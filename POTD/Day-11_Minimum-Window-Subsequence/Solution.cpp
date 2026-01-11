class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Dynamic Programming)
    // dp[i][j] = starting index in s1 where
    //            s2[0..j] ends at s1[i]
    // =====================================================
    string minWindow(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Base case: matching first character of s2
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[0])
                dp[i][0] = i;
        }

        // Fill DP table
        for (int j = 1; j < m; j++) {
            int prev = -1;
            for (int i = 0; i < n; i++) {
                if (prev != -1 && s1[i] == s2[j])
                    dp[i][j] = prev;
                if (dp[i][j - 1] != -1)
                    prev = dp[i][j - 1];
            }
        }

        // Find minimum window
        int minLen = INT_MAX;
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

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Greedy Two-Pointer (Forward + Backward)
- Often shown online
- FAILS for overlapping subsequences
- Example:
  s1 = "geeksforgeeks"
  s2 = "eksrg"
- Produces wrong output on GFG ❌

2️⃣ Brute Force
- Check all substrings
- Verify subsequence
- Time: O(n^3)
- Not acceptable

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
using namespace std;

int main() {
    string s1 = "geeksforgeeks";
    string s2 = "eksrg";
    Solution sol;
    cout << sol.minWindow(s1, s2);
    return 0;
}

===================================================================
*/
