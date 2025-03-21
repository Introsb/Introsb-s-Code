# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* l3 = new ListNode();
            ListNode* curr = l3;
            int carry = 0;
            while ( l1 || l2 || carry)
            {
                int a = l1 ? l1->val : 0;
                int b = l2 ? l2->val : 0;
                int sum = a + b + carry;
                carry = sum >= 10 ? 1 : 0;
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
            return l3->next;
        }
    };