/*
class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
*/

class Solution {

    // Helper function to merge two sorted bottom-linked lists
    private Node merge(Node a, Node b) {

        // If one list is empty, return the other
        if (a == null) return b;
        if (b == null) return a;

        Node result;

        // Pick smaller node and merge recursively
        if (a.data < b.data) {
            result = a;
            result.bottom = merge(a.bottom, b);
        } else {
            result = b;
            result.bottom = merge(a, b.bottom);
        }

        // next pointer is ignored in final flattened list
        result.next = null;
        return result;
    }

    public Node flatten(Node root) {

        // Base case
        if (root == null || root.next == null) {
            return root;
        }

        // Step 1: Flatten the list to the right
        root.next = flatten(root.next);

        // Step 2: Merge current list with flattened right list
        root = merge(root, root.next);

        return root;
    }
}
