# include <iostream>
# include <vector>

using namespace std;

/* 基于数组实现的栈 */
class ArrayStack
{
    private:
        vector<int> stack;

    public:
        int size()
        {
            return stack.size();
        }

        bool isEmpty()
        {
            return stack.size() == 0;
        }

        void push(int num)
        {
            stack.push_back(num);
        }

        int pop()
        {
            int num = top();
            stack.pop_back();
            return num;
        }

        int top()
        {
            if (isEmpty())
                throw out_of_range("栈为空");
            return stack.back();
        }

        vector<int> toVector()
        {
            return stack;
        }
};