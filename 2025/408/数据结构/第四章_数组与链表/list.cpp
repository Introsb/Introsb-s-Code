# include <iostream>
# include <vector>
using namespace std;

/* 列表类 */
class MyList
{
private:
    int *arr; // 数组(存储列表元素)
    int arrCapacity = 10;
    int arrSize = 0;
    int extendRatio;

public:
    /* 构造方法 */
    MyList()
    {
        arr = new int[arrCapacity];
    }

    /* 析构方法 */
    ~MyList()
    {
        delete[] arr;
    }

    int size()
    {
        return arrSize;
    }

    int capacity()
    {
        return arrCapacity;
    }

    int get(int index)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        return arr[index];
    }

    void set(int index, int num)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        arr[index] = num;
    }

    void add(int num)
    {
        if (size() == capacity())
            extendCapacity();
        arr[size()] = num;
        arrSize++;
    }

    void insert(int index, int num)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        if (size() == capacity())
            extendCapacity();
        for (int j = size() - 1; j >= index; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[index] = num;
        arrSize++;
    }

    int remove(int index)
    {
        if (index < 0 || index >= size())
            throw out_of_range("索引越界");
        int num = arr[index];
        for (int j = index; j < size() - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arrSize--;
        return num;
    }

    void extendCapacity()
    {
        int newCapacity = capacity() * extendRatio;
        int *tmp = arr;
        arr = new int[newCapacity];
        for ( int i = 0; i < size(); i++)
        {
            arr[i] = tmp[i];
        }
        delete[] tmp;
        arrCapacity = newCapacity;
    }

    vector<int> toVector()
    {
        vector<int> vec(size());
        for ( int i = 0; i < size(); i++)
        {
            vec[i] = arr[i];
        }
        return vec;
    }
};