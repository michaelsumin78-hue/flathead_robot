#pragma once
#include <math.h>

// flathead single leg inverse kinematics test file for approval

struct LegConfig {
    float coxaLen; 
    float femurLen;
    float tibiaLen;
};

struct LegAngles {
    float coxa;
    float femur;
    float tibia;
    bool reachable;

};

static const LegConfig DEFAULT_LEG = { 30.0f, 75.0f, 75.0f };

static const float RAD2DEG = 57.29577951308232f;
static const float DEG2RAD = 0.017453292519943295f;

static inline float safeAcos(float v) {
    if (v >  1.0f) v =  1.0f;
    if (v < -1.0f) v = -1.0f;
    return acosf(v);
}


inline LegAngles solveIK(const LegConfig& cfg, float x, float y, float z){
    LegAngles out;
    out.reachable = true;

    out.coxa = atan2f(x, y) * RAD2DEG;

    float horiz = sqrtf(x * x + y * y);
    float r     = horiz - cfg.coxaLen;

    float dist = sqrtf(r * r + z * z);

    float maxReach = cfg.femurLen + cfg.tibiaLen;
    float minReach = fabsf(cfg.femurLen - cfg.tibiaLen);

    if (dist > maxReach) { dist = maxReach * 0.999f; out.reachable = false; }
    if (dist < minReach) { dist = minReach + 0.001f; out.reachable = false; }


    float phi   = atan2f(z, r);
    float alpha = safeAcos((cfg.femurLen * cfg.femurLen
                          + dist * dist
                          - cfg.tibiaLen * cfg.tibiaLen)
                         / (2.0f * cfg.femurLen * dist));

    out.femur = (phi + alpha) * RAD2DEG;

    float beta = safeAcos((cfg.femurLen * cfg.femurLen
                         + cfg.tibiaLen * cfg.tibiaLen
                         - dist * dist)
                        / (2.0f * cfg.femurLen * cfg.tibiaLen));

    out.tibia = 180.0f - beta * RAD2DEG;
    return out;



}

inline void forwardK(const LegConfig& cfg, const LegAngles& a,
                     float& x, float& y, float& z) {
    float femRad = a.femur * DEG2RAD;
    float tibAbs = (a.femur - a.tibia) * DEG2RAD;


  float kneeR = cfg.coxaLen + cfg.femurLen * cosf(femRad);
    float kneeZ =               cfg.femurLen * sinf(femRad);

    float footR = kneeR + cfg.tibiaLen * cosf(tibAbs);
    float footZ = kneeZ + cfg.tibiaLen * sinf(tibAbs);

    float coxaRad = a.coxa * DEG2RAD;
    x = footR * sinf(coxaRad);
    y = footR * cosf(coxaRad);
    z = footZ;
}


struct JointLimits {
    float coxaMin, coxaMax;
    float femurMin, femurMax;
    float tibiaMin, tibiaMax;
};

static const JointLimits DEFAULT_LIMITS = {
    -45.0f, 45.0f,
    -90.0f, 20.0f,
    30.0f, 140.0f

};

inline bool clampAngles(LegAngles& a, const JointLimits& lim) {
    bool ok = true;
    if (a.coxa  < lim.coxaMin) { a.coxa  = lim.coxaMin; ok = false;}
    if (a.coxa  > lim.coxaMax) { a.coxa  = lim.coxaMax; ok = false;}
    if (a.femur  < lim.femurMin) { a.femur  = lim.femurMin; ok = false;}
    if (a.femur  > lim.femurMax) { a.femur  = lim.femurMax; ok = false;}
    if (a.tibia  < lim.tibiaMin) { a.tibia  = lim.tibiaMin; ok = false;}
    if (a.tibia  > lim.tibiaMax) { a.tibia  = lim.tibiaMax; ok = false;}
    return ok;
}

