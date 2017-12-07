#ifndef POSITIONPOINT_H
#define POSITIONPOINT_H

struct PositionPoint {
    PositionPoint(int n_x, int n_y)
    : x(n_x)
    , y(n_y) {}

    int x, y;
};

#endif // POSITIONPOINT_H
