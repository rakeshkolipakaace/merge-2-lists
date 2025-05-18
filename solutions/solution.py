# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: ListNode or None
        :type list2: ListNode or None
        :rtype: ListNode or None
        """
        dummy = ListNode(-1)  # Temporary node to simplify the merging logic
        current = dummy

        while list1 and list2:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        # Attach the remaining elements (if any)
        if list1:
            current.next = list1
        elif list2:
            current.next = list2

        return dummy.next  # Head of the merged list
