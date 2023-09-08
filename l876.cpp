#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     ListNode *middleNode(ListNode *head)
//     {
//         if (head->next == nullptr)
//         {
//             return head;
//         }

//         ListNode *copy = head;
//         int c = 0;
//         while (copy->next != nullptr)
//         {
//             c++;
//             copy = copy->next;
//         }

//         for (int i = 0; i < c / 2; i++)
//         {
//             head = head->next;
//         }

//         return c % 2 != 0 ? head->next : head;
//     }
// };

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode * fast = head;
        ListNode * slow = head;

        while (fast->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};