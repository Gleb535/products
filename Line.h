#ifndef _LINE_H_
#define _LINE_H_

#include "Dot.h"

class Line : public Dot
{
private:
    Dot dot2;
    double length;

public:
    Line() : Dot(), dot2(0, 0, 0), length(0) {}

    Line(int x1, int y1, int z1, int x2, int y2, int z2) : Dot(x1, y1, z1), dot2(x2, y2, z2) { updLength(); }

    void updLength()
    {
        length = sqrt(pow(dot2.getX() - x, 2) + pow(dot2.getY() - 2, 2) + pow(dot2.getZ() - z, 2));
    }

    int getdX() const { return dot2.getX(); }
    int getdY() const { return dot2.getY(); }
    int getdZ() const { return dot2.getZ(); }

    double getLenght() const
    {
        return length;
    }

    void setdX(int newX)
    {
        dot2.setX(newX);
        updLength();
    }

    void setdY(int newY)
    {
        dot2.setY(newY);
        updLength();
    }

    void setdZ(int newZ)
    {
        dot2.setZ(newZ);
        updLength();
    }

    void print_product() const
    {
        std::cout << "X_1 coord: " << getX() << "\n"
                  << "Y_1 coord: " << getY() << "\n"
                  << "Z_1 coord: " << getZ() << "\n"

                  << "X_2 coord: " << dot2.getX() << "\n"
                  << "Y_2 coord: " << dot2.getY() << "\n"
                  << "Z_2 coord: " << dot2.getZ() << "\n"

                  << "Length: " << getLenght() << std::endl;
    }

    void get_product(int &a1, int &b1, int &c1, int &a2, int &b2, int &c2, double &l)
    {
        a1 = x;
        b1 = y;
        c1 = z;

        a2 = dot2.getX();
        b2 = dot2.getY();
        c2 = dot2.getZ();

        l = getLenght();
    }
};

#endif