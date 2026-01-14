class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Greedy + Two Pointers)
    // =====================================================
    public int catchThieves(char[] arr, int k) {

        ArrayList<Integer> police = new ArrayList<>();
        ArrayList<Integer> thieves = new ArrayList<>();

        // Store positions
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 'P')
                police.add(i);
            else if (arr[i] == 'T')
                thieves.add(i);
        }

        int i = 0, j = 0, count = 0;

        // Two-pointer greedy matching
        while (i < police.size() && j < thieves.size()) {
            if (Math.abs(police.get(i) - thieves.get(j)) <= k) {
                count++;
                i++;
                j++;
            }
            else if (police.get(i) < thieves.get(j)) {
                i++;
            }
            else {
                j++;
            }
        }

        return count;
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- O(n^2)
- ❌ TLE for large inputs

---------------------------------------------------------------

2️⃣ Sliding Window
- Complicated state tracking
- ❌ Not recommended

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        char[] arr = {'P','T','T','P','T'};
        int k = 1;
        Solution sol = new Solution();
        System.out.println(sol.catchThieves(arr, k));
    }
}

===================================================================
*/
