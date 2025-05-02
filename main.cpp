#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

#include "common.h"

int main()
{

    int user_id = 'a';
    // std::cin >> user_id;
    int user_price = -2;

    try
    {
        Product ex{user_id, "kotiki", user_price, plugs::BOB};
    }
    catch (const ProductIncorrectIdException &e)
    {
        std::cout << e.what() << '\n';

        try
        {
            Product ex{-user_id, "kotiki", user_price, plugs::BOB};
        }
        catch (const ProductIncorrectPriceException &e)
        {
            std::cout << e.what() << '\n';

            try
            {
                Product ex{-user_id, "kotiki", -user_price, plugs::BOB};
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    catch (const ProductIncorrectPriceException &e)
    {
        try
        {
            Product ex{user_id, "kotiki", -user_price, plugs::BOB};
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
        std::cerr << e.what() << '\n';
    }

    linked_list<Product> pl;

    pl.add_product(Product(1, "1", 100, SLAY));
    pl.print_list();

    /*
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
*/

    linked_list<Dot> dd;
    dd.add_product(Dot());
    dd.add_product(Dot(1, 1, 1));
    // dd.print_list();
    dd.save_to_file("file.txt");
    dd.load_from_file("file.txt");

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    // std::string x = "bb ";
    // std::cout << typeid(x).name() << std::endl;

    linked_list<Line> lol;
    lol.add_product(Line());
    lol.add_product(Line(1, 1, 1, 1, 1, 1));
    // lol.print_list();

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    linked_list<Parall> l;
    l.add_product(Parall());
    // l.print_list();

    // NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
    // NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE

    // std::cout << "\n";
    // std::cout << "\n";
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