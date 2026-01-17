class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Stack + Frequency Map)
    # =====================================================
    def nextFreqGreater(self, arr):

        from collections import Counter

        n = len(arr)
        freq = Counter(arr)
        ans = [-1] * n
        stack = []

        # Traverse from right to left
        for i in range(n - 1, -1, -1):

            while stack and freq[stack[-1]] <= freq[arr[i]]:
                stack.pop()

            if stack:
                ans[i] = stack[-1]

            stack.append(arr[i])

        return ans


'''
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Two nested loops
- Compare frequencies
- ❌ O(n^2)

---------------------------------------------------------------

2️⃣ Stack of Indices
- Same logic, index-based
- Slightly more complex

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [2, 1, 1, 3, 2, 1]
    sol = Solution()
    print(sol.nextFreqGreater(arr))

===================================================================
'''
