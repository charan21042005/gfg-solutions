class Solution:

    # =====================================================
    # ✅ OPTIMAL APPROACH (Stack-based)
    # =====================================================
    def checkRedundancy(self, s):

        stack = []

        for ch in s:
            if ch == ')':
                has_operator = False

                while stack and stack[-1] != '(':
                    top = stack.pop()
                    if top in '+-*/':
                        has_operator = True

                # Pop '('
                if stack:
                    stack.pop()

                if not has_operator:
                    return True
            else:
                stack.append(ch)

        return False


'''
========================= OTHER APPROACHES =========================

1️⃣ Brute Force
- Generate substrings inside ()
- Check for operators
- ❌ O(n^2)

---------------------------------------------------------------

2️⃣ Regex
- Difficult to maintain
- ❌ Not interview friendly

---------------------------------------------------------------

3️⃣ Full Standalone Runnable Version

if __name__ == "__main__":
    s = "((a+b))"
    sol = Solution()
    print(sol.checkRedundancy(s))

===================================================================
'''
