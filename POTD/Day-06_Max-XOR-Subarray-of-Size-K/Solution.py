class Solution:

    # ✅ OPTIMAL APPROACH (Sliding Window + XOR)
    def maxSubarrayXOR(self, arr, k):

        # Step 1: XOR of first window
        current_xor = 0
        for i in range(k):
            current_xor ^= arr[i]

        max_xor = current_xor

        # Step 2: Slide the window
        for i in range(k, len(arr)):
            current_xor ^= arr[i - k]   # remove outgoing element
            current_xor ^= arr[i]       # add incoming element
            max_xor = max(max_xor, current_xor)

        return max_xor


'''
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Brute Force
- Compute XOR for each window
- Time: O(n * k)
- Space: O(1)

def maxSubarrayXOR(arr, k):
    max_xor = 0
    for i in range(len(arr) - k + 1):
        curr = 0
        for j in range(i, i + k):
            curr ^= arr[j]
        max_xor = max(max_xor, curr)
    return max_xor

2️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1, 2, 3, 4]
    k = 2
    sol = Solution()
    print(sol.maxSubarrayXOR(arr, k))
'''
