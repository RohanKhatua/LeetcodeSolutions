#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }

        ListNode *curr = head->next;
        ListNode *prev = new ListNode(head->val);
        ListNode *new_node;
        while (curr != nullptr)
        {
            new_node = new ListNode(curr->val);
            new_node->next = prev;
            prev = new_node;
            curr = curr->next;
        }

        // new_node = new ListNode(curr->val);
        // new_node->next = prev;

        return new_node;
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
