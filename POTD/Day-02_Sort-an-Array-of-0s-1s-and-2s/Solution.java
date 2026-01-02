class Solution {
    public void sort012(int[] arr) {

        int low = 0;                 // boundary for 0s
        int mid = 0;                 // current index
        int high = arr.length - 1;   // boundary for 2s

        // Continue until mid pointer crosses high
        while (mid <= high) {

            // Case 1: element is 0
            if (arr[mid] == 0) {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;

                low++;      // move 0s boundary
                mid++;      // move forward
            }

            // Case 2: element is 1
            else if (arr[mid] == 1) {
                mid++;      // correct place, just move ahead
            }

            // Case 3: element is 2
            else {
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;

                high--;     // shrink 2s region
                // do NOT increment mid here
            }
        }
    }
}
