#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advance the first pointer by n+1 steps to create a gap of n nodes
        for (int i = 0; i <= n; ++i) {
            if (first == NULL) return NULL; // In case the list has fewer than n nodes
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int n = 2;
    head = solution.removeNthFromEnd(head, n);

    // Print the modified list
    printList(head);

    // Clean up the memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
