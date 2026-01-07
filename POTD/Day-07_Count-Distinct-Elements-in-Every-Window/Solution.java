class Solution {

    // ✅ OPTIMAL APPROACH (Sliding Window + HashMap)
    ArrayList<Integer> countDistinct(int arr[], int k) {

        HashMap<Integer, Integer> freq = new HashMap<>();
        ArrayList<Integer> result = new ArrayList<>();

        // Step 1: First window
        for (int i = 0; i < k; i++) {
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
        }
        result.add(freq.size());

        // Step 2: Slide the window
        for (int i = k; i < arr.length; i++) {

            // Remove outgoing element
            freq.put(arr[i - k], freq.get(arr[i - k]) - 1);
            if (freq.get(arr[i - k]) == 0) {
                freq.remove(arr[i - k]);
            }

            // Add incoming element
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);

            result.add(freq.size());
        }

        return result;
    }
}

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force using HashSet
- For every window, insert elements into HashSet
- Time: O(n * k)
- Space: O(k)

2️⃣ TreeMap Approach
- Same logic as HashMap
- Time: O(n log k)

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 3, 4, 2, 3};
        int k = 4;
        Solution sol = new Solution();
        System.out.println(sol.countDistinct(arr, k));
    }
}
*/
