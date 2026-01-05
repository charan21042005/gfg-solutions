class Solution {

    // ✅ OPTIMAL APPROACH (Sliding Window)
    public int maxSubarraySum(int[] arr, int k) {

        int windowSum = 0;
        int maxSum;

        // Step 1: Sum of first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        maxSum = windowSum;

        // Step 2: Slide the window
        for (int i = k; i < arr.length; i++) {
            windowSum = windowSum + arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }
}

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force Approach
- Nested loops
- Time: O(n * k)
- Space: O(1)

2️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {100, 200, 300, 400};
        int k = 2;
        Solution sol = new Solution();
        System.out.println(sol.maxSubarraySum(arr, k));
    }
}
*/
