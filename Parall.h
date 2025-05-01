#ifndef _PARALL_H_
#define _PARALL_H_

#include "Rectangle.h"

class Parall : public Rectangle
{
private:
    Dot dot5, dot6, dot7, dot8;
    double volume;

public:
    Parall() : Rectangle(), dot5(0, 0, 0), dot6(0, 0, 0), dot7(0, 0, 0), dot8(0, 0, 0), volume(0) {}
    Parall(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int x5, int y5, int z5, int x6, int y6, int z6, int x7, int y7, int z7, int x8, int y8, int z8)
        : Rectangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4), dot5(x5, y5, z5), dot6(x6, y6, z6), dot7(x7, y7, z7), dot8(x8, y8, z8)
    {
        updVolume();
    }

    double getVolume() const
    {
        return volume;
    }

    int getDot5X() const { return dot5.getX(); }
    int getDot5Y() const { return dot5.getY(); }
    int getDot5Z() const { return dot5.getZ(); }

    int getDot6X() const { return dot6.getX(); }
    int getDot6Y() const { return dot6.getY(); }
    int getDot6Z() const { return dot6.getZ(); }

    int getDot7X() const { return dot7.getX(); }
    int getDot7Y() const { return dot7.getY(); }
    int getDot7Z() const { return dot7.getZ(); }

    int getDot8X() const { return dot8.getX(); }
    int getDot8Y() const { return dot8.getY(); }
    int getDot8Z() const { return dot8.getZ(); }

    void setDot5X(int newX)
    {
        dot5.setX(newX);
        updVolume();
    }
    void setDot5Y(int newY)
    {
        dot5.setY(newY);
        updVolume();
    }
    void setDot5Z(int newZ)
    {
        dot5.setZ(newZ);
        updVolume();
    }

    void setDot6X(int newX)
    {
        dot6.setX(newX);
        updVolume();
    }
    void setDot6Y(int newY)
    {
        dot6.setY(newY);
        updVolume();
    }
    void setDot6Z(int newZ)
    {
        dot6.setZ(newZ);
        updVolume();
    }

    void setDot7X(int newX)
    {
        dot7.setX(newX);
        updVolume();
    }
    void setDot7Y(int newY)
    {
        dot7.setY(newY);
        updVolume();
    }
    void setDot7Z(int newZ)
    {
        dot7.setZ(newZ);
        updVolume();
    }

    void setDot8X(int newX)
    {
        dot8.setX(newX);
        updVolume();
    }
    void setDot8Y(int newY)
    {
        dot8.setY(newY);
        updVolume();
    }
    void setDot8Z(int newZ)
    {
        dot8.setZ(newZ);
        updVolume();
    }

    void updVolume()
    {
        // Получение координат всех 8 вершин. ABCD - вершины нижнего основания, EFGH - верхнего основания
        int Ax = getX(), Ay = getY(), Az = getZ();
        int Bx = getdX(), By = getdY(), Bz = getdZ();
        int Cx = getDot3X(), Cy = getDot3Y(), Cz = getDot3Z();
        int Dx = getDot4X(), Dy = getDot4Y(), Dz = getDot4Z();
        int Ex = dot5.getX(), Ey = dot5.getY(), Ez = dot5.getZ();
        int Fx = dot6.getX(), Fy = dot6.getY(), Fz = dot6.getZ();
        int Gx = dot7.getX(), Gy = dot7.getY(), Gz = dot7.getZ();
        int Hx = dot8.getX(), Hy = dot8.getY(), Hz = dot8.getZ();

        // Точке A соответствует точка E, точке B - F, точке C - G, точке D - H
        Rectangle base1(Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz, Dx, Dy, Dz);
        Rectangle base2(Ex, Ey, Ez, Fx, Fy, Fz, Gx, Gy, Gz, Hx, Hy, Hz);

        if (base1.getSqrt() <= 0 || base2.getSqrt() <= 0)
        {
            volume = -1;
            return;
        }

        int AEx = Ex - Ax, AEy = Ey - Ay, AEz = Ez - Az; // AE - вектор, показывающий как смещается точка A в точку E

        // Проверяется, что верхнее основание (EFGH) является точной параллельной копией нижнего основания (ABCD), смещённой на вектор AE = (AEx, AEy, AEz)
        if ((Fx - Bx) != AEx || (Fy - By) != AEy || (Fz - Bz) != AEz ||
            (Gx - Cx) != AEx || (Gy - Cy) != AEy || (Gz - Cz) != AEz ||
            (Hx - Dx) != AEx || (Hy - Dy) != AEy || (Hz - Dz) != AEz)
        {
            volume = -1; // крч не параллелепипед
            return;
        }

        double height = sqrt(AEx * AEx + AEy * AEy + AEz * AEz);
        volume = base1.getSqrt() * height;
    }

    void print_product() const
    {
        std::cout << "Dots of the parallelepiped:" << std::endl;
        std::cout << "Dot1: " << getX() << ", " << getY() << ", " << getZ() << std::endl;
        std::cout << "Dot2: " << getdX() << ", " << getdY() << ", " << getdZ() << std::endl;
        std::cout << "Dot3: " << getDot3X() << ", " << getDot3Y() << ", " << getDot3Z() << std::endl;
        std::cout << "Dot4: " << getDot4X() << ", " << getDot4Y() << ", " << getDot4Z() << std::endl;
        std::cout << "Dot5: " << dot5.getX() << ", " << dot5.getY() << ", " << dot5.getZ() << std::endl;
        std::cout << "Dot6: " << dot6.getX() << ", " << dot6.getY() << ", " << dot6.getZ() << std::endl;
        std::cout << "Dot7: " << dot7.getX() << ", " << dot7.getY() << ", " << dot7.getZ() << std::endl;
        std::cout << "Dot8: " << dot8.getX() << ", " << dot8.getY() << ", " << dot8.getZ() << std::endl;
        std::cout << "Volume: " << volume << std::endl;
    }
};

#endif