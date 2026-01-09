class Solution {

    // ✅ OPTIMAL APPROACH (Sliding Window + HashMap)
    public int countAtMostK(int arr[], int k) {

        if (k == 0) return 0;

        HashMap<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        int count = 0;

        // Expand window
        for (int right = 0; right < arr.length; right++) {
            freq.put(arr[right], freq.getOrDefault(arr[right], 0) + 1);

            // Shrink window if distinct count exceeds k
            while (freq.size() > k) {
                freq.put(arr[left], freq.get(arr[left]) - 1);
                if (freq.get(arr[left]) == 0) {
                    freq.remove(arr[left]);
                }
                left++;
            }

            // Count valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
}

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force using HashSet
- Nested loops
- Time: O(n^2)
- Space: O(n)

2️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 2, 3};
        int k = 2;
        Solution sol = new Solution();
        System.out.println(sol.countAtMostK(arr, k));
    }
}
*/
