#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advances first pointer so that the gap between first and second is n nodes
        for(int i = 1; i <= n + 1; i++) {
            first = first->next;
        }

        // Move first to the end, maintaining the gap
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // second is now the node before the one we want to remove
        second->next = second->next->next;

        return dummy->next;
    }
};
