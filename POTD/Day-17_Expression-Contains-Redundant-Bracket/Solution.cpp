class Solution {
  public:
    // =====================================================
    // ✅ OPTIMAL APPROACH (Stack-based)
    // =====================================================
    bool checkRedundancy(string &s) {

        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;

                // Check contents inside brackets
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                }

                // Pop opening bracket
                if (!st.empty()) st.pop();

                // If no operator found → redundant
                if (!hasOperator)
                    return true;
            } 
            else {
                st.push(ch);
            }
        }

        return false;
    }
};

/*
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Check every substring inside ()
- Verify presence of operator
- Time: O(n^2)
- ❌ Not efficient

---------------------------------------------------------------

2️⃣ Regex Based (Not Recommended)
- Hard to maintain
- ❌ Not interview friendly

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "((a+b))";
    Solution sol;
    cout << sol.checkRedundancy(s);
    return 0;
}

===================================================================
*/
