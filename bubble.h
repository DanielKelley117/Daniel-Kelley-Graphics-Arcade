//
// Created by Daniel Kelley on 11/12/2022.
//

#ifndef M1OEP_BUBBLE_H
#define M1OEP_BUBBLE_H
#include "circle.h"
class Bubble : public Circle {
private:
    double radius;
public:
    /* Constructors */
    Bubble();
    explicit Bubble(double radius);
    explicit Bubble(color fill);
    explicit Bubble(point2D center);
    Bubble(color fill, point2D center);
    Bubble(double red, double green, double blue, double alpha);
    Bubble(double x, double y);
    Bubble(double red, double green, double blue, double alpha, double x, double y);
    Bubble(color fill, double x, double y);
    Bubble(double red, double green, double blue, double alpha, point2D center);
    Bubble(color fill, double radius);
    Bubble(point2D center, double radius);
    Bubble(color fill, point2D center, double radius);
    Bubble(double red, double green, double blue, double alpha, double radius);
    Bubble(double x, double y, double radius);
    Bubble(double red, double green, double blue, double alpha, double x, double y, double radius);
    Bubble(color fill, double x, double y, double radius);
    Bubble(double red, double green, double blue, double alpha, point2D center, double radius);
    Bubble(double redFill, double greenFill, double blueFill, double alphaFill, double redBorder, double greenBorder, double blueBorder, double alphaBorder, double x, double y, double radius);

    /* Destructor */
    virtual ~Bubble() = default;

    /* Getters */
    double getRadius() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setter */
    void setRadius(double r);
    void changeRadius(double delta);

    /* Overlapping */
    bool isOverlapping(const Bubble &c) const;

    /* Collision */
    void collide(Bubble &c);

    /* Draw */
    void draw() const override;

};
#endif //M1OEP_BUBBLE_H
