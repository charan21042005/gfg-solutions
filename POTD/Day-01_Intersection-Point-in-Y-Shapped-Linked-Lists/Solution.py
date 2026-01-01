'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:
    def intersectPoint(self, head1, head2):
        # Step 1: Find length of first linked list
        len1 = 0
        temp1 = head1
        while temp1:
            len1 += 1
            temp1 = temp1.next

        # Step 2: Find length of second linked list
        len2 = 0
        temp2 = head2
        while temp2:
            len2 += 1
            temp2 = temp2.next

        # Step 3: Find difference in lengths
        diff = abs(len1 - len2)

        # Step 4: Move pointer of longer list ahead
        temp1 = head1
        temp2 = head2

        if len1 > len2:
            while diff > 0:
                temp1 = temp1.next
                diff -= 1
        else:
            while diff > 0:
                temp2 = temp2.next
                diff -= 1

        # Step 5: Traverse both lists together
        while temp1 and temp2:
            if temp1 == temp2:
                return temp1.data   # intersection found
            temp1 = temp1.next
            temp2 = temp2.next

        # Step 6: No intersection
        return -1
