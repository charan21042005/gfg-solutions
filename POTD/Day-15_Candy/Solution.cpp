class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Two-Pass Greedy)
    // =====================================================
    int minCandy(vector<int> &arr) {

        int n = arr.size();
        vector<int> candies(n, 1);

        // Left to Right pass
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to Left pass
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum all candies
        int total = 0;
        for (int c : candies) total += c;

        return total;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ One-Pass Greedy (Incorrect)
- Considers only left neighbor
- Fails for cases like [1,3,2]

---------------------------------------------------------------

2️⃣ Brute Force
- Try all distributions
- Exponential complexity
- ❌ Not feasible

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 2};
    Solution sol;
    cout << sol.minCandy(arr);
    return 0;
}

===================================================================
*/
