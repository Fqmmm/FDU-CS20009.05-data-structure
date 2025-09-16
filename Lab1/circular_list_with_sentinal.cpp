#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : Node(data, NULL) {}
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class CircularLinkedList
{
private:
    Node *sentinal; // 哨兵节点
    int size;

public:
    CircularLinkedList()
    {
        this->sentinal = new Node(-1);
        this->sentinal->next = sentinal; // 初始时指向自己
        this->size = 0;
    }

    ~CircularLinkedList()
    {
        Node *p = sentinal->next;
        while (p != sentinal)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
        delete sentinal;
    }

    // 尾插法插入一个节点
    void insert(int val)
    {
        Node *newNode = new Node(val, sentinal);
        Node *p = sentinal;
        while (p->next != sentinal)
        {
            p = p->next;
        }
        p->next = newNode;
        size++;
    }

    // 约瑟夫过程，返回最后的胜者编号
    int josephus(int n, int k)
    {
        // 构建循环链表
        for (int i = 1; i <= n; i++)
        {
            insert(i);
        }

        if (n == 1) return 1;

        Node *prev = sentinal;
        Node *current = sentinal->next;

        int count = size;
        while (count > 1)
        {
            // 报数 k-1 次
            for (int i = 1; i < k; i++)
            {
                prev = current;
                current = current->next;
                if (current == sentinal) // 跳过哨兵
                {
                    prev = current;
                    current = current->next;
                }
            }

            // 删除 current
            prev->next = current->next;
            Node *toDelete = current;
            current = prev->next;
            if (current == sentinal) current = current->next; // 跳过哨兵
            delete toDelete;
            count--;
        }

        return current->data;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    CircularLinkedList list;
    int winner = list.josephus(n, k);
    cout << winner << endl;
    return 0;
}
