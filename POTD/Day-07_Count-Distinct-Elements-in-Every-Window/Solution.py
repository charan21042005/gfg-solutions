class Solution:

    # ✅ OPTIMAL APPROACH (Sliding Window + Dictionary)
    def countDistinct(self, arr, k):

        freq = {}
        result = []

        # Step 1: First window
        for i in range(k):
            freq[arr[i]] = freq.get(arr[i], 0) + 1

        result.append(len(freq))

        # Step 2: Slide the window
        for i in range(k, len(arr)):

            # Remove outgoing element
            freq[arr[i - k]] -= 1
            if freq[arr[i - k]] == 0:
                del freq[arr[i - k]]

            # Add incoming element
            freq[arr[i]] = freq.get(arr[i], 0) + 1

            result.append(len(freq))

        return result


'''
============ OTHER APPROACHES (COMMENTED) ============

1️⃣ Brute Force (Using Set)
- For each window, create a set
- Time: O(n * k)
- Space: O(k)

def countDistinct(arr, k):
    ans = []
    for i in range(len(arr) - k + 1):
        s = set(arr[i:i+k])
        ans.append(len(s))
    return ans

2️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = [1, 2, 1, 3, 4, 2, 3]
    k = 4
    sol = Solution()
    print(sol.countDistinct(arr, k))
'''
