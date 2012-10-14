#ifndef __ASTRONOMICAL_OBJECT_H__
#define __ASTRONOMICAL_OBJECT_H__

#include <Windows.h>
#include "SDL.h"
#include "GL/GL.h"
#include "GL/GLU.h"

class AstronomicalObject
{
public:
    AstronomicalObject();
    AstronomicalObject(float xTranslation, float zTranslation, double radius, float rotationVelocity, float translationVelocity, float r, float g, float b);
    ~AstronomicalObject();

    void processLogics(float secs);
    void draw() const;

private:
    float _zTranslation;
    float _xTranslation;
    double _radius;
    float _rotationVelocity;
    float _translationVelocity;

    float _r;
    float _g;
    float _b;

    float _rotationAngle;
    float _translationAngle;

    void drawSolidSphere(double radius, int stacks, int columns, bool fill=true) const;

};

#endif //__ASTRONOMICAL_OBJECT_H__
