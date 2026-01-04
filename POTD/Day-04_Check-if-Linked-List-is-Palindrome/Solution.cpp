/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  private:
    // Helper function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

  public:
    // ✅ OPTIMAL APPROACH (O(n) time, O(1) space)
    bool isPalindrome(Node *head) {

        // Edge cases
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle using slow & fast pointers
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* secondHalf = reverseList(slow);

        // Step 3: Compare both halves
        Node* firstHalf = head;
        Node* temp = secondHalf;

        while (temp != NULL) {
            if (firstHalf->data != temp->data)
                return false;

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force (Using Array)
- Traverse list, store values in array
- Check if array is palindrome
- Time: O(n)
- Space: O(n)

2️⃣ Stack Method
- Push first half into stack
- Compare with second half
- Time: O(n)
- Space: O(n)

3️⃣ Full Standalone Version (Beginner Style)

#include <iostream>
using namespace std;

int main() {
    // build linked list manually
    // call isPalindrome()
    return 0;
}
*/
