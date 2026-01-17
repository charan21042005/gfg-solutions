# Expression Contains Redundant Bracket or Not

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given a **valid mathematical expression** containing:
- Parentheses `(` and `)`
- Operators `+`, `-`, `*`, `/`
- Operands (variables or numbers)

Your task is to **check whether the expression contains any redundant brackets**.

### 🔎 What is a redundant bracket?

A pair of brackets is considered **redundant** if:
- They do **not enclose any operator**, OR
- The same sub-expression is surrounded by **unnecessary brackets**

---

## 📥 Input Description

- A string `s` representing a **balanced expression**
- No white spaces
- Expression is always valid

---

## 📤 Output Description

- Return `true` → if **redundant brackets exist**
- Return `false` → otherwise

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Stack Data Structure
- LIFO behavior
- Used to process nested structures

### 🔹 Expression Parsing
- Handling operators and parentheses
- Matching opening and closing brackets

---

## 🧠 Key Observations

- Redundant brackets look like:
  - `(a)`
  - `((a+b))`
  - `(a+(b))`
- Valid non-redundant cases:
  - `(a+b)`
  - `(a+(b*c))`

👉 **If there is no operator between `(` and `)` → redundant**

---

## 🎯 Intuition (Stack-Based Thinking)

We scan the expression **left to right** and use a stack.

### Core idea:
- Push everything onto the stack
- When we encounter `)`:
  - Pop elements until `(` is found
  - If **no operator** was found in between → redundant bracket

---

## 🛠️ Approach (Optimal & Expected)

---

## 🟢 Stack-Based Approach (Optimal)

### 💡 Strategy

1. Initialize an empty stack
2. Traverse each character in the string
3. Push characters into stack **until `)` is encountered**
4. On `)`:
   - Pop until `(` is found
   - Check if any operator (`+ - * /`) exists
   - If NOT → redundant

---

## ✍️ Pseudocode
```cpp
stack = empty

for ch in expression:
if ch == ')':
hasOperator = false
while stack.top() != '(':
if stack.top() is operator:
hasOperator = true
pop stack
pop '('
if hasOperator == false:
return true
else:
push ch

return false
```

---

## 🧪 Dry Run Examples

### Example 1
Input: ((a+b))

Stack before processing `)`:
( ( a + b

- Operator `+` found → OK
- Outer brackets have **no operator** → ❌ redundant

✅ Output: `true`

---

### Example 2
Input: (a+(b)/c)

- `(b)` has no operator → redundant

✅ Output: `true`

---

### Example 3
Input: (a+b+(c+d))

- All brackets contain operators

❌ Output: `false`

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |
| Technique | Stack |

---

## ⚠️ Edge Cases

- Single variable in brackets `(a)`
- Nested redundant brackets
- Long expressions (up to `10^5`)

---

## 🧩 Interview Tips

- Always mention **stack usage**
- Focus on operator presence
- Clarify why checking operators works
- Common follow-up: remove redundant brackets

---

## ✅ Final Notes

- This is a **must-know stack problem**
- Frequently asked in interviews
- Tests understanding of **expression parsing**

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-17 README Completed Successfully!**  
🚀 *Stack mastery in progress — expressions decoded.*

