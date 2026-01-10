class Solution {

    // =====================================================
    // Helper Function:
    // Counts substrings with AT MOST k distinct characters
    // Optimized using fixed-size frequency array (a-z)
    // Sliding Window Technique
    // =====================================================
    private int atMostK(String s, int k) {
        if (k < 0) return 0;

        int[] freq = new int[26];   // frequency of characters a-z
        int left = 0;
        int distinct = 0;
        int count = 0;

        for (int right = 0; right < s.length(); right++) {

            int idx = s.charAt(right) - 'a';

            // Add incoming character
            if (freq[idx] == 0)
                distinct++;
            freq[idx]++;

            // Shrink window if distinct characters exceed k
            while (distinct > k) {
                int leftIdx = s.charAt(left) - 'a';
                freq[leftIdx]--;
                if (freq[leftIdx] == 0)
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
    public int countSubstr(String s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Using HashMap (Works but Slower on GFG)

- Same sliding window logic
- Uses HashMap<Character, Integer>
- More overhead compared to array
- Might TLE for large inputs on GFG

---------------------------------------------------------------

2️⃣ Direct Sliding Window (Only for 'a', 'b', 'c' type problems)

- Track frequency of only 'a', 'b', 'c'
- When all present → add (n - right)
- Used in problems like:
  "Count Substrings containing a, b and c"

Time: O(n)
Space: O(1)

---------------------------------------------------------------

3️⃣ Brute Force (Not Recommended)

Idea:
- Generate all substrings
- Count distinct characters using HashSet

Time: O(n^2)
Space: O(n)

---------------------------------------------------------------

4️⃣ Full Standalone Runnable Version (For Local Testing)

class Main {
    public static void main(String[] args) {
        String s = "abcabc";
        int k = 3;
        Solution sol = new Solution();
        System.out.println(sol.countSubstr(s, k));
    }
}

===================================================================
*/
