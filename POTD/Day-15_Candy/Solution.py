class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Two-Pass Greedy)
    # =====================================================
    def minCandy(self, arr):

        n = len(arr)
        candies = [1] * n

        # Left to Right pass
        for i in range(1, n):
            if arr[i] > arr[i - 1]:
                candies[i] = candies[i - 1] + 1

        # Right to Left pass
        for i in range(n - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)

        return sum(candies)


'''
========================= OTHER APPROACHES =========================

1️⃣ One-Pass Greedy
- Breaks right neighbor condition
- ❌ Incorrect

---------------------------------------------------------------

2️⃣ Brute Force
- Try all distributions
- Exponential time
- ❌ Not usable

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1, 0, 2]
    sol = Solution()
    print(sol.minCandy(arr))

===================================================================
'''
