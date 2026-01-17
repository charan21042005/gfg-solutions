class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Stack + Frequency Map)
    // =====================================================
    vector<int> nextFreqGreater(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> freq;

        // Frequency count
        for (int x : arr)
            freq[x]++;

        vector<int> ans(n, -1);
        stack<int> st;  // stores elements (not indices)

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements with <= frequency
            while (!st.empty() && freq[st.top()] <= freq[arr[i]])
                st.pop();

            if (!st.empty())
                ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- For each element, scan right side
- Compare frequencies
- Time: O(n^2)
- ❌ Too slow

---------------------------------------------------------------

2️⃣ Using Index Stack (Variation)
- Same logic, store indices instead of values
- Slightly more complex, same complexity

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 1, 3, 2, 1};
    Solution sol;
    vector<int> res = sol.nextFreqGreater(arr);

    for (int x : res)
        cout << x << " ";

    return 0;
}

===================================================================
*/
