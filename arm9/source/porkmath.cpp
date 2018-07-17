#include <nds9.h>

float sinF(float angle) {
    int32 s = sinLerp((short) (angle * DEGREES_IN_CIRCLE / 360));

    return f32tofloat(s);
}

float cosF(float angle) {
    int32 c = cosLerp((short) (angle * DEGREES_IN_CIRCLE / 360));

    return f32tofloat(c);
}
