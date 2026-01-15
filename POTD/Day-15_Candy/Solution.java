class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Two-Pass Greedy)
    // =====================================================
    public int minCandy(int arr[]) {

        int n = arr.length;
        int[] candies = new int[n];

        // Initialize with 1 candy each
        Arrays.fill(candies, 1);

        // Left to Right pass
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to Left pass
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum all candies
        int total = 0;
        for (int c : candies) total += c;

        return total;
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ One-Pass Greedy
- Ignores right neighbor
- ❌ Incorrect

---------------------------------------------------------------

2️⃣ Brute Force
- Exponential
- ❌ Impossible for large n

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1, 0, 2};
        Solution sol = new Solution();
        System.out.println(sol.minCandy(arr));
    }
}

===================================================================
*/
