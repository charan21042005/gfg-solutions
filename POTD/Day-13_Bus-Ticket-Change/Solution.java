class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Greedy Simulation)
    // =====================================================
    public boolean canServe(int[] arr) {

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
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Backtracking / Combinatorial
- Exponential complexity
- ❌ Overkill

---------------------------------------------------------------

2️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {5,5,5,10,20};
        Solution sol = new Solution();
        System.out.println(sol.canServe(arr));
    }
}

===================================================================
*/
