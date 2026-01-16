class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Greedy Interval Coverage)
    // =====================================================
    public int minMen(int arr[]) {

        int n = arr.length;
        ArrayList<int[]> intervals = new ArrayList<>();

        // Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = Math.max(0, i - arr[i]);
                int R = Math.min(n - 1, i + arr[i]);
                intervals.add(new int[]{L, R});
            }
        }

        // Sort by start
        intervals.sort((a, b) -> a[0] - b[0]);

        int count = 0;
        int i = 0;
        int currentEnd = 0;
        int maxReach = 0;

        // Greedy coverage
        while (currentEnd <= n - 1) {
            boolean found = false;

            while (i < intervals.size() && intervals.get(i)[0] <= currentEnd) {
                maxReach = Math.max(maxReach, intervals.get(i)[1]);
                i++;
                found = true;
            }

            if (!found) return -1;

            count++;
            currentEnd = maxReach + 1;
        }

        return count;
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Exponential
- ❌ Not practical

---------------------------------------------------------------

2️⃣ DP
- Higher space usage
- ❌ Overkill

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 0};
        Solution sol = new Solution();
        System.out.println(sol.minMen(arr));
    }
}

===================================================================
*/
