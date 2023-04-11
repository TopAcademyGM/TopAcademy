#include <iostream>
#include <string>

template <typename T>
class my_list
{
private:
    struct node
    {
        T value;
        node *next;
        node *prev;

        node() : node(T()) {}
        explicit node(const T &value,
                      node *next = nullptr,
                      node *prev = nullptr)
            : value(value), next(next), prev(prev) {}
    };

    node *head; // голова (первый элемент)
    node *tail; // хвост  (последний элемент)
    int size;

    void ch_head(node *n_node)
    {
        node *tmp = this->head;
        this->head = n_node;
        if (tmp != nullptr)
        {
            tmp->prev = this->head;
        }
        this->head->next = tmp;
        this->head->prev = this->tail;

        this->tail->next = this->head;
    }
    node *node_by_index(int i)
    {
        node *find_node = this->head;
        while (i != 0)
        {
            find_node = find_node->next;
            --i;
        }
        return find_node;
    }

public:
    void insert(int index, const T &val)
    {
        node *tmp = node_by_index(index);
        node *new_node = new node(val, tmp, tmp->prev);
        if (tmp != nullptr)
        {
            if (tmp->prev != nullptr)
            {
                tmp->prev->next = new_node;
            }
            tmp->prev = new_node;
        }
        this->size++;
    }
    my_list() : size(0), head(nullptr)
    {
        tail = new node();
    }
    my_list(const std::initializer_list<T> &list)
    {
        tail = new node();
        this->size = 0;
        for (auto i = list.begin(); i != list.end(); ++i)
        {
            if (i == list.begin())
            {
                ch_head(new node(*i));
                this->tail->prev = this->head;
                this->head->next = this->tail;
                this->size++;
            }
            else
            {
                insert(this->size, *i);
            }
        }
    }
    void erase(int index)
    {
        node *tmp = node_by_index(index);
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        this->size--;
    }
    void erase(int i_start, int i_end)
    {
        node *save_start;
        if (i_start == 0)
            save_start = tail;
        else
            save_start = node_by_index(i_start - 1);

        node *save_end = node_by_index(i_end + 1);
        node *i = node_by_index(i_start);
        while (i != save_end)
        {
            node *tmp = i;
            i = i->next;
            delete tmp;
            this->size--;
        }
        save_start->next = save_end;
        save_end->prev = save_start;
        if (save_start == tail) {
            head = save_end;
        }
    }

    void print()
    {
        for (node *i = this->head; i != this->tail; i = i->next)
        {
            std::cout << i->value << " ";
        }
        std::cout << "\n";
    }

    ~my_list()
    {
        node *i = this->head;
        while (i != this->tail)
        {
            node *tmp = i;
            i = tmp->next;
            delete tmp;
        }
        delete this->tail;
    }
};

int main()
{
    my_list<std::string> str_list({"Kat", "Dog", "Wolf", "Snake"});
    std::cout << "test\n";
    str_list.print();
    str_list.insert(2, "Enot");
    str_list.print();
    str_list.erase(4);
    str_list.print();
    str_list.erase(0, 2);
    str_list.print();

    return 0;
}
