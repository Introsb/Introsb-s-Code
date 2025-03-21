# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <utility>
using namespace std;

/* 链式地址哈希表 */
class HashMapChaining
{
    private:
        int size;             // 键值对数量
        int capacity;          // 哈希表容量
        double loadThres;     // 触发扩容的负载因子阈值
        int extendRatio;      // 扩容倍数
        vector<vector<pair<int,string>*>> buckets; // 桶数组     

    public:
        /* 构造方法 */
        HashMapChaining() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2)
        {
            buckets.resize(capacity);
        }

        /* 析构方法 */
        ~HashMapChaining()
        {
            for ( auto & bucket : buckets )
            {
                for ( pair<int,string>* pairptr : bucket )
                {
                    delete pairptr;  // 正确删除指针指向的对象
                }
            }
        }

        /* 哈希函数 */
        int hash(int key)
        {
            return key % capacity;
        }

        /* 负载因子 */
        double loadFactor()
        {
            return (double)size / (double)capacity;
        }

        /* 查询操作 */
        string get(int key)
        {
            int index = hash(key);
            for ( pair<int,string>* pairptr : buckets[index] )
            {
                if ( pairptr->first == key )
                {
                    return pairptr->second;
                }
            }
            return "";
        }

        /* 添加操作 */
        void put(int key, string value)
        {
            int index = hash(key);
            for ( pair<int,string>* pairptr : buckets[index] )
            {
                if ( pairptr->first == key )
                {
                    pairptr->second = value;
                    return;
                }
            }
            pair<int,string>* pairptr = new pair<int,string>(key, value);
            buckets[index].push_back(pairptr);
            size++;
            if ( loadFactor() > loadThres )
            {
                extend();
            }
        }

        /* 删除操作 */
        void remove(int key)
        {
            int index = hash(key);
            for ( auto it = buckets[index].begin(); it != buckets[index].end(); it++ )
            {
                if ( (*it)->first == key )
                {
                    delete *it;  // 正确删除指针指向的对象
                    buckets[index].erase(it);
                    size--;
                    return;
                }
            }
        }

        /* 扩容操作 */
        void extend()
        {
            int oldCapacity = capacity;
            capacity *= extendRatio;
            vector<vector<pair<int,string>*>> newBuckets;
            newBuckets.resize(capacity);
            for ( auto & bucket : buckets )
            {
                for ( pair<int,string>* pairptr : bucket )
                {
                    int index = pairptr->first % capacity;
                    newBuckets[index].push_back(pairptr);
                }
            }
            buckets = newBuckets;
        }

        /* 打印哈希表 */
        void print()
        {
            for ( int i = 0; i < capacity; i++ )
            {
                cout << i << ": ";
                for ( pair<int,string>* pairptr : buckets[i] )
                {
                    cout << "(" << pairptr->first << "," << pairptr->second << ") ";
                }
                cout << endl;
            }
        }


};