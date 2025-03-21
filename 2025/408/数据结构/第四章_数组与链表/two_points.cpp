# include <iostream>
using namespace std;

// 链表节点结构定义
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

int findKthNodeFromEnd_TwoPointers(LinkList list, int k)
{
    if (list == nullptr || list -> next == nullptr)
    {
        return 0;
    }
    if (k <= 0)
    {
        return 0;
    }

    LNode *fast = list;
    LNode *slow = list;
    int count = 0;

    // 快指针先移动 k 步
    for(int i = 0; i < k; ++i)
    {
        if(fast == nullptr)
        {
            return 0;
        }
        fast = fast->next;
        count++;
    }

    if(fast == nullptr)
    {
        return 0;
    }

    // 快慢指针同步移动
    while(fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    cout << "找到倒数第" << k << "个结点，data 值为：" << slow->next << endl;
    return 1;

}