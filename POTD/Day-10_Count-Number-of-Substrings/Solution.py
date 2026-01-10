class Solution:

    # =====================================================
    # Helper Function:
    # Counts number of substrings with AT MOST k distinct characters
    # Uses Sliding Window + Frequency Dictionary
    # =====================================================
    def atMostK(self, s, k):
        if k < 0:
            return 0

        freq = {}          # frequency of characters in current window
        left = 0           # left pointer of window
        count = 0          # total valid substrings

        for right in range(len(s)):

            # Add incoming character
            freq[s[right]] = freq.get(s[right], 0) + 1

            # Shrink window if distinct characters exceed k
            while len(freq) > k:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    del freq[s[left]]
                left += 1

            # All substrings ending at 'right' are valid
            count += (right - left + 1)

        return count

    # =====================================================
    # ✅ OPTIMAL APPROACH (MAIN GFG SOLUTION)
    # Exactly K distinct =
    #     substrings with at most K distinct
    #   - substrings with at most (K - 1) distinct
    # =====================================================
    def countSubstr(self, s, k):
        return self.atMostK(s, k) - self.atMostK(s, k - 1)


'''
========================= OTHER APPROACHES =========================

1️⃣ Direct Sliding Window (Special Case: 'a', 'b', 'c')

- Track frequency of 'a', 'b', 'c'
- When all three present:
    count += (n - right)
- Used in:
  "Count Substrings containing a, b and c"

Time: O(n)
Space: O(1)

-------------------------------------------------------------------

2️⃣ Brute Force (Not Recommended)

Idea:
- Generate all substrings
- Use set to count distinct characters

Time: O(n^2)
Space: O(n)

-------------------------------------------------------------------

3️⃣ Prefix Sum + Hashing (Alternative Thinking)

- Convert problem into prefix count of distinct characters
- Less intuitive than sliding window
- Generally not preferred in interviews

-------------------------------------------------------------------

4️⃣ Full Standalone Runnable Version (For Local Testing)

if __name__ == "__main__":
    s = "abcabc"
    k = 3
    sol = Solution()
    print(sol.countSubstr(s, k))

===================================================================
'''
