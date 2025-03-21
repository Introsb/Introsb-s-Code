# include <iostream>
# include <vector>
using namespace std;

/* 基于环形数组实现的队列 */
class ArrayQueue
{
    private:
        int *nums;
        int front;
        int queSize;
        int queCapacity;

    public:
        ArrayQueue(int capacity)
        {
            nums = new int[capacity];
            queCapacity = capacity;
            front = queSize = 0;
        }

        ~ArrayQueue()
        {
            delete[] nums;
        }

        /* 获取队列的容量 */
        int capacity()
        {
            return queCapacity;
        }

        /* 获取队列的长度 */
        int size()
        {
            return queSize;
        }

        /* 判断队列是否为空 */
        bool isEmpty()
        {
            return size() == 0;
        }

        /* 入队 */
        void push(int num)
        {
            if ( queSize == queCapacity )
            {
                cout << "队列已满 " << endl;
                return;
            }
            // 计算队尾指针，指向队尾索引 + 1
            // 通过取余操作实现 rear 越过数组尾部回到头部
            int rear = ( front + queSize ) % queCapacity;
            // 将 num 添加至队尾
            nums[rear] = num;
            queSize++;
        }
};