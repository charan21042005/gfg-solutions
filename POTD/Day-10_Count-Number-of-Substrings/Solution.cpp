class Solution {
  public:
    // =====================================================
    // Helper Function:
    // Counts number of substrings with AT MOST k distinct characters
    // Uses Sliding Window + Frequency Array (Optimized for GFG)
    // =====================================================
    int atMostK(string &s, int k) {
        if (k < 0) return 0;

        int freq[26] = {0};     // frequency of characters a-z
        int left = 0;           // left pointer of window
        int distinct = 0;       // number of distinct characters
        long long count = 0;    // total valid substrings

        for (int right = 0; right < s.length(); right++) {

            // Add current character
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            // Shrink window if distinct characters exceed k
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            // All substrings ending at 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }

    // =====================================================
    // ✅ OPTIMAL APPROACH (MAIN GFG SOLUTION)
    // Exactly K distinct =
    //     substrings with at most K distinct
    //   - substrings with at most (K - 1) distinct
    // =====================================================
    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Direct Sliding Window (Only for 'a', 'b', 'c' type problems)

Idea:
- Maintain frequency of 'a', 'b', 'c'
- Once all are present, count (n - right)
- Used in problems like:
  "Count Substrings containing a, b and c"

Time: O(n)
Space: O(1)

-------------------------------------------------------------------

2️⃣ Brute Force (Not Recommended)

Idea:
- Generate all substrings
- Count distinct characters using set

Time: O(n^2)
Space: O(n)

Pseudo:
for i in range(n):
    set.clear()
    for j in range(i, n):
        insert s[j]
        if set.size == k:
            count++

-------------------------------------------------------------------

3️⃣ Using unordered_map (Works but TLE on GFG)

Reason for TLE:
- Hashing overhead
- Poor performance on large inputs

Better alternative:
- Use fixed-size array when characters are limited (a-z)

-------------------------------------------------------------------

4️⃣ Full Standalone Runnable Version (For Local Testing)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcabc";
    int k = 3;
    Solution sol;
    cout << sol.countSubstr(s, k);
    return 0;
}

====================================================================
*/
