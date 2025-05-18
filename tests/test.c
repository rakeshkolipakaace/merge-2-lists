#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Helper: Create linked list from array
ListNode* create_list(int* arr, int size) {
    if (size == 0) return NULL;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    head->next = NULL;

    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = arr[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }
    return head;
}

// Helper: Print linked list
void print_list(ListNode* head) {
    if (!head) {
        printf("(empty)");
    }
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Helper: Compare two linked lists for equality
int are_lists_equal(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == NULL && l2 == NULL;
}

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;

    return dummy.next;
}

// Run a single test
void run_test(int* v1, int size1, int* v2, int size2, int* expected, int expected_size, const char* description) {
    ListNode* list1 = create_list(v1, size1);
    ListNode* list2 = create_list(v2, size2);
    ListNode* merged = mergeTwoLists(list1, list2);
    ListNode* expected_list = create_list(expected, expected_size);

    printf("Test: %s\n", description);
    printf("Merged List: ");
    print_list(merged);

    if (are_lists_equal(merged, expected_list)) {
        printf("Result: PASSED ✅\n");
    } else {
        printf("Result: FAILED ❌\n");
    }
    printf("--------------------------\n");

    // Free allocated memory (simple way)
    // You can write a helper to free list if needed
}

int main() {
    printf("Running Test Cases...\n\n");

    int v1a[] = {1, 2, 4};
    int v2a[] = {1, 3, 4};
    int expected_a[] = {1, 1, 2, 3, 4, 4};
    run_test(v1a, 3, v2a, 3, expected_a, 6, "Basic merge with overlapping values");

    run_test(NULL, 0, NULL, 0, NULL, 0, "Both lists empty");

    int v2b[] = {0};
    int expected_b[] = {0};
    run_test(NULL, 0, v2b, 1, expected_b, 1, "First list empty");

    int v1c[] = {5};
    run_test(v1c, 1, NULL, 0, v1c, 1, "Second list empty");

    int v1d[] = {1, 2, 3};
    int v2d[] = {4, 5, 6};
    int expected_d[] = {1, 2, 3, 4, 5, 6};
    run_test(v1d, 3, v2d, 3, expected_d, 6, "All elements in list1 < list2");

    int v1e[] = {4, 5, 6};
    int v2e[] = {1, 2, 3};
    int expected_e[] = {1, 2, 3, 4, 5, 6};
    run_test(v1e, 3, v2e, 3, expected_e, 6, "All elements in list1 > list2");

    int v1f[] = {1};
    int v2f[] = {1};
    int expected_f[] = {1, 1};
    run_test(v1f, 1, v2f, 1, expected_f, 2, "Single identical values");

    int v1g[] = {1, 1, 1};
    int v2g[] = {1, 1, 1};
    int expected_g[] = {1, 1, 1, 1, 1, 1};
    run_test(v1g, 3, v2g, 3, expected_g, 6, "All values are same");

    int v1h[] = {-3, -2, -1};
    int v2h[] = {0, 1, 2};
    int expected_h[] = {-3, -2, -1, 0, 1, 2};
    run_test(v1h, 3, v2h, 3, expected_h, 6, "Negative and positive numbers");

    int v1i[] = {1, 4, 6};
    int v2i[] = {2, 3, 5};
    int expected_i[] = {1, 2, 3, 4, 5, 6};
    run_test(v1i, 3, v2i, 3, expected_i, 6, "Interleaved values");

    int v1j[] = {1};
    int v2j[] = {2, 3, 4, 5};
    int expected_j[] = {1, 2, 3, 4, 5};
    run_test(v1j, 1, v2j, 4, expected_j, 5, "One list has only one element");

    int v1k[] = {2, 3, 4, 5};
    int v2k[] = {1};
    int expected_k[] = {1, 2, 3, 4, 5};
    run_test(v1k, 4, v2k, 1, expected_k, 5, "One list has only one element (reverse)");

    int v1l[] = {-10, -10, -5};
    int v2l[] = {-6, -6, -2};
    int expected_l[] = {-10, -10, -6, -6, -5, -2};
    run_test(v1l, 3, v2l, 3, expected_l, 6, "Duplicates with negatives");

    int v1m[] = {0};
    int v2m[] = {0};
    int expected_m[] = {0, 0};
    run_test(v1m, 1, v2m, 1, expected_m, 2, "Both have one element with the same value");

    printf("\n✅ All test cases finished!\n");
    return 0;
}
