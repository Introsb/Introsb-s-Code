#include<iostream>
using namespace std;

// 定义节点结构体
struct Node
{
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head; //链表头指针
public:
    // 构造函数：初始化为空链表
    SinglyLinkedList() : head(nullptr) {}

    // 析构函数：释放链表所有节点
    ~SinglyLinkedList()
    {
        Node *current = head;
        while(current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 插入操作：在位置 pos 插入 value （位置从0开始），成功返回 true
    bool insert(int pos, int value)
    {
        if (pos < 0) return false;
        Node* newNode = new Node(value);
        // 插入到链表头
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return true;
        }
        Node* curr = head;
        int index = 0;
        // 找到待插入位置的前一个节点
        while (curr != nullptr && index < pos - 1)
        {
            curr = curr->next;
            index++;
        }
        if (curr == nullptr) // 插入位置超出链表长度
        {
            delete newNode;
            return false;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return true;
    }

    // 遍历操作：依次输出链表中的所有节点
    void traverse()
    {
        Node* curr = head;
        while(curr != nullptr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    // 删除操作：删除位置 pos 的节点，将删除的元素存入 value 中
    bool remove(int pos, int &value)
    {
        if ((pos < 0 )|| (head = nullptr)) return false;
        // 删除头节点
        if (pos == 0)
        {
            Node* temp = head;
            value = head->data;
            head = head->next;
            delete temp;
            return true;
        }
        Node* curr = head;
        int index = 0;
        // 找到待删除节点的前驱
        while(curr->next != nullptr && index < pos - 1)
        {
            curr = curr->next;
            index++;
        }
        if (curr->next == nullptr)
        {
            return false; //pos超出范围
        }
        Node* temp = curr->next;
        value = temp->data;
        curr->next = temp->next;
        delete temp;
    }

    // 查找操作：返回第一个与 value 相等的节点位置，未找到返回 -1
    int search(int value)
    {
        Node* curr = head;
        int index = 0;
        while(curr != nullptr)
        {
            if (curr->data == value)
                return index;
            curr = curr->next;
            index++;
        }
        return -1;
    }

    // 更新操作：将位置 pos 的节点更新为 newValue
    bool update(int pos, int newValue)
    {
        if (pos < 0) return false;
        Node* curr = head;
        int index = 0;
        while(curr != nullptr && index < pos)
        {
            curr = curr->next;
            index++;
        }
        if (curr == nullptr) return false;
        curr->data = newValue;
        return true;
    }
};

int main()
{
    SinglyLinkedList list;
    cout << "单链表插入操作：" << endl;
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 15);
    list.traverse();

    cout << "查找操作:查找15的位置 ->"<< list.search(15) << endl;

    cout << "更新操作:将下标1的元素更新为17" << endl;
    list.update(1, 17);
    list.traverse();

    return 0;  
}