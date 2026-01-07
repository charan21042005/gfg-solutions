class Solution {
  public:
    // ✅ OPTIMAL APPROACH (Sliding Window + Hash Map)
    vector<int> countDistinct(vector<int> &arr, int k) {

        unordered_map<int, int> freq;
        vector<int> result;

        // Step 1: Process first window
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        result.push_back(freq.size());

        // Step 2: Slide the window
        for (int i = k; i < arr.size(); i++) {

            // Remove outgoing element
            freq[arr[i - k]]--;
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }

            // Add incoming element
            freq[arr[i]]++;

            result.push_back(freq.size());
        }

        return result;
    }
};

/*
================ OTHER APPROACHES (COMMENTED) ================

1️⃣ Brute Force (Using Set for every window)
- For each window, insert k elements into a set
- Time: O(n * k)
- Space: O(k)

vector<int> countDistinct(vector<int> &arr, int k) {
    vector<int> ans;
    for (int i = 0; i <= arr.size() - k; i++) {
        unordered_set<int> s;
        for (int j = i; j < i + k; j++) {
            s.insert(arr[j]);
        }
        ans.push_back(s.size());
    }
    return ans;
}

2️⃣ Using Ordered Map (Same logic, slower)
- map instead of unordered_map
- Time: O(n log k)

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    Solution sol;
    vector<int> res = sol.countDistinct(arr, k);
    for (int x : res) cout << x << " ";
    return 0;
}
*/
