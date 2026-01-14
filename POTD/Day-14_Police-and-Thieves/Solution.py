class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Greedy + Two Pointers)
    # =====================================================
    def catchThieves(self, arr, k):

        police = []
        thieves = []

        # Store positions
        for i in range(len(arr)):
            if arr[i] == 'P':
                police.append(i)
            elif arr[i] == 'T':
                thieves.append(i)

        i = j = 0
        count = 0

        # Two-pointer greedy matching
        while i < len(police) and j < len(thieves):
            if abs(police[i] - thieves[j]) <= k:
                count += 1
                i += 1
                j += 1
            elif police[i] < thieves[j]:
                i += 1
            else:
                j += 1

        return count


'''
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Check all pairs
- Time: O(n^2)
- ❌ Inefficient

---------------------------------------------------------------

2️⃣ Sliding Window
- Hard to maintain correct matching
- ❌ Not clean

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    arr = ['P','T','T','P','T']
    k = 1
    sol = Solution()
    print(sol.catchThieves(arr, k))

===================================================================
'''
