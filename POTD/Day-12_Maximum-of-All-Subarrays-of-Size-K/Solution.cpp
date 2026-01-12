class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Deque / Monotonic Queue)
    // =====================================================
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {

        Deque<Integer> dq = new ArrayDeque<>();
        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {

            // Remove out-of-window indices
            if (!dq.isEmpty() && dq.peekFirst() <= i - k)
                dq.pollFirst();

            // Remove smaller elements
            while (!dq.isEmpty() && arr[dq.peekLast()] < arr[i])
                dq.pollLast();

            dq.offerLast(i);

            // Window complete
            if (i >= k - 1)
                result.add(arr[dq.peekFirst()]);
        }

        return result;
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Time: O(n*k)
- ❌ Too slow

---------------------------------------------------------------

2️⃣ Priority Queue (Max Heap)
- Time: O(n log k)
- Space: O(k)
- ❌ Not optimal

---------------------------------------------------------------

3️⃣ Segment Tree
- Range maximum query
- ❌ Heavy and unnecessary

---------------------------------------------------------------

4️⃣ Preprocessing / Block Technique
- leftMax[] and rightMax[]
- Time: O(n)
- Space: O(n)

---------------------------------------------------------------

5️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        Solution sol = new Solution();
        System.out.println(sol.maxOfSubarrays(arr, k));
    }
}

===================================================================
*/
