#include <cstdio>
#include <cmath>
#include "leg_ik.h"

static int failures = 0;

void checkPose(const char* label, float x, float y, float z) {
    LegAngles a = solveIK(DEFAULT_LEG, x, y, z);

    float fx, fy, fz;
    forwardK(DEFAULT_LEG, a, fx, fy, fz);

    float err = sqrtf((fx - x) * (fx - x)
                    + (fy - y) * (fy - y)
                    + (fz - z) * (fz - z));
    LegAngles copy = a;
    bool inLimits = clampAngles(copy, DEFAULT_LIMITS);

     printf("%-22s target(%6.1f %6.1f %6.1f)  ->  "
           "coxa %7.2f  femur %7.2f  tibia %7.2f   knee %6.1f   err %.4f mm  %s%s\n",
           label, x, y, z,
           a.coxa, a.femur, a.tibia, 180.0f - a.tibia, err,
           a.reachable ? "" : "[UNREACHABLE] ",
           inLimits    ? "" : "[Limit HIT]");

    if (a.reachable && err > 0.01f) failures++;
}

void standingPose() {
    printf("\n=== NEUTRAL STANDING POSE ===\n\n");
    float lean   = 40.0f * DEG2RAD;
    float height = 2.0f * DEFAULT_LEG.femurLen * cosf(lean);
    checkPose("standing", 0.0f, DEFAULT_LEG.coxaLen, -height);
}

void reachLimits() {
    printf("\n=== WORKSPACE EDGES ===\n\n");
    checkPose("way too far",   0.0f, 30.0f, -300.0f);
    checkPose("fully folded",  0.0f, 30.0f,  -10.0f);
    checkPose("near-straight", 0.0f, 30.0f, -149.0f);
}

void swingArc() {
    printf("\n=== SWING PHASE SWEEP ===\n\n");
    printf("   t      x        z       coxa     femur    tibia     knee\n");
    printf("  ----  -------  -------  -------  -------  -------  -------\n");


    const float stride = 60.0f, lift = 30.0f;
    const float standZ = -114.9f, standY = 30.0f;
    float prevFemur = 0.0f;
    bool first = true;

    for (int i =0; i <= 10; i++) {
        float t = 1 / 10.0f;
        float x = -stride / 2.0f + stride * t;
        float z = standZ + lift * sinf(t * M_PI);

        LegAngles a = solveIK(DEFAULT_LEG, x, standY, z);

         printf("  %.2f  %7.2f  %7.2f  %7.2f  %7.2f  %7.2f  %7.2f",
               t, x, z, a.coxa, a.femur, a.tibia, 180.0f - a.tibia);

        if (!first && fabsf(a.femur - prevFemur) > 15.0f) {
            printf("   <-- DISCONTINUITY");
            failures++;
        }
         printf("\n");
        prevFemur = a.femur;
        first = false;
}
}

void attitudeDemo() {
    printf("\n=== BODY ROLL COMPENSATION ===\n\n");
    float roll = 10.0f * DEG2RAD;
    float y0 = 30.0f, z0 = -114.9f;

    float yR = y0 * cosf(-roll) - z0 * sinf(-roll);
    float zR = y0 * sinf(-roll) + z0 * cosf(-roll);

    checkPose("level",         0.0f, y0, z0);
    checkPose("rolled 10 deg", 0.0f, yR, zR);
}

int main() {
    printf("Flathead leg IK — coxa %.0f, femur %.0f, tibia %.0f mm\n",
           DEFAULT_LEG.coxaLen, DEFAULT_LEG.femurLen, DEFAULT_LEG.tibiaLen);

    standingPose();
    reachLimits();
    swingArc();
    attitudeDemo();

    printf("\n");
    if (failures == 0) printf("ALL CHECKS PASSED\n");
    else               printf("%d CHECK(S) FAILED.\n", failures);
    return failures ? 1 : 0;
}