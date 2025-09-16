#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) 
    {
        this->data = val;
        this->next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;
    int size;
public:
    CircularLinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    ~CircularLinkedList() {
        if (head == NULL) return;
        Node* p = head->next;
        while(p != head) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
        delete head;
        head = NULL;
    }
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head; 
        } else {
            Node* p = head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    
    int josephus(int n, int k) {
        // 构建链表
        for (int i = 1; i <= n; i++) {
            insert(i);
        }
        
        // 如果只有一个人，他就是获胜者
        if (n == 1) {
            return 1;
        }

        
        Node* current = head;
        Node* prev = head;
        while (prev->next != head) {
            prev = prev->next;
        }

        // 模拟报数和出列过程，直到链表只剩一个节点
        while (size > 1) {
            for (int i = 1; i < k; i++) {
                prev = current;
                current = current->next;
            }
            
            prev->next = current->next;
            
            // 如果出列的是头节点，需要更新 head 指针
            if (current == head) {
                head = prev->next;
            }

            Node* toDelete = current;
            current = prev->next;
            delete toDelete;
            size--;
        }
        
        return head->data;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    CircularLinkedList list;
    int winner = list.josephus(n, k);
    cout << winner << endl;
    return 0;
}