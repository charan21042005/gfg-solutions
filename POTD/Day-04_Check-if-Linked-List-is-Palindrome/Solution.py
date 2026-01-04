'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:

    # Helper function to reverse linked list
    def reverseList(self, head):
        prev = None
        curr = head

        while curr:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode

        return prev

    # ✅ OPTIMAL APPROACH
    def isPalindrome(self, head):

        # Edge cases
        if head is None or head.next is None:
            return True

        # Step 1: Find middle
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse second half
        secondHalf = self.reverseList(slow)

        # Step 3: Compare both halves
        firstHalf = head
        temp = secondHalf

        while temp:
            if firstHalf.data != temp.data:
                return False
            firstHalf = firstHalf.next
            temp = temp.next

        return True

'''
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Convert to List
values = []
while head:
    values.append(head.data)
Check palindrome using two pointers

2️⃣ Stack Method
Push first half into stack
Compare with second half

Both use O(n) extra space
'''
