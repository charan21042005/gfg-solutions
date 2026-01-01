/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // Step 1: Calculate length of first linked list
        int len1 = 0;
        Node* temp1 = head1;
        while (temp1 != NULL) {
            len1++;
            temp1 = temp1->next;
        }

        // Step 2: Calculate length of second linked list
        int len2 = 0;
        Node* temp2 = head2;
        while (temp2 != NULL) {
            len2++;
            temp2 = temp2->next;
        }

        // Step 3: Find difference in lengths
        int diff = abs(len1 - len2);

        // Step 4: Move pointer of longer list ahead by diff
        temp1 = head1;
        temp2 = head2;

        if (len1 > len2) {
            while (diff--) {
                temp1 = temp1->next;
            }
        } else {
            while (diff--) {
                temp2 = temp2->next;
            }
        }

        // Step 5: Traverse both lists together
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 == temp2) {
                return temp1;   // intersection node found
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Step 6: No intersection
        return NULL;
    }
};
