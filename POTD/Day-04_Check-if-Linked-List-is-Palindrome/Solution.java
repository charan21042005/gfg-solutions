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

    // Helper method to reverse linked list
    private Node reverseList(Node head) {
        Node prev = null;
        Node curr = head;

        while (curr != null) {
            Node nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // ✅ OPTIMAL APPROACH
    public boolean isPalindrome(Node head) {

        // Edge cases
        if (head == null || head.next == null)
            return true;

        // Step 1: Find middle
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Reverse second half
        Node secondHalf = reverseList(slow);

        // Step 3: Compare halves
        Node firstHalf = head;
        Node temp = secondHalf;

        while (temp != null) {
            if (firstHalf.data != temp.data)
                return false;

            firstHalf = firstHalf.next;
            temp = temp.next;
        }

        return true;
    }
}

/*
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Using ArrayList
- Store all values
- Two-pointer palindrome check

2️⃣ Stack Based
- Push first half
- Compare second half

(All above use extra space O(n))
*/
