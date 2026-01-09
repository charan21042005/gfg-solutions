class Solution {
  public:
    // ✅ OPTIMAL APPROACH (Sliding Window + Hash Map)
    int countAtMostK(vector<int> &arr, int k) {

        if (k == 0) return 0;

        unordered_map<int, int> freq;
        int left = 0;
        int count = 0;

        // Expand window using right pointer
        for (int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;

            // Shrink window until distinct elements <= k
            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }

            // All subarrays ending at 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }
};

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force (Using Set)
- For every subarray, count distinct elements
- Time: O(n^2)
- Space: O(n)

int countAtMostK(vector<int> &arr, int k) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        unordered_set<int> s;
        for (int j = i; j < arr.size(); j++) {
            s.insert(arr[j]);
            if (s.size() <= k) ans++;
            else break;
        }
    }
    return ans;
}

2️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    Solution sol;
    cout << sol.countAtMostK(arr, k);
    return 0;
}
*/
