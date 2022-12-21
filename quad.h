//
// Created by Daniel Kelley on 11/9/2022.
//

#ifndef M1OEP_QUAD_H
#define M1OEP_QUAD_H
#include "shape.h"

struct point2d {
    int x;
    int y;
};


class Quad {
protected:
    color fill;
    point2d center;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(color fill, point2d center, unsigned int width, unsigned int height);

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point2d getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};
#endif //M1OEP_QUAD_H
