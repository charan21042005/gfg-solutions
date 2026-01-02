class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0;                 // boundary for 0s
        int mid = 0;                 // current element
        int high = arr.size() - 1;   // boundary for 2s

        // Traverse the array until mid crosses high
        while (mid <= high) {

            // Case 1: current element is 0
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;      // move boundary of 0s
                mid++;      // move to next element
            }

            // Case 2: current element is 1
            else if (arr[mid] == 1) {
                mid++;      // 1 is already in correct region
            }

            // Case 3: current element is 2
            else {
                swap(arr[mid], arr[high]);
                high--;     // move boundary of 2s
                // mid is NOT incremented here
            }
        }
    }
};
