# include <iostream>
# include <vector>
using namespace std;

struct DoubleListNode
{
    int val;
    DoubleListNode *next;
    DoubleListNode *prev;
    DoubleListNode(int val) : val(val), prev(nullptr), next(nullptr)
    {}
};

/* 基于双向链表实现的双向队列 */
class LinkedListDeque
{
    private: 
        DoubleListNode *front, *rear; // 头节点 front， 尾节点 rear
        int queSize = 0; // 双向队列的长度

    public:
        /* 构造方法 */
        LinkedListDeque() : front(nullptr), rear(nullptr)
        {}

        /* 析构函数 */
        ~LinkedListDeque()
        {
            // 遍历链表删除节点，释放内存
            DoubleListNode *pre, *cur = front;
            while ( cur != nullptr )
            {
                pre = cur;
                cur = cur -> next;
                delete pre;
            }
        }

        /* 获取双向队列的长度 */
        int size()
        {
            return queSize;
        }

        /* 判断双向队列是否为空 */
        bool isEmpty()
        {
            return size() == 0;
        }

        /* 入队操作 */
        void push(int num, bool isFront)
        {
            DoubleListNode *node = new DoubleListNode(num);
            // 若链表为空，则令 front 和 rear 都指向 node
            if (isEmpty())
            {
                front = rear = node;
            }
            // 队首入队操作
            else if (isFront)
            {
                // 将 node 添加至链表头部
                front->prev = node;
                node->next = front;
                front = node; // 更新头节点
            }
            // 队尾入队操作
            else
            {
                // 将 node 添加至链表尾部
                rear->next = node;
                node->prev = rear;
                rear = node; // 更新尾节点
            }
            queSize++; // 更新队列长度
        }

        /* 队首入队 */
        void pushFirst(int num)
        {
            push(num, true);
        }

        /* 队尾入队 */
        void pushLast(int num)
        {
            push(num, false);
        }

        /* 出队操作 */
        int pop(bool isFront)
        {
            if (isEmpty())
            {
                throw out_of_range("队列为空");
            }
            int val;
            // 队首出队操作
            if (isFront)
            {
                val = front->val; // 暂存头节点值
                // 删除头节点
                DoubleListNode *fNext = front->next;
                if (fNext != nullptr)
                {
                    fNext->prev = nullptr;
                }
            }
        }
};
