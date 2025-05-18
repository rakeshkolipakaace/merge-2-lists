// solution.cpp...

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify logic
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Loop through both lists and merge them
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining part of the non-empty list
        if (list1 != nullptr) current->next = list1;
        else current->next = list2;

        // Return the merged list starting from dummy.next
        return dummy.next;
    }
};
