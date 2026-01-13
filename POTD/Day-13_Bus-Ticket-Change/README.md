# Bus Ticket Change

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/lemonade-change/1

🟢 **Difficulty:** Easy

---

## 📌 Problem Overview

You are given an array `arr[]` representing passengers standing in a queue.  
Each passenger buys a bus ticket that costs **5 coins**.

The value `arr[i]` represents the coin/bill used by the `i-th` passenger to pay:
- `5`
- `10`
- `20`

You must **serve passengers in order** and always provide **exact change** so that each passenger effectively pays **exactly 5 coins**.

Your task is to determine whether it is possible to serve **all passengers** without ever running out of change.

---

## 📥 Input Description

- `arr[]`: array of integers where each element is `{5, 10, 20}`
- Passengers must be processed in the given order

---

## 📤 Output Description

- Return `true` if all passengers can be served correctly
- Return `false` otherwise

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Greedy Algorithm
- Make the **locally optimal decision** at each step
- No backtracking
- Works because future decisions depend on current change

### 🔹 Simulation
- Process events step-by-step
- Maintain state variables (coins in hand)

---

## 🧠 Key Observations

- Ticket cost is always **5**
- Only three types of payments exist: `5`, `10`, `20`
- Change required:
  - `5` → no change
  - `10` → need `5`
  - `20` → need `15` (`10 + 5` preferred)

---

## 🎯 Intuition

We simulate the process while keeping track of:
- Number of `5`-coin bills
- Number of `10`-coin bills

💡 **Greedy choice**:
- When giving change for `20`, **prefer using one `10` + one `5`**
- This preserves smaller denominations for future passengers

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force / Backtracking (Not Needed)

- Try all combinations of change
- Extremely inefficient
- ❌ Not required for this problem

---

## 🟢 Approach 2: Greedy Simulation (Optimal & Expected)

### ⭐ Most Important Approach

This is the **correct and expected solution**.

---

## ⚙️ Greedy Rules

Let:
- `five` = number of 5-coin bills
- `ten` = number of 10-coin bills

Process each passenger:

1️⃣ If passenger pays `5`
- Increment `five`

2️⃣ If passenger pays `10`
- Must give one `5`
- Decrement `five`, increment `ten`

3️⃣ If passenger pays `20`
- Prefer:
  - One `10` + one `5`
- Else:
  - Three `5`s
- If neither possible → return `false`

---

## ✍️ Pseudocode
```cpp
five = 0
ten = 0

for each bill in arr:
if bill == 5:
five++
else if bill == 10:
if five == 0:
return false
five--
ten++
else:
if ten > 0 and five > 0:
ten--
five--
else if five >= 3:
five -= 3
else:
return false

return true
```


---

## 🧪 Dry Run Example

### Example 1
```cpp
arr = [5, 5, 5, 10, 20]
```

| Passenger | Pays | Action |
|---------|------|-------|
| 1 | 5 | five = 1 |
| 2 | 5 | five = 2 |
| 3 | 5 | five = 3 |
| 4 | 10 | give 5 → five = 2, ten = 1 |
| 5 | 20 | give 10 + 5 → five = 1, ten = 0 |

✅ All served → `true`

---

### Example 2
```cpp
arr = [5, 5, 10, 10, 20]
```

Last passenger needs `15` change  
Only two `10`s exist → ❌ not possible

❌ Output: `false`

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |
| Technique | Greedy Simulation |

---

## ⚠️ Edge Cases

- First passenger pays `10` or `20`
- No `5` available for change
- Many `20`s at the end
- All passengers pay `5`

---

## 🧩 Interview Tips

- Always explain **why greedy works**
- Mention **preference of 10 + 5 over 3 fives**
- Emphasize constant space
- This problem tests **decision logic**, not data structures

---

## ✅ Final Notes

- Simple problem, but **easy to make mistakes**
- Accuracy matters more than complexity
- A clean greedy solution is expected

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-13 README Completed Successfully!**  
🚀 *Greedy decision-making mastered.*

