/*
class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}
*/

class Solution {
    public Node intersectPoint(Node head1, Node head2) {

        // Step 1: Find length of first list
        int len1 = 0;
        Node temp1 = head1;
        while (temp1 != null) {
            len1++;
            temp1 = temp1.next;
        }

        // Step 2: Find length of second list
        int len2 = 0;
        Node temp2 = head2;
        while (temp2 != null) {
            len2++;
            temp2 = temp2.next;
        }

        // Step 3: Calculate difference
        int diff = Math.abs(len1 - len2);

        // Step 4: Move pointer of longer list
        temp1 = head1;
        temp2 = head2;

        if (len1 > len2) {
            while (diff-- > 0) {
                temp1 = temp1.next;
            }
        } else {
            while (diff-- > 0) {
                temp2 = temp2.next;
            }
        }

        // Step 5: Traverse together to find intersection
        while (temp1 != null && temp2 != null) {
            if (temp1 == temp2) {
                return temp1;   // intersection found
            }
            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        // Step 6: No intersection
        return null;
    }
}
