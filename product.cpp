#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

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

    node *partition(node *low, node *high)
    {
        int pivot = high->tovar.get_id(); // Опорный элемент для разбиения списка
        node *i = low->prev;              // Указатель на элемент, который будет разделять список на две части

        for (node *j = low; j != high; j = j->next)
        { // Перебираем элементы списка от low до high
            if (j->tovar.get_id() <= pivot)
            {                                       // Если текущий элемент меньше или равен опорному
                i = (i == nullptr) ? low : i->next; // Перемещаем указатель i на следующую позицию
                swap(i->tovar, j->tovar);           // Меняем местами элементы i и j
            }
        }
        i = (i == nullptr) ? low : i->next; // После завершения цикла перемещаем i на следующую позицию
        swap(i->tovar, high->tovar);        // Меняем местами элементы i и high
        return i;                           // Возвращаем указатель на элемент i, который является разделителем между двумя частями списка
    }

    void quickSort(node *low, node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                    // Проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            node *pi = partition(low, high); // Разбиваем список на две части с помощью метода partition
            quickSort(low, pi->prev);        // Рекурсивно сортируем левую часть списка
            quickSort(pi->next, high);       // Рекурсивно сортируем правую часть списка
        }
    }

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
    return 0;
}