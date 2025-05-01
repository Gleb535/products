#ifndef _DOT_H_
#define _DOT_H_

#include <iostream>

class Dot
{
protected:
    int x, y, z;

public:
    Dot() : x(0), y(0), z(0) {}

    Dot(int setx, int sety, int setz) : x(setx), y(sety), z(setz) {}

    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

    void setX(int setx) { x = setx; }
    void setY(int sety) { y = sety; }
    void setZ(int setz) { z = setz; }

    void print_product() const
    {
        std::cout << "X coord: " << x << "\n"
                  << "Y coord: " << y << "\n"
                  << "Z coord: " << z << std::endl;
    }

    void get_product(int &a, int &b, int &c)
    {
        a = x;
        b = y;
        c = z;
    }
};

#endif