#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode *new_head = reverseList(head->next);
        
        head->next->next = head;
        head->next = prev;

        return new_head;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(3);

    ListNode *new_head = s.reverseList(head);
    while (new_head != nullptr)
    {
        cout << new_head->val << "\t";
        new_head = new_head->next;
    }
}
