#include <iostream>
using namespace std;

struct Node
{
    unsigned int data; 
    Node *next;        
    Node(unsigned int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    private:
        Node *head; 
    public:
        LinkedList()
        {
            head = new Node(1);
        }

        ~LinkedList()
        {
            Node *p = head;
            while (p)
            {
                Node *tmp = p->next;
                delete p;
                p = tmp;
            }
        }

        // 插入
        void insert(unsigned int x, unsigned int y)
        {
            Node *p = head;
            while (p)
            {
                if (p->data == x)
                {
                    Node *node = new Node(y);
                    node->next = p->next;
                    p->next = node;
                    return;
                }
                p = p->next;
            }
        }

        // 查询
        unsigned int get_next(unsigned int x)
        {
            Node *p = head;
            while (p)
            {
                if (p->data == x)
                {
                    if (p->next)
                        return p->next->data;
                    else
                        return 0;
                }
                p = p->next;
            }
            return 0;
        }

        // 删除（头节点不会被删）
        void remove(unsigned int x)
        {
            if (head->data == x)
                return; 
            Node *p = head;
            while (p && p->next)
            {
                if (p->next->data == x)
                {
                    Node *tmp = p->next;
                    p->next = tmp->next;
                    delete tmp;
                    return;
                }
                p = p->next;
            }
        }

        // 把x改为y
        void modify(unsigned int x, unsigned int y)
        {
            Node *p = head;
            while (p)
            {
                if (p->data == x)
                {
                    p->data = y;
                    return;
                }
                p = p->next;
            }
        }

        // 打印链表
        void print()
        {
            Node *p = head;
            bool first = true;
            while (p)
            {
                if (!first)
                    cout << " ";
                cout << p->data;
                first = false;
                p = p->next;
            }
            cout << "\n";
        }
};

int main()
{
    int q;
    cin >> q;
    LinkedList list;

    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            unsigned int x, y;
            cin >> x >> y;
            list.insert(x, y);
        }
        else if (op == 2)
        {
            unsigned int x;
            cin >> x;
            cout << list.get_next(x) << "\n";
        }
        else if (op == 3)
        {
            unsigned int x;
            cin >> x;
            list.remove(x);
        }
        else if (op == 4)
        {
            unsigned int x, y;
            cin >> x >> y;
            list.modify(x, y);
        }
        else if (op == 5)
        {
            list.print();
        }
    }
    return 0;
}
