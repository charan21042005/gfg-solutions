class Solution:

    # ✅ OPTIMAL APPROACH (Prefix Sum + Dictionary)
    def countSubarrays(self, arr, k):

        freq = {0: 1}     # base case
        prefix_odd = 0
        count = 0

        for num in arr:

            if num % 2 == 1:
                prefix_odd += 1

            if prefix_odd - k in freq:
                count += freq[prefix_odd - k]

            freq[prefix_odd] = freq.get(prefix_odd, 0) + 1

        return count


'''
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Sliding Window (At Most K Odds)

def countAtMost(arr, k):
    left = 0
    odd_count = 0
    res = 0

    for right in range(len(arr)):
        if arr[right] % 2 == 1:
            odd_count += 1

        while odd_count > k:
            if arr[left] % 2 == 1:
                odd_count -= 1
            left += 1

        res += (right - left + 1)

    return res

Answer = countAtMost(arr, k) - countAtMost(arr, k-1)

2️⃣ Brute Force
- Check every subarray
- Time: O(n^2)

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1, 1, 2, 1, 1]
    k = 3
    sol = Solution()
    print(sol.countSubarrays(arr, k))
'''
