#ifndef _LINKED_LIST_RECTANGLE_H_
#define _LINKED_LIST_RECTANGLE_H_

#include "Linked_list.h"
#include "Rectangle.h"

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

#endif