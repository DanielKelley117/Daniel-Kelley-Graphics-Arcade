//
// Created by Daniel Kelley on 11/12/2022.
//
#include "bubble.h"
#include "graphics.h"

Bubble::Bubble() : Circle(), radius(0) {
}

Bubble::Bubble(double radius) : Circle() {
    setRadius(radius);
}

Bubble::Bubble(color fill) : Circle(fill), radius(0) {
}

Bubble::Bubble(point2D center) : Circle(center), radius(0) {
}

Bubble::Bubble(color fill, point2D center) : Circle(fill, center), radius(0) {
}

Bubble::Bubble(double red, double green, double blue, double alpha) : Circle(red, green, blue, alpha), radius(0) {
}

Bubble::Bubble(double x, double y) : Circle(x, y), radius(0) {
}

Bubble::Bubble(double red, double green, double blue, double alpha, double x, double y) : Circle(red, green, blue, alpha, x, y), radius(0) {
}

Bubble::Bubble(color fill, double x, double y) : Circle(fill, x, y), radius(0) {
}

Bubble::Bubble(double red, double green, double blue, double alpha, point2D center) : Circle(red, green, blue, alpha, center), radius(0) {
}

Bubble::Bubble(color fill, double radius) : Circle(fill) {
    setRadius(radius);
}

Bubble::Bubble(point2D center, double radius) : Circle(center) {
    setRadius(radius);
}

Bubble::Bubble(color fill, point2D center, double radius) : Circle(fill, center) {
    setRadius(radius);
}

Bubble::Bubble(double red, double green, double blue, double alpha, double radius) : Circle(red, green, blue, alpha) {
    setRadius(radius);
}

Bubble::Bubble(double x, double y, double radius) : Circle(x, y) {
    setRadius(radius);
}

Bubble::Bubble(double red, double green, double blue, double alpha, double x, double y, double radius) : Circle(red, green, blue, alpha, x, y) {
    setRadius(radius);
}

Bubble::Bubble(color fill, double x, double y, double radius) : Circle(fill, x, y) {
    setRadius(radius);
}

Bubble::Bubble(double red, double green, double blue, double alpha, point2D center, double radius) : Circle(red, green, blue, alpha, center) {
    setRadius(radius);
}

Bubble::Bubble(double redFill, double greenFill, double blueFill, double alphaFill, double redBorder, double greenBorder, double blueBorder, double alphaBorder, double x, double y, double radius) : Circle(redFill, greenFill, blueFill, alphaFill, redBorder, greenBorder, blueBorder, alphaBorder, x, y, radius) {
    setRadius(radius);
}


double Bubble::getRadius() const {
    return radius;
}

double Bubble::getLeftX() const {
    return center.x - radius;
}

double Bubble::getRightX() const  {
    return center.x + radius;
}

double Bubble::getTopY() const {
    return center.y - radius;
}

double Bubble::getBottomY() const {
    return center.y + radius;
}

void Bubble::setRadius(double r) {
    if (r < 0) {
        r = 0;
    }
    radius = r;
}

void Bubble::changeRadius(double delta) {
    setRadius(radius + delta);
}

bool Bubble::isOverlapping(const Bubble &c) const {
    // return true if the distance between the center points is <= the sum of the radii
    return (sqrt((c.center.x - center.x)*(c.center.x - center.x) + (c.center.y - center.y)*(c.center.y - center.y)) <= c.radius + radius);
}

void Bubble::collide(Bubble &c) {
    // 2-dimensional elastic collision
    double radiusSum = radius + c.radius;
    double xVel = xVelocity, yVel = yVelocity, xVel2 = c.xVelocity, yVel2 = c.yVelocity;
    xVelocity = (xVel - ((2.0*c.radius)/radiusSum) * ((xVel - xVel2)*(c.center.x - center.x) + (yVel - yVel2)*(c.center.y - center.y)) / double((c.center.x - center.x)*(c.center.x - center.x) + (c.center.y - center.y)*(c.center.y - center.y)) * (c.center.x - center.x));
    yVelocity = (yVel - ((2.0*c.radius)/radiusSum) * ((xVel - xVel2)*(c.center.x - center.x) + (yVel - yVel2)*(c.center.y - center.y)) / double((c.center.x - center.x)*(c.center.x - center.x) + (c.center.y - center.y)*(c.center.y - center.y)) * (c.center.y - center.y));
    c.xVelocity = (xVel2 - ((2.0*radius)/radiusSum) * ((xVel2 - xVel)*(center.x - c.center.x) + (yVel2 - yVel)*(center.y - c.center.y)) / double((c.center.x - center.x)*(c.center.x - center.x) + (c.center.y - center.y)*(c.center.y - center.y)) * (center.x - c.center.x));
    c.yVelocity = (yVel2 - ((2.0*radius)/radiusSum) * ((xVel2 - xVel)*(center.x - c.center.x) + (yVel2 - yVel)*(center.y - c.center.y)) / double((c.center.x - center.x)*(c.center.x - center.x) + (c.center.y - center.y)*(c.center.y - center.y)) * (center.y - c.center.y));

    while (isOverlapping(c)) {
        move(xVelocity/100.0, yVelocity/100.0);
        c.move(c.xVelocity/100.0, c.yVelocity/100.0);
    }
}

void Bubble::draw() const {
    // Set drawing color to fill color
    glColor3f(fill.red, fill.green, fill.blue);
    // Draw circle as Triangle Fan
    glBegin(GL_TRIANGLE_FAN);
    // Draw center point
    glVertex2i(center.x, center.y);
    // Set drawing color to border color
    glColor3f(border.red, border.green, border.blue);
    // Draw points on edge of circle
    for (double i = 0; i < 2.0*PI+0.05; i += (2.0*PI)/360.0) {
        glVertex2i(center.x + (radius * cos(i)),
                   center.y + (radius * sin(i)));
    }
    // End Triangle Fan
    glEnd();
}

