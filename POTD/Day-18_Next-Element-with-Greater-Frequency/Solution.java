class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Stack + Frequency Map)
    // =====================================================
    public ArrayList<Integer> nextFreqGreater(int[] arr) {

        int n = arr.length;
        HashMap<Integer, Integer> freq = new HashMap<>();

        // Frequency count
        for (int x : arr)
            freq.put(x, freq.getOrDefault(x, 0) + 1);

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) ans.add(-1);

        Stack<Integer> st = new Stack<>();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            while (!st.isEmpty() &&
                   freq.get(st.peek()) <= freq.get(arr[i])) {
                st.pop();
            }

            if (!st.isEmpty())
                ans.set(i, st.peek());

            st.push(arr[i]);
        }

        return ans;
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Nested loops
- Compare frequencies
- ❌ O(n^2)

---------------------------------------------------------------

2️⃣ Stack of Indices
- Store indices instead of values
- Same idea, slightly verbose

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        int[] arr = {2, 1, 1, 3, 2, 1};
        Solution sol = new Solution();
        System.out.println(sol.nextFreqGreater(arr));
    }
}

===================================================================
*/
