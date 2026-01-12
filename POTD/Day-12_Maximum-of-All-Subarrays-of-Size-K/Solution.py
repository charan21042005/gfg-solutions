from collections import deque

class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Deque / Monotonic Queue)
    # =====================================================
    def maxOfSubarrays(self, arr, k):

        dq = deque()        # stores indices
        result = []

        for i in range(len(arr)):

            # Remove indices out of window
            if dq and dq[0] <= i - k:
                dq.popleft()

            # Remove smaller elements
            while dq and arr[dq[-1]] < arr[i]:
                dq.pop()

            dq.append(i)

            # Window complete
            if i >= k - 1:
                result.append(arr[dq[0]])

        return result


'''
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Time: O(n*k)
- ❌ Inefficient

---------------------------------------------------------------

2️⃣ Max Heap
- Use (-value, index)
- Time: O(n log k)
- ❌ Slower than deque

---------------------------------------------------------------

3️⃣ Segment Tree
- RMQ based
- ❌ Overkill

---------------------------------------------------------------

4️⃣ Block Decomposition (Optimized Alternative)
- Use leftMax[] and rightMax[]
- Time: O(n)
- Space: O(n)

---------------------------------------------------------------

5️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1,3,-1,-3,5,3,6,7]
    k = 3
    sol = Solution()
    print(sol.maxOfSubarrays(arr, k))

===================================================================
'''
