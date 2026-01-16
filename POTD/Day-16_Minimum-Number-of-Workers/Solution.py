class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Greedy Interval Coverage)
    # =====================================================
    def minMen(self, arr):

        n = len(arr)
        intervals = []

        # Build intervals
        for i in range(n):
            if arr[i] != -1:
                L = max(0, i - arr[i])
                R = min(n - 1, i + arr[i])
                intervals.append((L, R))

        # Sort by start
        intervals.sort()

        count = 0
        i = 0
        current_end = 0
        max_reach = 0

        # Greedy coverage
        while current_end <= n - 1:
            found = False

            while i < len(intervals) and intervals[i][0] <= current_end:
                max_reach = max(max_reach, intervals[i][1])
                i += 1
                found = True

            if not found:
                return -1

            count += 1
            current_end = max_reach + 1

        return count


'''
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Try all worker combinations
- Exponential time
- ❌ Not feasible

---------------------------------------------------------------

2️⃣ Dynamic Programming
- Higher space & time
- ❌ Overkill

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1, 2, 1, 0]
    sol = Solution()
    print(sol.minMen(arr))

===================================================================
'''
