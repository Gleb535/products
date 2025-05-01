#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

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

                  << "X_2 coord: " << getdX() << "\n"
                  << "Y_2 coord: " << getdY() << "\n"
                  << "Z_2 coord: " << getdZ() << "\n"

                  << "X_1 coord: " << x << "\n"
                  << "Y_1 coord: " << y << "\n"
                  << "Z_1 coord: " << z << "\n"

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

class ProductException : public std::exception
{
private:
    std::string msg;

public:
    ProductException(const std::string error) noexcept : msg(error) {}

    const char *what() const noexcept override { return msg.data(); } // override контролирует синтаксис наследуемого дочерним классом виртуального метода

    virtual ~ProductException() {}
};

class ProductIncorrectIdException : public ProductException
{
public:
    ProductIncorrectIdException(const std::string error) noexcept : ProductException(error) {}

    ~ProductIncorrectIdException() {}
};

enum plugs
{
    SLAY,
    FSTAGE,
    OLEG,
    BOB
};

// функция для преобразования значения plug-ов в строку
std::string plug_to_string(plugs plug)
{
    switch (plug)
    {
    case SLAY:
        return "SLAY";
    case FSTAGE:
        return "FST AGE";
    case OLEG:
        return "OLEG";
    case BOB:
        return "BOB";
    default:
        return "nah";
    }
}

// класс товар
class Product
{
    int id;           // id
    std::string name; // название товара
    int price;        // цена
    plugs plug;       // поставщик

public:
    // конструктор без параметров (по умолчанию)
    Product() : id(0), name("noname"), price(0), plug(SLAY)
    {
    }

    // параметризованный конструктор
    Product(int a, std::string n, int p, plugs g) : name(n), price(p), plug(g)
    {
        if (a < 0)
            throw ProductIncorrectIdException("Constructor: Id can't be niggative");

        id = a;

        printf("Product with data: %d, %s, %d, %s was created!!!11\n", a, n.c_str(), p, plug_to_string(g).c_str());
    }

    // конструктор копирования
    Product(const Product &other) : id(other.id), name(other.name), price(other.price), plug(other.plug) {}

    // метод для установки значений товара
    void set_product(int a, std::string n, int p, plugs g)
    {
        id = a;
        name = n;
        price = p;
        plug = g;
    }

    void set_id(int a)
    {
        id = a;
    }

    void set_name(std::string n)
    {
        name = n;
    }

    void set_price(int p)
    {
        price = p;
    }

    void set_plug(plugs g)
    {
        plug = g;
    }

    // метод для получения значений товара
    void get_product(int &a, std::string &n, int &p, plugs &g)
    {
        a = id;
        n = name;
        p = price;
        g = plug;
    }

    void get_prod_id(int &a)
    {
        a = id;
    }

    void get_prod_name(std::string &n)
    {
        n = name;
    }

    void get_prod_price(int &p)
    {
        p = price;
    }

    void get_prod_plug(plugs &g)
    {
        g = plug;
    }

    int get_id() const
    {
        return id;
    }

    int get_price() const
    {
        return price;
    }

    int get_plug() const
    {
        return plug;
    }

    // метод вывода информации о товаре
    void print_product() const
    {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << price << ", Plug: " << plug_to_string(plug) << std::endl;
    }

    // метод вывода краткой информации о товаре
    void short_print_product() const
    {
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }
};

// класс узла для двусвязного списка
template <typename T>
class Node
{
public:
    T tovar;    // товар в узле
    Node *prev; // указатель на предыдущий узел
    Node *next; // указатель на следующий узел

    // конструктор
    Node(T new_tovar) : tovar(new_tovar), prev(NULL), next(NULL) {}
};

// двусвяз список для продуктов
template <typename F>
class linked_list
{
private:
    Node<F> *head; // указатель на первый узел списка
    Node<F> *tail; // указатель на последний узел списка

    // сортировка по id

