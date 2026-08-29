#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

class Solution {
    public:
    bool isPalindrome(ListNode* head) 
    {
        vector<int> list_val;
        ListNode* p = head;
        while (p != nullptr)
        {
            list_val.push_back(p->val);
            p = p->next;
        }
        bool palindrome = true;
        int i = 0, j = list_val.size() - 1;
        while (i <= j)
        {
            if (list_val[i++] != list_val[j--])
                palindrome = false;
        }
        return palindrome;
    }
};