// testcases.cpp

#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"

using namespace std;

// Helper: Create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper: Print the linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "(empty)" << endl;
        return;
    }
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Test runner
void runTest(const vector<int>& v1, const vector<int>& v2, const string& description) {
    Solution sol;
    ListNode* list1 = createList(v1);
    ListNode* list2 = createList(v2);
    ListNode* merged = sol.mergeTwoLists(list1, list2);
    cout << "Test: " << description << endl;
    cout << "Merged List: ";
    printList(merged);
    cout << "--------------------------" << endl;
}

int main() {
    cout << "Running Test Cases...\n";

    runTest({1, 2, 4}, {1, 3, 4}, "Basic merge with overlapping values");
    runTest({}, {}, "Both lists empty");
    runTest({}, {0}, "First list empty");
    runTest({5}, {}, "Second list empty");
    runTest({1, 2, 3}, {4, 5, 6}, "All elements in list1 < list2");
    runTest({4, 5, 6}, {1, 2, 3}, "All elements in list1 > list2");
    runTest({1}, {1}, "Single identical values");
    runTest({1, 1, 1}, {1, 1, 1}, "All values are same");
    runTest({-3, -2, -1}, {0, 1, 2}, "Negative and positive numbers");
    runTest({1, 4, 6}, {2, 3, 5}, "Interleaved values");
    runTest({1}, {2, 3, 4, 5}, "One list has only one element");
    runTest({2, 3, 4, 5}, {1}, "One list has only one element (reverse)");
    runTest({-10, -10, -5}, {-6, -6, -2}, "Duplicates with negatives");
    runTest({0}, {0}, "Both have one element with the same value");

    return 0;
}
