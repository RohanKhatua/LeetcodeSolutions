#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> visited;
        while (head!=NULL) {
            if (find(all(visited),head)==visited.end()) {
                visited.push_back(head);     
                head = head->next;
                continue;
            }
            else return true;
        }
        return false;
    }
};