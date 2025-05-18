package solutions;

public class Solution {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    // Merge two sorted linked lists
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }

        current.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }

    // Helper: Create a linked list from an array
    public static ListNode createList(int[] values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        return head;
    }

    // Helper: Compare two lists
    public static boolean areEqual(ListNode a, ListNode b) {
        while (a != null && b != null) {
            if (a.val != b.val) return false;
            a = a.next;
            b = b.next;
        }
        return a == null && b == null;
    }

    // Helper: Print a list
    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val);
            if (node.next != null) System.out.print(" -> ");
            node = node.next;
        }
        System.out.println();
    }

    // Runs a single test
    public static void runTest(int[] list1, int[] list2, int[] expected, String testName) {
        Solution sol = new Solution();
        ListNode l1 = createList(list1);
        ListNode l2 = createList(list2);
        ListNode exp = createList(expected);

        ListNode result = sol.mergeTwoLists(l1, l2);

        boolean passed = areEqual(result, exp);
        System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));
        if (!passed) {
            System.out.print("Expected: ");
            printList(exp);
            System.out.print("Got:      ");
            printList(result);
        }
    }
}
