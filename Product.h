#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include <iostream>

#include "ProductException.h"

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

#endif