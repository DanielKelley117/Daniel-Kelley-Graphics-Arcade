//
// Created by Daniel Kelley on 11/13/2022.
//

#ifndef M1OEP_CUBE_H
#define M1OEP_CUBE_H

#include <vector>
#include "quad.h"

struct point3d {
    double x;
    double y;
    double z;
};


class Cube {
private:
    point3d center;
    unsigned int edge_length;
    std::vector<point3d> corners;

    // Private helper methods
    void reset_corners();
    void draw_point(const point3d &p) const;

public:

    // Constructors
    Cube();
    Cube(point3d center, unsigned int edge_length);

    // Draw the cube
    void draw() const;

    // Rotate the cube
    void rotate(double theta_x, double theta_y, double theta_z);

    // Move the cube
    void move(double delta_x, double delta_y, double delta_z);
};

#endif //M1OEP_CUBE_H
