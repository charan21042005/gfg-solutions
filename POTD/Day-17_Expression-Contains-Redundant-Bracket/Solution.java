class Solution {

    // =====================================================
    // ✅ OPTIMAL APPROACH (Stack-based)
    // =====================================================
    public static boolean checkRedundancy(String s) {

        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == ')') {
                boolean hasOperator = false;

                while (!st.isEmpty() && st.peek() != '(') {
                    char top = st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                }

                // Pop '('
                if (!st.isEmpty()) st.pop();

                if (!hasOperator)
                    return true;
            } 
            else {
                st.push(ch);
            }
        }

        return false;
    }
}

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Extract substrings
- Check operators
- ❌ Inefficient

---------------------------------------------------------------

2️⃣ Regex
- Hard to debug
- ❌ Not recommended

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

class Main {
    public static void main(String[] args) {
        String s = "(a+(b)/c)";
        System.out.println(Solution.checkRedundancy(s));
    }
}

===================================================================
*/
