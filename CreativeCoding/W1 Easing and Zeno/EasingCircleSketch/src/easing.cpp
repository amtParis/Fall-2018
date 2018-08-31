//
//  easing.cpp
//  EasingFunctions
//
//  Created by csugrue on 8/30/18.
//

#include "easing.h"

float linear(float t) {
    return t;
}

float inQuad(float t) {
    return t * t;
}

float outQuad(float t) {
    return t * (2 - t);
}

float inOutQuad(float t) {
    return t < .5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
}

float inCubic(float t) {
    return t * t * t;
}

float outCubic(float t) {
    t--;
    return t * t * t + 1;
}

float inOutCubic(float t) {
    return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
}

float inQuart(float t) {
    return t * t * t * t;
}

float outQuart(float t) {
    t--;
    return 1 - t * t * t * t;
}

float inOutQuart(float t) {
    float nt = t-1;
    return t < .5 ? 8 * t * t * t * t : 1 - 8 * nt * nt * nt * nt;
}

float inQuint(float t) {
    return t * t * t * t * t;
}

float outQuint(float t) {
    t--;
    return 1 + t * t * t * t * t;
}

float inOutQuint(float t) {
    float nt = t-1;
    return t < .5 ? 16 * t * t * t * t * t : 1 + 16 * nt * nt * nt * nt * nt;
}

float inSine(float t) {
    return sin( (PI * 0.5) * t );
    
    //        return -1 * cos(t / 1 * (PI * 0.5)) + 1;
}

float outSine(float t) {
    return 1 + sin( (PI * 0.5) * (--t) );
    
    // return sin(t / 1 * (PI * 0.5));
}

float inOutSine(float t) {
    return 0.5 * (1 + sin( PI * (t - 0.5) ) );
}

float inExpo(float t) {
    return (pow( 2, 8 * t ) - 1) / 255;
}

float outExpo(float t) {
    return 1 - pow( 2, -8 * t );
}

float inOutExpo(float t) {
    if( t < 0.5 ) {
        return (pow( 2, 16 * t ) - 1) / 510;
    } else {
        return 1 - 0.5 * pow( 2, -16 * (t - 0.5) );
    }
}

float inCirc(float t) {
    return 1 - sqrt( 1 - t );
}

float outCirc(float t) {
    return sqrt( t );
    
}

float inOutCirc(float t) {
    if( t < 0.5 ) {
        return (1 - sqrt( 1 - 2 * t )) * 0.5;
    } else {
        return (1 + sqrt( 2 * t - 1 )) * 0.5;
    }
}

double inElastic( double t ) {
    double t2 = t * t;
    return t2 * t2 * sin( t * PI * 4.5 );
}

float outElastic(float t) {
    double t2 = (t - 1) * (t - 1);
    return 1 - t2 * t2 * cos( t * PI * 4.5 );
    
}

float inOutElastic(float t) {
    double t2;
    if( t < 0.45 ) {
        t2 = t * t;
        return 8 * t2 * t2 * sin( t * PI * 9 );
    } else if( t < 0.55 ) {
        return 0.5 + 0.75 * sin( t * PI * 4 );
    } else {
        t2 = (t - 1) * (t - 1);
        return 1 - 8 * t2 * t2 * sin( t * PI * 9 );
    }
}

float inBack(float t, float s) {
    if (s == -1) s = 1.70158;
    return 1 * t * t * ((s + 1) * t - s);
}

float outBack(float t, float s) {
    if (s == -1) s = 1.70158;
    float nt = t / 1 -1;
    return 1 * ((nt) * nt * ((s + 1) * nt + s) + 1);
}

float inOutBack(float t, float s) {
    if( t < 0.5 ) {
        return t * t * (7 * t - 2.5) * 2;
    } else {
        t--;
        return 1 + (t) * t * 2 * (7 * t + 2.5);
    }
}


float outBounce(float t) {
    if ((t /= 1) < (1 / 2.75)) {
        return (7.5625 * t * t);
    } else if (t < (2 / 2.75)) {
        float nt = t - (1.5 / 2.75);
        return (7.5625 * nt * nt + .75);
    } else if (t < (2.5 / 2.75)) {
        float nt = t - (2.25 / 2.75);
        return (7.5625 * nt * nt + .9375);
    } else {
        float nt = t - (2.625 / 2.75);
        return (7.5625 * nt * nt + .984375);
    }
}

float inBounce(float t) {
    return 1 - outBounce(1 - t);
}

float inOutBounce(float t) {
    if (t < .5) return inBounce(t * 2) * 0.5;
    return outBounce(t * 2 - 1) * 0.5 + 0.5;
    }
