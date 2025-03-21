# include <iostream>
# include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};
/* 基于链表实现的栈 */
class LinkedListStack
{
    private:
        Node *stackTop;
        int stkSize;
    
    public:
        LinkedListStack()
        {
            stackTop = nullptr;
            stkSize = 0;
        }

        ~LinkedListStack()
        {
            // 遍历链表删除节点，释放内存
            freeMemoryLinkedList(stackTop);
        }

        void freeMemoryLinkedList(Node * stackTop)
        {}

        int size()
        {
            return stkSize;
        }

        bool isEmpty()
        {
            return size() == 0;
        }

        void push(int num)
        {
            Node *node = new Node(num);
            node->next = stackTop;
            stackTop = node;
            stkSize++;
        }

        int top()
        {
            if (isEmpty())
            {
                throw out_of_range("栈为空");
            }
            return stackTop->data;
        }

        vector<int> toVector()
        {
            Node *node = stackTop;
            vector<int> res(size());
            for (int i = res.size() - 1; i >= 0; i--)
            {
                res[i] = node->data;
                node = node->next;
            }
            return res;
        }

};
