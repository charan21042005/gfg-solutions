class Solution {
  public:
    // ✅ OPTIMAL APPROACH (Sliding Window)
    int maxSubarraySum(vector<int>& arr, int k) {

        int windowSum = 0;
        int maxSum = 0;

        // Step 1: Calculate sum of first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        maxSum = windowSum;

        // Step 2: Slide the window
        for (int i = k; i < arr.size(); i++) {
            windowSum = windowSum + arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force
- For every index, calculate sum of next k elements
- Time: O(n * k)
- Space: O(1)

int maxSubarraySum(vector<int>& arr, int k) {
    int maxSum = INT_MIN;
    for (int i = 0; i <= arr.size() - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

2️⃣ Full Standalone Runnable Version (Beginner Style)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {100, 200, 300, 400};
    int k = 2;
    // call maxSubarraySum(arr, k)
    return 0;
}
*/
