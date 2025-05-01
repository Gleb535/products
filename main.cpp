#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

#include "common.h"

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