class Solution {
  public:
    // ✅ OPTIMAL APPROACH (Prefix Sum + Hash Map)
    int countSubarrays(vector<int>& arr, int k) {

        unordered_map<int, int> freq;
        freq[0] = 1;          // base case

        int prefixOddCount = 0;
        int count = 0;

        for (int num : arr) {
            // Treat odd as 1, even as 0
            if (num % 2 == 1) {
                prefixOddCount++;
            }

            // Check if prefixOddCount - k exists
            if (freq.find(prefixOddCount - k) != freq.end()) {
                count += freq[prefixOddCount - k];
            }

            freq[prefixOddCount]++;
        }

        return count;
    }
};

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Sliding Window (At Most K Odds Trick)
- Exactly K = AtMost(K) - AtMost(K-1)
- Time: O(n)
- Space: O(1)

2️⃣ Brute Force
- Count odds for every subarray
- Time: O(n^2)
- Space: O(1)

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;
    Solution sol;
    cout << sol.countSubarrays(arr, k);
    return 0;
}
*/
