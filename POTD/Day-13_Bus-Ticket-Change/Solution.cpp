class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Greedy Simulation)
    // =====================================================
    bool canServe(vector<int> &arr) {

        int five = 0, ten = 0;

        for (int bill : arr) {

            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Backtracking / Combinations
- Try all possible ways to give change
- Exponential time
- ❌ Completely unnecessary

---------------------------------------------------------------

2️⃣ Brute Force Simulation with State Copy
- Maintain all combinations of coins
- Very slow and complex
- ❌ Not interview-friendly

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5,5,5,10,20};
    Solution sol;
    cout << sol.canServe(arr);
    return 0;
}

===================================================================
*/
