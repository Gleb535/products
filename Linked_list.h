#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <fstream>

#include "Node.h"
#include "Product.h"

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

        Node<F> *current = head; // начинаем с головы списка
        while (current)          // пока не достигнем конца списка
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

        while (!file.eof()) // продолжаем до конца файла
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

#endif