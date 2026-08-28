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
    ListNode* reverseList(ListNode* head) 
    {
        vector<int> list_val;
        ListNode* q = head;
        while (q != nullptr)
        {
            list_val.push_back(q->val);
            q = q->next;
        }
        q = head;
        for (int i = list_val.size() - 1; i >= 0; i--)
        {
            q->val = list_val[i];
            q = q->next;
        }
        return head;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode* node = new ListNode(x);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
    Solution s;
    ListNode* result = s.reverseList(head);
    ListNode* p = result;
    while (p != nullptr)
    {
        cout << p->val;
        if (p->next != nullptr)
            cout << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}

