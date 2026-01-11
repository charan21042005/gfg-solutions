class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Dynamic Programming)
    # dp[i][j] = starting index in s1 where
    #            s2[0..j] ends at s1[i]
    # =====================================================
    def minWindow(self, s1, s2):

        n, m = len(s1), len(s2)
        dp = [[-1] * m for _ in range(n)]

        # Base case
        for i in range(n):
            if s1[i] == s2[0]:
                dp[i][0] = i

        # Fill DP table
        for j in range(1, m):
            prev = -1
            for i in range(n):
                if prev != -1 and s1[i] == s2[j]:
                    dp[i][j] = prev
                if dp[i][j - 1] != -1:
                    prev = dp[i][j - 1]

        min_len = float('inf')
        start = -1

        for i in range(n):
            if dp[i][m - 1] != -1:
                length = i - dp[i][m - 1] + 1
                if length < min_len:
                    min_len = length
                    start = dp[i][m - 1]

        return "" if start == -1 else s1[start:start + min_len]


'''
========================= OTHER APPROACHES =========================

1️⃣ Greedy Two-Pointer
- Common online
- Fails for overlapping subsequences on GFG ❌

2️⃣ Brute Force
- Generate all substrings
- Check subsequence
- Time: O(n^3)

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    s1 = "geeksforgeeks"
    s2 = "eksrg"
    sol = Solution()
    print(sol.minWindow(s1, s2))

===================================================================
'''
