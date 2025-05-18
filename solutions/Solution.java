package solutions;

public class Solution {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
       // write your code here
    }


//===================================================================================================================================================================================================================















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

    public static boolean areEqual(ListNode a, ListNode b) {
        while (a != null && b != null) {
            if (a.val != b.val) return false;
            a = a.next;
            b = b.next;
        }
        return a == null && b == null;
    }

    public static void printList(ListNode node) {
        if (node == null) {
            System.out.print("Empty list");
        } else {
            while (node != null) {
                System.out.print(node.val);
                if (node.next != null) System.out.print(" -> ");
                node = node.next;
            }
        }
        System.out.println();
    }

    public static void runTest(int[] list1, int[] list2, int[] expected, String testName) {
        Solution sol = new Solution();
        ListNode l1 = createList(list1);
        ListNode l2 = createList(list2);
        ListNode exp = createList(expected);

        ListNode result = sol.mergeTwoLists(l1, l2);

        boolean passed = areEqual(result, exp);
        System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));

        System.out.print("Merged List: ");
        printList(result);

        if (!passed) {
            System.out.print("Expected:    ");
            printList(exp);
        }
        System.out.println(); // blank line between tests
    }
}
