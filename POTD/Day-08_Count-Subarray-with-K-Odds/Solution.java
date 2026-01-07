class Solution {

    // ✅ OPTIMAL APPROACH (Prefix Sum + HashMap)
    public int countSubarrays(int[] arr, int k) {

        HashMap<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);   // base case

        int prefixOddCount = 0;
        int count = 0;

        for (int num : arr) {

            if (num % 2 == 1) {
                prefixOddCount++;
            }

            if (freq.containsKey(prefixOddCount - k)) {
                count += freq.get(prefixOddCount - k);
            }

            freq.put(prefixOddCount, freq.getOrDefault(prefixOddCount, 0) + 1);
        }

        return count;
    }
}

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Sliding Window (At Most K Odds)
- countAtMost(k) - countAtMost(k-1)
- Time: O(n)

2️⃣ Brute Force
- Two loops
- Time: O(n^2)

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1, 1, 2, 1, 1};
        int k = 3;
        Solution sol = new Solution();
        System.out.println(sol.countSubarrays(arr, k));
    }
}
*/
