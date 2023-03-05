#include <bits\stdc++.h>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *Temp = head, *Walk = head;
        for (int i = 0; i < n - 1; ++i)
        {
            Temp = Temp->next;
        }
        while (Temp->next != nullptr)
        {
            Temp = Temp->next;
            Walk = Walk->next;
        }
        if (Walk->next == nullptr)
        {
            if (Walk == head)
            {
                head = nullptr;
            }
            delete Walk;
        }
        else
        {
            Walk->val = Walk->next->val;
            ListNode *Dele = Walk->next;
            Walk->next = Walk->next->next;
            delete Dele;
        }
        return head;
    }
};
int main(int argc, char **argv)
{
    Solution S;
    return 0;
}
