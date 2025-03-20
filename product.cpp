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

// функция для преобразования значения plug-ов в строку
string plug_to_string(plugs plug)
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
    Product(int a, string n, int p, plugs g) : id(a), name(n), price(p), plug(g) {}

    // конструктор копирования
    Product(const Product &other) : id(other.id), name(other.name), price(other.price), plug(other.plug) {}

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
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << ", Plug: " << plug_to_string(plug) << endl;
    }

    // метод вывода краткой информации о товаре
    void short_print_product() const
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

// класс узла для двусвязного списка
class Node
{
public:
    Product tovar; // товар в узле
    Node *prev;    // указатель на предыдущий узел
    Node *next;    // указатель на следующий узел

    // конструктор
    Node(Product new_tovar) : tovar(new_tovar), prev(NULL), next(NULL) {}
};

// двусвяз список
class product_list
{
private:
    Node *head; // указатель на первый узел списка
    Node *tail; // указатель на последний узел списка

    // сортировка по id

    Node *partition_id(Node *low, Node *high)
    {
        int pivot = high->tovar.get_id(); // опорный элемент для разбиения списка
        Node *i = low->prev;              // указатель на элемент, который будет разделять список на две части

        for (Node *j = low; j != high; j = j->next)
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

    void quickSort_by_id(Node *low, Node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                       // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            Node *pi = partition_id(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_id(low, pi->prev);     // рекурсивно сортируем левую часть списка
            quickSort_by_id(pi->next, high);    // рекурсивно сортируем правую часть списка
        }
    }

    // сортировка по цене

    Node *partition_price(Node *low, Node *high)
    {
        int pivot = high->tovar.get_price(); // опорный элемент для разбиения списка
        Node *i = low->prev;                 // указатель на элемент, который будет разделять список на две части

        for (Node *j = low; j != high; j = j->next)
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

    void quickSort_by_price(Node *low, Node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                          // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            Node *pi = partition_price(low, high); // разбиваем список на две части с помощью метода partition
            quickSort_by_price(low, pi->prev);     // рекурсивно сортируем левую часть списка
            quickSort_by_price(pi->next, high);    // рекурсивно сортируем правую часть списка
        }
    }

    // сортировка по поставщику

    Node *partition_plug(Node *low, Node *high)
    {
        int pivot = high->tovar.get_plug(); // опорный элемент для разбиения списка
        Node *i = low->prev;                // указатель на элемент, который будет разделять список на две части

        for (Node *j = low; j != high; j = j->next)
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

    void quickSort_by_plug(Node *low, Node *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {                                         // проверяем, что high не равен nullptr, и low не равен high, и low не равен следующему элементу после high
            Node *pi = partition_plug(low, high); // разбиваем список на две части с помощью метода partition
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
        Node *current = other.head; // начинаем с головы другого списка
        while (current)             // пока не достигнем конца списка
        {
            add_product(current->tovar); // добавляем товар из текущего узла в новый список
            current = current->next;     // переход к следующему
        }
    }
    // конструктор перемещения
    product_list(product_list &&other) : head(other.head), tail(other.tail)
    {
        other.head = nullptr; // очищаем указатель на голову в исходном объекте
        other.tail = nullptr; // очищаем указатель на хвост в исходном объекте
    }

    // перегруженный оператор сложения для добавления товара
    product_list &operator+(const Product &product)
    {
        add_product(product); // добавляем товар в список
        return *this;         // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // перегруженный оператор вычетания для удаления товара по id
    product_list &operator-(int id)
    {
        remove_product(id); // удаляем товар с указанным id из списка
        return *this;       // возвращаем ссылку на текущий объект (для поддержания цепочки вызовов)
    }

    // метод добавления товара в список
    void add_product(const Product &new_product)
    {
        Node *new_node = new Node(new_product); // создаем новый узел, используя конструктор node
        if (!head)                              // проверка пуст ли список (head == nullptr)
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
    Node *insertAtPos(Node *head, int pos, Node new_data)
    {

        Node *new_node = new Node(new_data); // создаем новый узел

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

        Node *curr = head;
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
        Node *current = head; // начинаем с головы списка
        while (current)       // пока не достигнем конца списка
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
    void save_to_file(const string &filename)
    {
        ofstream file(filename); // открываем файл для записи
        Node *current = head;    // начинаем с головы списка
        while (current)          // пока не достигнем конца списка
        {
            int id, price;
            string name;
            plugs plug;
            current->tovar.get_product(id, name, price, plug);                // получаем данные о товаре из текущего узла
            file << id << " " << name << " " << price << " " << plug << endl; // записываем данные в файл
            current = current->next;                                          // переходим к следующему узлу
        }
        file.close(); // закрываем файл после записи
    }

    // метод загрузки списка товаров из файла
    void load_from_file(const string &filename)
    {
        ifstream file(filename); // открываем файл для чтения
        while (!file.eof())      // продолжаем до конца файла
        {
            int id, price;
            string name;
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
        Node *current = head; // начинаем с головы списка
        while (current)       // пока не достигнем конца списка
        {
            current->tovar.print_product(); // вывод инфы товара
            current = current->next;        // переходим к следующему
        }
    }

    // метод отображения списка по фильтру id
    void print_list_by_id(int id) const
    {
        Node *current = head;
        while (current) // пока не достигнут конец списка
        {
            if (current->tovar.get_id() == id) // проверка на соответствию с фильтром
            {
                current->tovar.print_product(); // вывод инфы товара
            }
            current = current->next; // переходим к следующему
        }
    }

    // метод отображения списка по фильтру цены
    void print_list_by_price(int price) const
    {
        Node *current = head; // начинаем с головы списка
        while (current)       // пока не достигнем конца списка
        {
            if (current->tovar.get_price() == price) // проверка на соответствию с фильтром
            {
                current->tovar.print_product(); // вывод инфы товара
            }
            current = current->next; // переходим к следующему
        }
    }

    // метод отображения списка по фильтру поставщика
    void print_list_by_plug(plugs plug) const
    {
        Node *current = head; // начинаем с головы списка
        while (current)       // пока не достигнем конца списка
        {
            if (current->tovar.get_plug() == plug) // проверка на соответствию с фильтром
            {
                current->tovar.print_product(); // вывод инфы товара
            }
            current = current->next; // переходим к следующему
        }
    }
};

int main()
{

    product_list pl;

    pl.add_product(Product(1, "Product1", 100, SLAY));
    pl.add_product(Product(2, "Product2", 200, FSTAGE));
    pl.print_list();
    cout << "\n";

    pl.add_product(Product());

    pl.save_to_file("products.txt");
    pl.load_from_file("products.txt");
    cout << "\n";

    pl.remove_product(1);

    pl.print_list();
    cout << "\n";

    // товары по фильтру
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