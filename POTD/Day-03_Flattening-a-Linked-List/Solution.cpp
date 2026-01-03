/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  private:
    // Helper function to merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        // If one list is empty, return the other
        if (a == NULL) return b;
        if (b == NULL) return a;

        Node* result = NULL;

        // Choose smaller node and recurse
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        // next pointer is not used in final list
        result->next = NULL;
        return result;
    }

  public:
    Node *flatten(Node *root) {
        // Base case: empty list or single column
        if (root == NULL || root->next == NULL) {
            return root;
        }

        // Step 1: Recursively flatten the list on the right
        root->next = flatten(root->next);

        // Step 2: Merge current list with flattened right list
        root = merge(root, root->next);

        return root;
    }
};
