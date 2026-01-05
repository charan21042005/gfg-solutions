class Solution:

    # ✅ OPTIMAL APPROACH (Sliding Window)
    def maxSubarraySum(self, arr, k):

        # Step 1: Sum of first window
        window_sum = sum(arr[:k])
        max_sum = window_sum

        # Step 2: Slide the window
        for i in range(k, len(arr)):
            window_sum = window_sum + arr[i] - arr[i - k]
            max_sum = max(max_sum, window_sum)

        return max_sum


'''
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Brute Force
- For each index, sum k elements
- Time: O(n * k)
- Space: O(1)

def maxSubarraySum(arr, k):
    max_sum = float('-inf')
    for i in range(len(arr) - k + 1):
        curr_sum = 0
        for j in range(i, i + k):
            curr_sum += arr[j]
        max_sum = max(max_sum, curr_sum)
    return max_sum

2️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [100, 200, 300, 400]
    k = 2
    sol = Solution()
    print(sol.maxSubarraySum(arr, k))
'''
