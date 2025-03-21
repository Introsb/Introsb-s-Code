# include <iostream>
# include <vector>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode *next;
        ListNode(int num)
        {
            val = num;
        }
};

class LinkedListQueue
{
    private:
        ListNode *front, *rear;
        int queSize;

    public:
        LinkedListQueue()
        {
            front = nullptr;
            rear = nullptr;
            queSize = 0;
        }

        ~LinkedListQueue()
        {
            freeMemoryLinkedList(front);
        }

        void freeMemoryLinkedList(ListNode * node){}

        int size()
        {
            return queSize;
        }

        bool isEmpty()
        {
            return queSize == 0;
        }

        void push(int num)
        {
            ListNode *node = new ListNode(num);
            if (front == nullptr)
            {
                front = node;
                rear = node;
            }
            else
            {
                rear->next = node;
                rear = node;
            }
            queSize++;
        }

        int pop()
        {
            int num = peek();
            ListNode *tmp = front;
            front = front->next;
            delete tmp;
            queSize--;
            return num;
        }

        int peek()
        {
            if (size() == 0)
                throw out_of_range("队列为空");
            return front->val;
        }

        vector<int> toVector()
        {
            ListNode *node = front;
            vector<int> res(size());
            for ( int i = 0; i <= res.size() - 1; i++)
            {
                res[i] = node->val;
                node = node->next;
            }
            return res;
        }
};

