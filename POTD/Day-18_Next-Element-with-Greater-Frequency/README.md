# Next Element with Greater Frequency

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]`.

For **each element**, you need to find the **first element to its right** whose **frequency in the entire array** is **strictly greater** than the frequency of the current element.

If no such element exists, return `-1` for that position.

---

## 📥 Input Description

- An integer array `arr[]` of size `n`

---

## 📤 Output Description

- An array `ans[]` of size `n`
- `ans[i]` = next element to the right with **greater frequency**
- `-1` if no such element exists

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should be comfortable with:

### 🔹 Hashing / Frequency Count
- Counting occurrences of elements
- Using maps or dictionaries

### 🔹 Stack (Monotonic Stack Variant)
- Similar to Next Greater Element
- Comparison based on **frequency**, not value

---

## 🧠 Key Observations

- Comparison is **not by element value**
- Comparison is **by frequency**
- Frequencies are fixed (whole array known beforehand)
- Brute force is too slow

---

## 🎯 Intuition

This problem is a **modified Next Greater Element (NGE)** problem.

Classic NGE:
> Compare values

This problem:
> Compare **frequencies of values**

### Strategy:
1. Precompute frequency of each element
2. Traverse array from **right to left**
3. Maintain a stack where:
   - Stack elements have **higher frequency**
4. Pop elements from stack while:
   - Frequency of stack top ≤ frequency of current element

---

## 🛠️ Approach (Optimal & Expected)

---

## 🟢 Stack + Frequency Map (Optimal)

### 💡 Core Idea

- Use a **hash map** to store frequency of each element
- Use a **stack** to track candidates for NGF
- Process elements from **right to left**

---

## ⚙️ Algorithm Steps

1. Build frequency map for all elements
2. Initialize empty stack
3. Create answer array `ans[]`
4. Traverse array from right to left:
   - While stack not empty AND  
     `freq[stack.top()] <= freq[current]` → pop
   - If stack empty → `ans[i] = -1`
   - Else → `ans[i] = stack.top()`
   - Push current element to stack

---

## ✍️ Pseudocode
```cpp
freq = frequency map of arr
stack = empty
ans = array of size n

for i from n-1 downto 0:
while stack not empty and freq[stack.top] <= freq[arr[i]]:
pop stack

if stack empty:
    ans[i] = -1
else:
    ans[i] = stack.top

push arr[i] to stack


return ans
```

---

## 🧪 Dry Run Example

### Input
```cpp
arr = [2, 1, 1, 3, 2, 1]
```

### Frequencies
```cpp
1 → 3
2 → 2
3 → 1
```

### Output
```cpp
[1, -1, -1, 2, 1, -1]
```

### Explanation
- For `2` → next `1` has higher frequency
- For `1` → no element has higher frequency
- For `3` → next `2` has higher frequency

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |
| Technique | Stack + Hashing |

---

## ⚠️ Edge Cases

- All elements same
- Strictly decreasing frequencies
- Array size = 1
- Large inputs (up to `10^5`)

---

## 🧩 Interview Tips

- Mention similarity to **Next Greater Element**
- Emphasize why brute force fails
- Explain stack condition clearly
- Highlight frequency comparison logic

---

## ✅ Final Notes

- This is a **high-quality stack problem**
- Common in interviews and assessments
- Reinforces stack + hashing combination

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-18 README Completed Successfully!**  
🚀 *Stack + frequency patterns mastered.*
