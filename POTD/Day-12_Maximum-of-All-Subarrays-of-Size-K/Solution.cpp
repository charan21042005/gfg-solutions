class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Deque / Monotonic Queue)
    // Time: O(n), Space: O(k)
    // =====================================================
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {

        deque<int> dq;              // stores indices
        vector<int> result;

        for (int i = 0; i < arr.size(); i++) {

            // Remove indices out of current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from back
            while (!dq.empty() && arr[dq.back()] < arr[i])
                dq.pop_back();

            dq.push_back(i);

            // Window ready
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }

        return result;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- For every window, scan k elements
- Time: O(n*k)
- Space: O(1)
- ❌ TLE on large inputs

---------------------------------------------------------------

2️⃣ Priority Queue (Max Heap)
- Store (value, index)
- Remove outdated elements
- Time: O(n log k)
- Space: O(k)
- ❌ Slower than deque

---------------------------------------------------------------

3️⃣ Segment Tree
- Range maximum query
- Build: O(n)
- Query: O(log n)
- ❌ Overkill for this problem

---------------------------------------------------------------

4️⃣ Preprocessing (Block Method)
- Divide array into blocks of size k
- Use leftMax[] and rightMax[]
- Time: O(n)
- Space: O(n)
- ✔️ Valid alternative

---------------------------------------------------------------

5️⃣ Full Standalone Runnable Version

#include <iostream>
using namespace std;

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> ans = sol.maxOfSubarrays(arr, k);
    for (int x : ans) cout << x << " ";
    return 0;
}

===================================================================
*/