    Node<F> *partition_id(Node<F> *low, Node<F> *high)
    {
        int pivot = high->tovar.get_id(); // опорный элемент для разбиения списка
        Node<F> *i = low->prev;           // указатель на элемент, который будет разделять список на две части

        for (Node<F> *j = low; j != high; j = j->next)
        { // перебор элементов списка от low до high
            if (j->tovar.get_id() <= pivot)
            {                                       // если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // перемещаем указатель i на следующую позицию
                std::swap(i->tovar, j->tovar);      // меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // после завершения цикла перемещаем i на следующую позицию
        std::swap(i->tovar, high->tovar);   // меняем местами элементы i и high
        return i;                           // возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort_by_id(Node<F> *low, Node<F> *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                          // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            Node<F> *pi = partition_id(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_id(low, pi->prev);        // рекурсивно сортируем левую часть списка
            quickSort_by_id(pi->next, high);       // рекурсивно сортируем правую часть списка
        }
    }

    // сортировка по цене

    Node<F> *partition_price(Node<F> *low, Node<F> *high)
    {
        int pivot = high->tovar.get_price(); // опорный элемент для разбиения списка
        Node<F> *i = low->prev;              // указатель на элемент, который будет разделять список на две части

        for (Node<F> *j = low; j != high; j = j->next)
        { // перебор элементов списка от low до high
            if (j->tovar.get_price() <= pivot)
            {                                       // если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // перемещаем указатель i на следующую позицию
                std::swap(i->tovar, j->tovar);      // меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // после завершения цикла перемещаем i на следующую позицию
        std::swap(i->tovar, high->tovar);   // меняем местами элементы i и high
        return i;                           // возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort_by_price(Node<F> *low, Node<F> *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                             // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            Node<F> *pi = partition_price(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_price(low, pi->prev);        // рекурсивно сортируем левую часть списка
            quickSort_by_price(pi->next, high);       // рекурсивно сортируем правую часть списка
        }
    }

    // сортировка по поставщику

    Node<F> *partition_plug(Node<F> *low, Node<F> *high)
    {
        int pivot = high->tovar.get_plug(); // опорный элемент для разбиения списка
        Node<F> *i = low->prev;             // указатель на элемент, который будет разделять список на две части

        for (Node<F> *j = low; j != high; j = j->next)
        { // перебор элементов списка от low до high
            if (j->tovar.get_plug() <= pivot)
            {                                       // если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // перемещаем указатель i на следующую позицию
                std::swap(i->tovar, j->tovar);      // меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // после завершения цикла перемещаем i на следующую позицию
        std::swap(i->tovar, high->tovar);   // меняем местами элементы i и high
        return i;                           // возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort_by_plug(Node<F> *low, Node<F> *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                            // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            Node<F> *pi = partition_plug(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_plug(low, pi->prev);        // рекурсивно сортируем левую часть списка
            quickSort_by_plug(pi->next, high);       // рекурсивно сортируем правую часть списка
        }
    }

public:
    // конструктор по умолчанию
    linked_list() : head(NULL), tail(NULL) {}

    // конструктор копирования
    linked_list(const linked_list &other) : head(nullptr), tail(nullptr)
    {
        Node<F> *current = other.head; // начинаем с головы другого списка
        while (current)                // пока не достигнем конца списка
        {
            add_product(current->tovar); // добавляем товар из текущего узла в новый список
            current = current->next;     // переход к следующему
        }
    }
    // конструктор перемещения
    linked_list(linked_list &&other) : head(other.head), tail(other.tail)
    {
        other.head = nullptr; // очищаем указатель на голову в исходном объекте
        other.tail = nullptr; // очищаем указатель на хвост в исходном объекте
    }

    // перегруженный оператор сложения для добавления товара
    linked_list &operator+(const Product &product)
    {
        add_product(product); // добавляем товар в список
        return *this;         // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // перегруженный оператор вычетания для удаления товара по id

    linked_list &operator-(int id)
    {
        remove_product(id); // удаляем товар с указанным id из списка
        return *this;       // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // метод добавления товара в список
    void add_product(const Node<F> &new_product)
    {
        Node<F> *new_node = new Node<F>(new_product); // создаем новый узел, используя конструктор node
        if (!head)                                    // проверка пуст ли список (head == nullptr)
        {
            head = tail = new_node; // если список пустой, новый узел становится и головой, и хвостом (начальная точка списка)
        }
        else
        {
            tail->next = new_node; // у текущего хвоста устанавливаем указатель на новый узел
            new_node->prev = tail; // у нового узла устанавливаем указатель на предыдущий узел (хвост)

            tail = new_node; // обновляем хвост списка, делая его текущим новым узлом
        }
    }

    // функция для вставки нового узла в заданную позицию
    Node<F> *insertAtPos(Node<F> *head, int pos, Node<F> new_data)
    {

        Node<F> *new_node = new Node<F>(new_data); // создаем новый узел

        if (pos == 1) // вставка в начало
        {
            new_node->next = head;

            // если список не пуст, устанавливаем prev головы на новый узел
            if (head != NULL)
                head->prev = new_node;

            // устанавливаем новый узел как голову связанного списка
            head = new_node;
            return head;
        }

        Node<F> *curr = head;
        // перемещаемся по списку, чтоб найти узел перед позицией вставки
        for (int i = 1; i < pos - 1 && curr != NULL; ++i)
        {
            curr = curr->next;
        }

        // если позиция вне границ
        if (curr == NULL)
        {
            delete new_node;
            return head;
        }

        new_node->prev = curr; // устанавливаем prev нового узла на текущий

        new_node->next = curr->next; // устанавливаем next нового узла на следующий от текущего

        curr->next = new_node; // обновляем next текущего узла на новый узел

        // если новый узел не последний, обновляем prev следующего узла на новый узел
        if (new_node->next != NULL)
            new_node->next->prev = new_node;

        return head; // возвращаем голову двусвяз списка
    }
    // метод удаления товара из списка по id
    void remove_product(int id)
    {
        Node<F> *current = head; // начинаем с головы списка
        while (current)          // пока не достигнем конца списка
        {
            if (current->tovar.get_id() == id) // если найден товар с нужным id
            {
                if (current->prev) // если есть предыдущий узел, обновляем его указатель на следующий узел
                    current->prev->next = current->next;

                if (current->next) // если есть следующий узел, обновляем его указатель на предыдущий узел
                    current->next->prev = current->prev;

                if (current == head) // если удаляемый узел был головой списка, обновляем голову
                    head = current->next;

                if (current == tail) // если удаляемый узел был хвостом списка, обновляем хвост
                    tail = current->prev;

                delete current; // удаляем текущий узел
                break;          // выходим из цикла (товар найден и удален)
            }
            current = current->next; // переходим к следующему узлу
        }
    }

    // сохранение списка товаров в файл
    void save_to_file(const std::string &filename)
    {
        std::ofstream file(filename); // открываем файл для записи
        Node<F> *current = head;      // начинаем с головы списка
        while (current)               // пока не достигнем конца списка
        {
            int id, price;
            std::string name;
            plugs plug;
            current->tovar.get_product(id, name, price, plug);                     // получаем данные о товаре из текущего узла
            file << id << " " << name << " " << price << " " << plug << std::endl; // записываем данные в файл
            current = current->next;                                               // переходим к следующему узлу
        }
        file.close(); // закрываем файл после записи
    }

    // метод загрузки списка товаров из файла
    void load_from_file(const std::string &filename)
    {
        std::ifstream file(filename); // открываем файл для чтения
        while (!file.eof())           // продолжаем до конца файла
        {
            int id, price;
            std::string name;
            int plug;
            file >> id >> name >> price >> plug; // читаем данные из файла
            if (file)                            // если данные были успешно прочитаны
            {
                Product new_product(id, name, price, static_cast<plugs>(plug)); // создаем новый товар
                add_product(new_product);                                       // добавляем товар в список
            }
        }
        file.close(); // закрываем файл после чтения
    }

    // вывод списка товаров
    void print_list() const
    {
        Node<F> *current = head; // начинаем с головы списка
        while (current)          // пока не достигнем конца списка
        {
            current->tovar.print_product(); // вывод инфы товара
            current = current->next;        // переходим к следующему
        }
    }
};

// специализация лист для точек

template <>
class linked_list<Dot>
{
private:
    Node<Dot> *head; // указатель на первый узел списка
    Node<Dot> *tail; // указатель на последний узел списка

public:
    // конструктор по умолчанию
    linked_list<Dot>() : head(NULL), tail(NULL) {}

    // конструктор копирования
    linked_list<Dot>(const linked_list<Dot> &other) : head(nullptr), tail(nullptr)
    {
        Node<Dot> *current = other.head; // начинаем с головы другого списка
        while (current)                  // пока не достигнем конца списка
        {
            add_product(current->tovar); // добавляем товар из текущего узла в новый список
            current = current->next;     // переход к следующему
        }
    }
    // конструктор перемещения
    linked_list<Dot>(linked_list<Dot> &&other) : head(other.head), tail(other.tail)
    {
        other.head = nullptr; // очищаем указатель на голову в исходном объекте
        other.tail = nullptr; // очищаем указатель на хвост в исходном объекте
    }

    // перегруженный оператор сложения для добавления товара
    linked_list<Dot> &operator+(const Node<Dot> &product)
    {
        add_product(product); // добавляем товар в список
        return *this;         // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // метод добавления товара в список
    void add_product(const Node<Dot> &new_product)
    {
        Node<Dot> *new_node = new Node<Dot>(new_product); // создаем новый узел, используя конструктор node
        if (!head)                                        // проверка пуст ли список (head == nullptr)
        {
            head = tail = new_node; // если список пустой, новый узел становится и головой, и хвостом (начальная точка списка)
        }
        else
        {
            tail->next = new_node; // у текущего хвоста устанавливаем указатель на новый узел
            new_node->prev = tail; // у нового узла устанавливаем указатель на предыдущий узел (хвост)

            tail = new_node; // обновляем хвост списка, делая его текущим новым узлом
        }
    }

    // функция для вставки нового узла в заданную позицию
    Node<Dot> *insertAtPos(Node<Dot> *head, int pos, Node<Dot> new_data)
    {

        Node<Dot> *new_node = new Node<Dot>(new_data); // создаем новый узел

        if (pos == 1) // вставка в начало
        {
            new_node->next = head;

            // если список не пуст, устанавливаем prev головы на новый узел
            if (head != NULL)
                head->prev = new_node;

            // устанавливаем новый узел как голову связанного списка
            head = new_node;
            return head;
        }

        Node<Dot> *curr = head;
        // перемещаемся по списку, чтоб найти узел перед позицией вставки
        for (int i = 1; i < pos - 1 && curr != NULL; ++i)
        {
            curr = curr->next;
        }

        // если позиция вне границ
        if (curr == NULL)
        {
            delete new_node;
            return head;
        }

        new_node->prev = curr; // устанавливаем prev нового узла на текущий

        new_node->next = curr->next; // устанавливаем next нового узла на следующий от текущего

        curr->next = new_node; // обновляем next текущего узла на новый узел

        // если новый узел не последний, обновляем prev следующего узла на новый узел
        if (new_node->next != NULL)
            new_node->next->prev = new_node;

        return head; // возвращаем голову двусвяз списка
    }

    // сохранение списка товаров в файл
    void save_to_file(const std::string &filename)
    {
        std::ofstream file(filename); // открываем файл для записи
        Node<Dot> *current = head;    // начинаем с головы списка
        while (current)               // пока не достигнем конца списка
        {
            int x, y, z;
            current->tovar.get_product(x, y, z);            // получаем данные о товаре из текущего узла
            file << x << " " << y << " " << z << std::endl; // записываем данные в файл
            current = current->next;                        // переходим к следующему узлу
        }
        file.close(); // закрываем файл после записи
    }

    // метод загрузки списка товаров из файла
    void load_from_file(const std::string &filename)
    {
        std::ifstream file(filename); // открываем файл для чтения
        while (!file.eof())           // продолжаем до конца файла
        {
            int x, y, z;
            file >> x >> y >> z; // читаем данные из файла
            if (file)            // если данные были успешно прочитаны
            {
                Dot new_product(x, y, z); // создаем новый товар
                add_product(new_product); // добавляем товар в список
            }
        }
        file.close(); // закрываем файл после чтения
    }

    // вывод списка товаров
    void print_list() const
    {
        Node<Dot> *current = head; // начинаем с головы списка
        while (current)            // пока не достигнем конца списка
        {
            current->tovar.print_product(); // вывод инфы товара
            current = current->next;        // переходим к следующему
        }
    }
};

// специализация лист для ЛИНИЙ

template <>
class linked_list<Line>
{
private:
    Node<Line> *head; // указатель на первый узел списка
    Node<Line> *tail; // указатель на последний узел списка

public:
    // конструктор по умолчанию
    linked_list<Line>() : head(NULL), tail(NULL) {}

    // конструктор копирования
    linked_list<Line>(const linked_list<Line> &other) : head(nullptr), tail(nullptr)
    {
        Node<Line> *current = other.head; // начинаем с головы другого списка
        while (current)                   // пока не достигнем конца списка
        {
            add_product(current->tovar); // добавляем товар из текущего узла в новый список
            current = current->next;     // переход к следующему
        }
    }
    // конструктор перемещения
    linked_list<Line>(linked_list<Line> &&other) : head(other.head), tail(other.tail)
    {
        other.head = nullptr; // очищаем указатель на голову в исходном объекте
        other.tail = nullptr; // очищаем указатель на хвост в исходном объекте
    }

    // перегруженный оператор сложения для добавления товара
    linked_list<Line> &operator+(const Node<Line> &product)
    {
        add_product(product); // добавляем товар в список
        return *this;         // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // метод добавления товара в список
    void add_product(const Node<Line> &new_product)
    {
        Node<Line> *new_node = new Node<Line>(new_product); // создаем новый узел, используя конструктор node
        if (!head)                                          // проверка пуст ли список (head == nullptr)
        {
            head = tail = new_node; // если список пустой, новый узел становится и головой, и хвостом (начальная точка списка)
        }
        else
        {
            tail->next = new_node; // у текущего хвоста устанавливаем указатель на новый узел
            new_node->prev = tail; // у нового узла устанавливаем указатель на предыдущий узел (хвост)

            tail = new_node; // обновляем хвост списка, делая его текущим новым узлом
        }
    }

    // функция для вставки нового узла в заданную позицию
    Node<Line> *insertAtPos(Node<Line> *head, int pos, Node<Line> new_data)
    {

        Node<Line> *new_node = new Node<Line>(new_data); // создаем новый узел

        if (pos == 1) // вставка в начало
        {
            new_node->next = head;

            // если список не пуст, устанавливаем prev головы на новый узел
            if (head != NULL)
                head->prev = new_node;

            // устанавливаем новый узел как голову связанного списка
            head = new_node;
            return head;
        }

        Node<Line> *curr = head;
        // перемещаемся по списку, чтоб найти узел перед позицией вставки
        for (int i = 1; i < pos - 1 && curr != NULL; ++i)
        {
            curr = curr->next;
        }

        // если позиция вне границ
        if (curr == NULL)
        {
            delete new_node;
            return head;
        }

        new_node->prev = curr; // устанавливаем prev нового узла на текущий

        new_node->next = curr->next; // устанавливаем next нового узла на следующий от текущего

        curr->next = new_node; // обновляем next текущего узла на новый узел

        // если новый узел не последний, обновляем prev следующего узла на новый узел
        if (new_node->next != NULL)
            new_node->next->prev = new_node;

        return head; // возвращаем голову двусвяз списка
    }

    // сохранение списка товаров в файл
    void save_to_file(const std::string &filename)
    {
        std::ofstream file(filename); // открываем файл для записи
        Node<Line> *current = head;   // начинаем с головы списка
        while (current)               // пока не достигнем конца списка
        {
            int x1, y1, z1, x2, y2, z2;
            double l;
            current->tovar.get_product(x1, y1, z1, x2, y2, z2, l);                                                // получаем данные о товаре из текущего узла
            file << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << " " << l << std::endl; // записываем данные в файл
            current = current->next;                                                                              // переходим к следующему узлу
        }
        file.close(); // закрываем файл после записи
    }

    // метод загрузки списка товаров из файла
    void load_from_file(const std::string &filename)
    {
        std::ifstream file(filename); // открываем файл для чтения
        while (!file.eof())           // продолжаем до конца файла
        {
            int x1, y1, z1, x2, y2, z2;
            double l;
            file >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> l; // читаем данные из файла
            if (file)                                      // если данные были успешно прочитаны
            {
                Line new_product(x1, y1, z1, x2, y2, z2); // создаем новый товар
                add_product(new_product);                 // добавляем товар в список
            }
        }
        file.close(); // закрываем файл после чтения
    }

    // вывод списка товаров
    void print_list() const
    {
        Node<Line> *current = head; // начинаем с головы списка
        while (current)             // пока не достигнем конца списка
        {
            current->tovar.print_product(); // вывод инфы товара
            current = current->next;        // переходим к следующему
        }
    }
};

// специализация лист для прямоугольников

template <>
class linked_list<Rectangle>
{
private:
    Node<Rectangle> *head; // указатель на первый узел списка
    Node<Rectangle> *tail; // указатель на последний узел списка

public:
    // конструктор по умолчанию
    linked_list<Rectangle>() : head(NULL), tail(NULL) {}

    // конструктор копирования
    linked_list<Rectangle>(const linked_list<Rectangle> &other) : head(nullptr), tail(nullptr)
    {
        Node<Rectangle> *current = other.head; // начинаем с головы другого списка
        while (current)                        // пока не достигнем конца списка
        {
            add_product(current->tovar); // добавляем товар из текущего узла в новый список
            current = current->next;     // переход к следующему
        }
    }
    // конструктор перемещения
    linked_list<Rectangle>(linked_list<Rectangle> &&other) : head(other.head), tail(other.tail)
    {
        other.head = nullptr; // очищаем указатель на голову в исходном объекте
        other.tail = nullptr; // очищаем указатель на хвост в исходном объекте
    }

    // перегруженный оператор сложения для добавления товара
    linked_list<Rectangle> &operator+(const Node<Rectangle> &product)
    {
        add_product(product); // добавляем товар в список
        return *this;         // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // метод добавления товара в список
    void add_product(const Node<Rectangle> &new_product)
    {
        Node<Rectangle> *new_node = new Node<Rectangle>(new_product); // создаем новый узел, используя конструктор node
        if (!head)                                                    // проверка пуст ли список (head == nullptr)
        {
            head = tail = new_node; // если список пустой, новый узел становится и головой, и хвостом (начальная точка списка)
        }
        else
        {
            tail->next = new_node; // у текущего хвоста устанавливаем указатель на новый узел
            new_node->prev = tail; // у нового узла устанавливаем указатель на предыдущий узел (хвост)

            tail = new_node; // обновляем хвост списка, делая его текущим новым узлом
        }
    }

    // функция для вставки нового узла в заданную позицию
    Node<Rectangle> *insertAtPos(Node<Rectangle> *head, int pos, Node<Rectangle> new_data)
    {

        Node<Rectangle> *new_node = new Node<Rectangle>(new_data); // создаем новый узел

        if (pos == 1) // вставка в начало
        {
            new_node->next = head;

            // если список не пуст, устанавливаем prev головы на новый узел
            if (head != NULL)
                head->prev = new_node;

            // устанавливаем новый узел как голову связанного списка
            head = new_node;
            return head;
        }

        Node<Rectangle> *curr = head;
        // перемещаемся по списку, чтоб найти узел перед позицией вставки
        for (int i = 1; i < pos - 1 && curr != NULL; ++i)
        {
            curr = curr->next;
        }

        // если позиция вне границ
        if (curr == NULL)
        {
            delete new_node;
            return head;
        }

        new_node->prev = curr; // устанавливаем prev нового узла на текущий

        new_node->next = curr->next; // устанавливаем next нового узла на следующий от текущего

        curr->next = new_node; // обновляем next текущего узла на новый узел

        // если новый узел не последний, обновляем prev следующего узла на новый узел
        if (new_node->next != NULL)
            new_node->next->prev = new_node;

        return head; // возвращаем голову двусвяз списка
    }

    // сохранение списка товаров в файл
    void save_to_file(const std::string &filename)
    {
        std::ofstream file(filename);    // открываем файл для записи
        Node<Rectangle> *current = head; // начинаем с головы списка
        while (current)                  // пока не достигнем конца списка
        {
            int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
            double s;
            current->tovar.get_product(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, s); // получаем данные о товаре из текущего узла
            file << x1 << " " << y1 << " " << z1
                 << " " << x2 << " " << y2 << " " << z2
                 << " " << x3 << " " << y3 << " " << z3
                 << " " << x4 << " " << y4 << " " << z4 << " " << s << std::endl; // записываем данные в файл
            current = current->next;                                              // переходим к следующему узлу
        }
        file.close(); // закрываем файл после записи
    }

    // метод загрузки списка товаров из файла
    void load_from_file(const std::string &filename)
    {
        std::ifstream file(filename); // открываем файл для чтения
        while (!file.eof())           // продолжаем до конца файла
        {
            int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
            double s;
            file >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4 >> s; // читаем данные из файла
            if (file)                                                                          // если данные были успешно прочитаны
            {
                Rectangle new_product(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4); // создаем новый товар
                add_product(new_product);                                              // добавляем товар в список
            }
        }
        file.close(); // закрываем файл после чтения
    }

    // вывод списка товаров
    void print_list() const
    {
        Node<Rectangle> *current = head; // начинаем с головы списка
        while (current)                  // пока не достигнем конца списка
        {
            current->tovar.print_product(); // вывод инфы товара
            current = current->next;        // переходим к следующему
        }
    }
};

int main()
{
    /*
    int user_id;
    std::cin >> user_id;

    try
    {
        Product ex{user_id, "kotiki", 228, plugs::BOB};
    }
    catch (const ProductIncorrectIdException &e)
    {
        std::cout << e.what() << '\n';

        try
        {
            Product ex{-user_id, "kotiki", 228, plugs::BOB};
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    catch (const ProductException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    */

    linked_list<Product> pl;

    pl.add_product(Product(1, "Product1", 100, SLAY));

    linked_list<Dot> dd;
    dd.add_product(Dot());
    dd.add_product(Dot(1, 1, 1));
    // dd.save_to_file("products.txt");
    // dd.load_from_file("products.txt");
    dd.print_list();
    //   выводим первый вариант списка
    //  pl.print_list();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    // pl.print_list();

    linked_list<Line> lol;
    lol.add_product(Line());
    lol.add_product(Line(1, 1, 1, 1, 1, 1));
    lol.print_list();

    linked_list<Parall> l;
    l.add_product(Parall());
    l.add_product(Parall());
    // l.print_list();

    // pl.add_product(Product());

    // pl.save_to_file("products.txt");
    // pl.load_from_file("products.txt");
    // std::cout << "\n";

    // pl.remove_product(1);

    // pl.print_list();
    // std::cout << "\n";

    // // товары по фильтру
    // std::cout << "Products with ID = 2:" << std::endl;
    // pl.print_list_by_id(2);
    // std::cout << "\n";

    // std::cout << "Products with Price = 100:" << std::endl;
    // pl.print_list_by_price(100);
    // std::cout << "\n";

    // std::cout << "Products with Plug = SLAY:" << std::endl;
    // pl.print_list_by_plug(SLAY);

    return 0;
}