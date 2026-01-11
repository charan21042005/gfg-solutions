class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Dynamic Programming)
    // dp[i][j] = starting index in s1 where
    //            s2[0..j] ends at s1[i]
    // =====================================================
    public String minWindow(String s1, String s2) {

        int n = s1.length(), m = s2.length();
        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);

        // Base case
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == s2.charAt(0))
                dp[i][0] = i;
        }

        // Fill DP table
        for (int j = 1; j < m; j++) {
            int prev = -1;
            for (int i = 0; i < n; i++) {
                if (prev != -1 && s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = prev;
                if (dp[i][j - 1] != -1)
                    prev = dp[i][j - 1];
            }
        }

        int minLen = Integer.MAX_VALUE;
        int start = -1;

        for (int i = 0; i < n; i++) {
            if (dp[i][m - 1] != -1) {
                int len = i - dp[i][m - 1] + 1;
                if (len < minLen) {
                    minLen = len;
                    start = dp[i][m - 1];
                }
            }
        }

        return start == -1 ? "" : s1.substring(start, start + minLen);
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Greedy Two-Pointer
- Forward scan + backward shrink
- Incorrect for overlapping subsequences on GFG ❌

2️⃣ Brute Force
- Time: O(n^3)

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        String s1 = "geeksforgeeks";
        String s2 = "eksrg";
        Solution sol = new Solution();
        System.out.println(sol.minWindow(s1, s2));
    }
}

===================================================================
*/
