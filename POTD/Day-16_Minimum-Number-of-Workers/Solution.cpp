class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Greedy Interval Coverage)
    // =====================================================
    int minMen(vector<int>& arr) {

        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }

        // Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int i = 0;
        int currentEnd = 0;
        int maxReach = 0;

        // Greedy coverage
        while (currentEnd <= n - 1) {
            bool found = false;

            while (i < intervals.size() && intervals[i].first <= currentEnd) {
                maxReach = max(maxReach, intervals[i].second);
                i++;
                found = true;
            }

            if (!found) return -1;

            count++;
            currentEnd = maxReach + 1;
        }

        return count;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Try all combinations of workers
- Exponential time
- ❌ Not feasible

---------------------------------------------------------------

2️⃣ Dynamic Programming
- Track minimum workers for each time
- Higher space and time
- ❌ Overkill

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 1, 0};
    Solution sol;
    cout << sol.minMen(arr);
    return 0;
}

===================================================================
*/
