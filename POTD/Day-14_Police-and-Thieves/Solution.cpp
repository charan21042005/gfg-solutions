class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Greedy + Two Pointers)
    // =====================================================
    int catchThieves(vector<char> &arr, int k) {

        vector<int> police, thieves;

        // Store positions
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else if (arr[i] == 'T')
                thieves.push_back(i);
        }

        int i = 0, j = 0, count = 0;

        // Two-pointer greedy matching
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                count++;
                i++;
                j++;
            }
            else if (police[i] < thieves[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return count;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- For every policeman, scan all thieves
- Time: O(n^2)
- ❌ Inefficient

---------------------------------------------------------------

2️⃣ Sliding Window (Complex)
- Window of size 2k+1 around policeman
- Hard to manage multiple matches
- ❌ Not clean

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> arr = {'P','T','T','P','T'};
    int k = 1;
    Solution sol;
    cout << sol.catchThieves(arr, k);
    return 0;
}

===================================================================
*/
