// test.c
#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"  // Include the actual reverseList function

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

// Helper: Free linked list memory
void free_list(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        free(head);
        head = next;
    }
}

// Run a single test case
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

    free_list(merged);
    free_list(expected_list);
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

    printf("\n✅ All test cases finished!\n");
    return 0;
}
