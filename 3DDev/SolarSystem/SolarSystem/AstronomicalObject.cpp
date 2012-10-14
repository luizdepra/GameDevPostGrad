#include "AstronomicalObject.h"


AstronomicalObject::AstronomicalObject()
:   _xTranslation(0.0f),
    _zTranslation(0.0f),
    _radius(1.0f),
    _rotationVelocity(1.0f),
    _translationVelocity(1.0f),
    _r(1.0f),
    _g(1.0f),
    _b(1.0f),
    _rotationAngle(0.0f),
    _translationAngle(0.0f)
{
}


AstronomicalObject::AstronomicalObject(float xTranslation, float zTranslation, double radius, float rotationVelocity, float translationVelocity, float r, float g, float b)
:   _xTranslation(xTranslation),
    _zTranslation(zTranslation),
    _radius(radius),
    _rotationVelocity(translationVelocity),
    _translationVelocity(translationVelocity),
    _r(r),
    _g(g),
    _b(b),
    _rotationAngle(0.0f),
    _translationAngle(0.0f)
{
}

AstronomicalObject::~AstronomicalObject()
{
}

void AstronomicalObject::processLogics( float secs )
{
    _rotationAngle += _rotationVelocity * secs;
    _translationAngle += _translationVelocity * secs;
}

void AstronomicalObject::draw() const
{
    glRotatef(_translationAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(_xTranslation, 0.0f, _zTranslation);

    glPushMatrix();

    glRotatef(_rotationAngle, 0.0f, 1.0f, 0.0f);

    glColor3f(_r, _g, _b);
    drawSolidSphere(_radius, 20, 20, true);

    glPopMatrix();
}

void AstronomicalObject::drawSolidSphere( double radius, int stacks, int columns, bool fill/*=true*/ ) const
{
    GLUquadric* quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, fill ? GLU_FILL : GLU_LINE);
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, true);
    gluSphere(quadObj, radius, stacks, columns);
    gluDeleteQuadric(quadObj);
}
