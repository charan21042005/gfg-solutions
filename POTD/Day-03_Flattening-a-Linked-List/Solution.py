'''
class Node:
    def __init__(self, d):
        self.data = d
        self.next = None
        self.bottom = None
'''

class Solution:
    # Helper function to merge two sorted bottom-linked lists
    def merge(self, a, b):

        # If one list is empty, return the other
        if a is None:
            return b
        if b is None:
            return a

        # Choose smaller node and recurse
        if a.data < b.data:
            result = a
            result.bottom = self.merge(a.bottom, b)
        else:
            result = b
            result.bottom = self.merge(a, b.bottom)

        # next pointer is not used in final list
        result.next = None
        return result

    def flatten(self, root):
        # Base case: empty list or single column
        if root is None or root.next is None:
            return root

        # Step 1: Flatten the list on the right
        root.next = self.flatten(root.next)

        # Step 2: Merge current list with flattened right list
        root = self.merge(root, root.next)

        return root
