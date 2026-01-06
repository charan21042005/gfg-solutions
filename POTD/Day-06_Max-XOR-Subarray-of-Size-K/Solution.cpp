class Solution {
  public:
    // ✅ OPTIMAL APPROACH (Sliding Window + XOR)
    int maxSubarrayXOR(vector<int>& arr, int k) {

        int currentXor = 0;

        // Step 1: XOR of first window
        for (int i = 0; i < k; i++) {
            currentXor ^= arr[i];
        }

        int maxXor = currentXor;

        // Step 2: Slide the window
        for (int i = k; i < arr.size(); i++) {
            currentXor ^= arr[i - k];   // remove outgoing element
            currentXor ^= arr[i];       // add incoming element
            maxXor = max(maxXor, currentXor);
        }

        return maxXor;
    }
};

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force
- For each index, compute XOR of next k elements
- Time: O(n * k)
- Space: O(1)

int maxSubarrayXOR(vector<int>& arr, int k) {
    int maxXor = 0;
    for (int i = 0; i <= arr.size() - k; i++) {
        int currXor = 0;
        for (int j = i; j < i + k; j++) {
            currXor ^= arr[j];
        }
        maxXor = max(maxXor, currXor);
    }
    return maxXor;
}

2️⃣ Full Standalone Runnable Version (Beginner Style)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    Solution sol;
    cout << sol.maxSubarrayXOR(arr, k);
    return 0;
}
*/
