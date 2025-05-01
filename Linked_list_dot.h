#ifndef _LINKED_LIST_DOT_H_
#define _LINKED_LIST_DOT_H_

#include "Linked_list.h"
#include "Dot.h"

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

#endif