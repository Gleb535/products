#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum plugs
{
    SLAY,
    FSTAGE,
    OLEG,
    BOB
};

// класс товар
class product
{
    int id;           // id
    std::string name; // название товара
    int price;        // цена
    plugs plug;       // поставщик

public:
    // товар по умолчанию
    product() : id(0), name("noname"), price(0), plug(SLAY) {}

    // параметризованный конструктор
    product(int a, string n, int p, plugs g) : id(a), name(n), price(p), plug(g) {}

    // метод для установки значений товара
    void set_product(int a, string n, int p, plugs g)
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

    void set_name(string n)
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
    void get_product(int &a, string &n, int &p, plugs &g)
    {
        a = id;
        n = name;
        p = price;
        g = plug;
    }

    // метод для получения id товара
    int get_id() const
    {
        return id;
    }

    // метод вывода краткой информации о товаре
    void print_product() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << ", Plug: " << plug << endl;
    }
};

// класс узла для двусвязного списка
class node
{
public:
    product tovar; // товар в узле
    node *prev;    // указатель на предыдущий узел
    node *next;    // указатель на следующий узел

    // конструктор
    node(product new_tovar) : tovar(new_tovar), prev(NULL), next(NULL) {}
};

// двусвяз список
class product_list
{
private:
    node *head;
    node *tail;

public:
    // конструктор
    product_list() : head(NULL), tail(NULL) {}

    // метод добавления товара в список
    void add_product(const product &new_product)
    {
        node *new_node = new node(new_product);
        if (!head)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    // метод удаления товара из списка по id
    void remove_product(int id)
    {
        node *current = head;
        while (current)
        {
            if (current->tovar.get_id() == id)
            {
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                if (current == head)
                    head = current->next;
                if (current == tail)
                    tail = current->prev;
                delete current;
                break;
            }
            current = current->next;
        }
    }

    // сохранение списка товаров в файл
    void save_to_file(const string &filename)
    {
        ofstream file(filename);
        node *current = head;
        while (current)
        {
            int id, price;
            string name;
            plugs plug;
            current->tovar.get_product(id, name, price, plug);
            file << id << " " << name << " " << price << " " << plug << endl;
            current = current->next;
        }
        file.close();
    }

    // метод загрузки списка товаров из файла
    void load_from_file(const string &filename)
    {
        ifstream file(filename);
        while (!file.eof())
        {
            int id, price;
            string name;
            int plug;
            file >> id >> name >> price >> plug;
            if (file)
            {
                product new_product(id, name, price, static_cast<plugs>(plug));
                add_product(new_product);
            }
        }
        file.close();
    }

    // вывод списка товаров
    void print_list() const
    {
        node *current = head;
        while (current)
        {
            current->tovar.print_product();
            current = current->next;
        }
    }
};

void add_new_product()
{
    system("clear");
    product t;
    int n;
    cout << "Enter the name of product: ";
}

int main()
{

    product_list pl;
    int n;
    pl.add_product(product());
    system("clear");
    cout << "Choose an action:" << endl;
    cout << "0 - exit" << "\n"
         << "1 - add product" << "\n"
         << "2 - all products" << endl;
    cout << "Your choice: ";
    cin >> n;
    switch (n)
    {
    case 0:
        break;
    case 1:
        pl.add_product(product(1, "Product1", 100, SLAY));
        break;
    case 2:
        system("clear");
        pl.print_list();
        break;
    default:
        printf("Error input\n");
        break;
    }

    pl.add_product(product(1, "Product1", 100, SLAY));
    pl.add_product(product(2, "Product2", 200, FSTAGE));
    // pl.print_list();
    // pl.add_product(product());

    // pl.save_to_file("products.txt");
    // pl.load_from_file("products.txt");

    // pl.print_list();
    return 0;
}