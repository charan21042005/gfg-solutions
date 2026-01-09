class Solution:

    # ✅ OPTIMAL APPROACH (Sliding Window + Dictionary)
    def countAtMostK(self, arr, k):

        if k == 0:
            return 0

        freq = {}
        left = 0
        count = 0

        # Expand window using right pointer
        for right in range(len(arr)):
            freq[arr[right]] = freq.get(arr[right], 0) + 1

            # Shrink window until distinct elements <= k
            while len(freq) > k:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                left += 1

            # All subarrays ending at 'right' are valid
            count += (right - left + 1)

        return count


'''
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Brute Force
- Count distinct elements for every subarray
- Time: O(n^2)
- Space: O(n)

def countAtMostK(arr, k):
    ans = 0
    for i in range(len(arr)):
        s = set()
        for j in range(i, len(arr)):
            s.add(arr[j])
            if len(s) <= k:
                ans += 1
            else:
                break
    return ans

2️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1, 2, 1, 2, 3]
    k = 2
    sol = Solution()
    print(sol.countAtMostK(arr, k))
'''
