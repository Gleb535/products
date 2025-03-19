#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <vector>

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
    // конструктор без параметров (по умолчанию)
    product() : id(0), name("noname"), price(0), plug(SLAY) {}

    // параметризованный конструктор
    product(int a, string n, int p, plugs g) : id(a), name(n), price(p), plug(g) {}

    // конструктор копирования
    product(const product &other) : id(other.id), name(other.name), price(other.price), plug(other.plug) {}

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

    void get_prod_id(int &a)
    {
        a = id;
    }

    void get_prod_name(string &n)
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

    // метод для получения id товара
    int get_id() const
    {
        return id;
    }

    // метод для получения цены
    int get_price() const
    {
        return price;
    }

    int get_plug() const
    {
        return plug;
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

    // сортировка по id
    node *partition_id(node *low, node *high)
    {
        int pivot = high->tovar.get_id(); // опорный элемент для разбиения списка
        node *i = low->prev;              // указатель на элемент, который будет разделять список на две части

        for (node *j = low; j != high; j = j->next)
        { // перебор элементов списка от low до high
            if (j->tovar.get_id() <= pivot)
            {                                       // если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // перемещаем указатель i на следующую позицию
                swap(i->tovar, j->tovar);           // меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // после завершения цикла перемещаем i на следующую позицию
        swap(i->tovar, high->tovar);        // меняем местами элементы i и high
        return i;                           // возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort_by_id(node *low, node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                       // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            node *pi = partition_id(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_id(low, pi->prev);     // рекурсивно сортируем левую часть списка
            quickSort_by_id(pi->next, high);    // рекурсивно сортируем правую часть списка
        }
    }

    // сортировка по цене
    node *partition_price(node *low, node *high)
    {
        int pivot = high->tovar.get_price(); // опорный элемент для разбиения списка
        node *i = low->prev;                 // указатель на элемент, который будет разделять список на две части

        for (node *j = low; j != high; j = j->next)
        { // перебор элементов списка от low до high
            if (j->tovar.get_price() <= pivot)
            {                                       // если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // перемещаем указатель i на следующую позицию
                swap(i->tovar, j->tovar);           // меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // после завершения цикла перемещаем i на следующую позицию
        swap(i->tovar, high->tovar);        // меняем местами элементы i и high
        return i;                           // возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort_by_price(node *low, node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                          // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            node *pi = partition_price(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_price(low, pi->prev);     // рекурсивно сортируем левую часть списка
            quickSort_by_price(pi->next, high);    // рекурсивно сортируем правую часть списка
        }
    }

    // сортировка по поставщику
    node *partition_plug(node *low, node *high)
    {
        int pivot = high->tovar.get_plug(); // опорный элемент для разбиения списка
        node *i = low->prev;                // указатель на элемент, который будет разделять список на две части

        for (node *j = low; j != high; j = j->next)
        { // перебор элементов списка от low до high
            if (j->tovar.get_plug() <= pivot)
            {                                       // если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // перемещаем указатель i на следующую позицию
                swap(i->tovar, j->tovar);           // меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // после завершения цикла перемещаем i на следующую позицию
        swap(i->tovar, high->tovar);        // меняем местами элементы i и high
        return i;                           // возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort_by_plug(node *low, node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                         // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            node *pi = partition_plug(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_plug(low, pi->prev);     // рекурсивно сортируем левую часть списка
            quickSort_by_plug(pi->next, high);    // рекурсивно сортируем правую часть списка
        }
    }

public:
    // конструктор по умолчанию
    product_list() : head(NULL), tail(NULL) {}

    // конструктор копирования
    product_list(const product_list &other) : head(nullptr), tail(nullptr)
    {
        node *current = other.head;
        while (current)
        {
            add_product(current->tovar);
            current = current->next;
        }
    }
    // конструктор перемещения
    product_list(product_list &&other) noexcept : head(other.head), tail(other.tail)
    {
        other.head = nullptr;
        other.tail = nullptr;
    }

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

    // Функция для вставки нового узла в заданную позицию
    node *insertAtPos(node *head, int pos, node new_data)
    {

        // Создаем новый узел
        node *new_node = new node(new_data);

        // Вставка в начало
        if (pos == 1)
        {
            new_node->next = head;

            // Если связанный список не пуст, устанавливаем prev головы на новый узел
            if (head != NULL)
                head->prev = new_node;

            // Устанавливаем новый узел как голову связанного списка
            head = new_node;
            return head;
        }

        node *curr = head;
        // Перемещаемся по списку, чтобы найти узел перед точкой вставки
        for (int i = 1; i < pos - 1 && curr != NULL; ++i)
        {
            curr = curr->next;
        }

        // Если позиция вне границ
        if (curr == NULL)
        {
            cout << "Позиция вне границ." << endl;
            delete new_node;
            return head;
        }

        // Устанавливаем prev нового узла на текущий
        new_node->prev = curr;

        // Устанавливаем next нового узла на следующий от текущего
        new_node->next = curr->next;

        // Обновляем next текущего узла на новый узел
        curr->next = new_node;

        // Если новый узел не последний, обновляем prev следующего узла на новый узел
        if (new_node->next != NULL)
            new_node->next->prev = new_node;

        // Возвращаем голову двусвязного списка
        return head;
    }
    // метод удаления товара из списка по id
    void remove_product(int id)
    {
        node *curr = head;
        while (curr)
        {
            if (curr->tovar.get_id() == id)
            {
                if (curr->prev)
                    curr->prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = curr->prev;
                if (curr == head)
                    head = curr->next;
                if (curr == tail)
                    tail = curr->prev;
                delete curr;
                break;
            }
            curr = curr->next;
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

    // метод отображения списка по фильтру id
    void print_list_by_id(int id) const noexcept
    {
        node *current = head;
        while (current)
        {
            if (current->tovar.get_id() == id)
            {
                current->tovar.print_product();
            }
            current = current->next;
        }
    }

    // метод отображения списка по фильтру цены
    void print_list_by_price(int price) const noexcept
    {
        node *current = head;
        while (current)
        {
            if (current->tovar.get_price() == price)
            {
                current->tovar.print_product();
            }
            current = current->next;
        }
    }

    // метод отображения списка по фильтру поставщика
    void print_list_by_plug(plugs plug) const noexcept
    {
        node *current = head;
        while (current)
        {
            if (current->tovar.get_plug() == plug)
            {
                current->tovar.print_product();
            }
            current = current->next;
        }
    }
};

int main()
{

    product_list pl;

    pl.add_product(product(1, "Product1", 100, SLAY));
    pl.add_product(product(2, "Product2", 200, FSTAGE));
    pl.print_list();
    cout << "\n";

    pl.add_product(product());

    pl.save_to_file("products.txt");
    pl.load_from_file("products.txt");
    cout << "\n";

    pl.remove_product(1);

    pl.print_list();
    cout << "\n";
    // Отображение товаров с определенным фильтром
    cout << "Products with ID = 2:" << endl;
    pl.print_list_by_id(2);
    cout << "\n";

    cout << "Products with Price = 100:" << endl;
    pl.print_list_by_price(100);
    cout << "\n";

    cout << "Products with Plug = SLAY:" << endl;
    pl.print_list_by_plug(SLAY);

    return 0;
}