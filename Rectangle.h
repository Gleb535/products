#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Line.h"

class Rectangle : public Line
{
protected:
    Dot dot3, dot4;
    double square;

public:
    Rectangle() : Line(), dot3(0, 0, 0), dot4(0, 0, 0), square(0) {}

    Rectangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4)
        : Line(x1, y1, z1, x2, y2, z2), dot3(x3, y3, z3), dot4(x4, y4, z4)
    {
        updSquared();
    }

    void updSquared()
    {
        // Координаты всех точек прямоугольника
        int Ax = getX(), Ay = getY(), Az = getZ();
        int Bx = getdX(), By = getdY(), Bz = getdZ();
        int Cx = dot3.getX(), Cy = dot3.getY(), Cz = dot3.getZ();
        int Dx = dot4.getX(), Dy = dot4.getY(), Dz = dot4.getZ();

        // Векторы AB и BC (стороны прямоугольника)
        int ABx = Bx - Ax, ABy = By - Ay;
        int BCx = Cx - Bx, BCy = Cy - By;

        // Проверка двух условий:
        // 1. Все точки в одной плоскости (Z одинаковы)
        bool isFlat = (Az == Bz) && (Bz == Cz) && (Cz == Dz);

        // 2. Стороны AB и BC перпендикулярны (скалярное произведение = 0)
        bool isPerpendicular = (ABx * BCx + ABy * BCy) == 0;

        if (isFlat && isPerpendicular)
        {
            double lengthAB = sqrt(ABx * ABx + ABy * ABy);
            double lengthBC = sqrt(BCx * BCx + BCy * BCy);
            square = lengthAB * lengthBC;
        }
        else
        {
            square = -1; // значит  не прямоугольник !!!
        }
    }

    int getSqrt() const
    {
        return square;
    }

    int getDot3X() const { return dot3.getX(); }
    int getDot3Y() const { return dot3.getY(); }
    int getDot3Z() const { return dot3.getZ(); }

    int getDot4X() const { return dot4.getX(); }
    int getDot4Y() const { return dot4.getY(); }
    int getDot4Z() const { return dot4.getZ(); }

    void setDot3X(int newX)
    {
        dot3.setX(newX);
        updSquared();
    }
    void setDot3Y(int newY)
    {
        dot3.setY(newY);
        updSquared();
    }
    void setDot3Z(int newZ)
    {
        dot3.setZ(newZ);
        updSquared();
    }

    void setDot4X(int newX)
    {
        dot4.setX(newX);
        updSquared();
    }
    void setDot4Y(int newY)
    {
        dot4.setY(newY);
        updSquared();
    }
    void setDot4Z(int newZ)
    {
        dot4.setZ(newZ);
        updSquared();
    }

    void print_product() const
    {
        std::cout << "X_4 coord: " << dot4.getX() << "\n"
                  << "Y_4 coord: " << dot4.getY() << "\n"
                  << "Z_4 coord: " << dot4.getZ() << "\n"

                  << "X_3 coord: " << dot3.getX() << "\n"
                  << "Y_3 coord: " << dot3.getY() << "\n"
                  << "Z_3 coord: " << dot3.getZ() << "\n"

                  << "sqrt: " << getSqrt() << std::endl;
    }

    void get_product(int &a1, int &b1, int &c1, int &a2, int &b2, int &c2, int &a3, int &b3, int &c3, int &a4, int &b4, int &c4, double &s)
    {
        a1 = x;
        b1 = y;
        c1 = z;

        a2 = getdX();
        b2 = getdY();
        c2 = getdZ();

        a3 = dot3.getX();
        b3 = dot3.getY();
        c3 = dot3.getZ();

        a4 = dot4.getX();
        b4 = dot4.getY();
        c4 = dot4.getZ();

        s = getSqrt();
    }
};

#endif