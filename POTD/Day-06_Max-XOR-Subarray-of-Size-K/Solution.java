class Solution {

    // ✅ OPTIMAL APPROACH (Sliding Window + XOR)
    public int maxSubarrayXOR(int[] arr, int k) {

        int currentXor = 0;

        // Step 1: XOR of first window
        for (int i = 0; i < k; i++) {
            currentXor ^= arr[i];
        }

        int maxXor = currentXor;

        // Step 2: Slide the window
        for (int i = k; i < arr.length; i++) {
            currentXor ^= arr[i - k];   // remove outgoing element
            currentXor ^= arr[i];       // add incoming element
            maxXor = Math.max(maxXor, currentXor);
        }

        return maxXor;
    }
}

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force
- Nested loops
- Time: O(n * k)
- Space: O(1)

2️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
        int k = 2;
        Solution sol = new Solution();
        System.out.println(sol.maxSubarrayXOR(arr, k));
    }
}
*/
