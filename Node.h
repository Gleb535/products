#ifndef _NODE_H_
#define _NODE_H_

// класс узла для двусвязного списка
template <typename T>
class Node
{
public:
    T tovar;    // товар в узле
    Node *prev; // указатель на предыдущий узел
    Node *next; // указатель на следующий узел

    // конструктор
    Node(T new_tovar) : tovar(new_tovar), prev(NULL), next(NULL) {}
};

#endif