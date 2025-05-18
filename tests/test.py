# tests/test_merge_lists.py

import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../solutions')))

from solution import Solution, ListNode

def create_list(vals):
    if not vals:
        return None
    head = current = ListNode(vals[0])
    for val in vals[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def print_list(head):
    if not head:
        print("(empty)")
        return
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(" -> ".join(vals))

def are_lists_equal(l1, l2):
    while l1 and l2:
        if l1.val != l2.val:
            return False
        l1 = l1.next
        l2 = l2.next
    return l1 is None and l2 is None

def run_test(v1, v2, expected, description):
    sol = Solution()
    list1 = create_list(v1)
    list2 = create_list(v2)

    merged = sol.mergeTwoLists(list1, list2)

    print(f"Test: {description}")
    print("Merged List: ", end="")
    print_list(merged)

    expected_list = create_list(expected)
    if are_lists_equal(merged, expected_list):
        print("Result: PASSED ✅")
    else:
        print("Result: FAILED ❌")
    print("--------------------------")

if __name__ == "__main__":
    print("Running Test Cases...\n")

    run_test([1, 2, 4], [1, 3, 4], [1, 1, 2, 3, 4, 4], "Basic merge with overlapping values")
    run_test([], [], [], "Both lists empty")
    run_test([], [0], [0], "First list empty")
    run_test([5], [], [5], "Second list empty")
    run_test([1, 2, 3], [4, 5, 6], [1, 2, 3, 4, 5, 6], "All elements in list1 < list2")
    run_test([4, 5, 6], [1, 2, 3], [1, 2, 3, 4, 5, 6], "All elements in list1 > list2")
    run_test([1], [1], [1, 1], "Single identical values")
    run_test([1, 1, 1], [1, 1, 1], [1, 1, 1, 1, 1, 1], "All values are same")
    run_test([-3, -2, -1], [0, 1, 2], [-3, -2, -1, 0, 1, 2], "Negative and positive numbers")
    run_test([1, 4, 6], [2, 3, 5], [1, 2, 3, 4, 5, 6], "Interleaved values")
    run_test([1], [2, 3, 4, 5], [1, 2, 3, 4, 5], "One list has only one element")
    run_test([2, 3, 4, 5], [1], [1, 2, 3, 4, 5], "One list has only one element (reverse)")
    run_test([-10, -10, -5], [-6, -6, -2], [-10, -10, -6, -6, -5, -2], "Duplicates with negatives")
    run_test([0], [0], [0, 0], "Both have one element with the same value")

    print("\n✅ All test cases finished!")
