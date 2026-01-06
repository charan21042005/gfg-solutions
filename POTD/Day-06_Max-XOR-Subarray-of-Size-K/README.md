# Max XOR Subarray of Size K

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]` of size `n` and an integer `k`.  
Your task is to **find the maximum XOR value** of any **contiguous subarray of size `k`**.

This problem combines:
- **Sliding Window technique**
- **Bitwise XOR operation**

and is frequently used to test how well a candidate understands **window-based optimization with bit manipulation**.

---

## 📥 Input Description

- An integer array `arr[]`
- Integer `k` (fixed window size)
- Constraint: `1 ≤ k ≤ n`

---

## 📤 Output Description

- Return a single integer representing the **maximum XOR** among all subarrays of size `k`

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should be comfortable with:

### 🔹 Arrays & Subarrays
- Contiguous segments of an array
- Fixed-size subarray problems

### 🔹 Bitwise XOR (`^`)
- XOR of two bits:
  - `0 ^ 0 = 0`
  - `1 ^ 1 = 0`
  - `0 ^ 1 = 1`
  - `1 ^ 0 = 1`
- XOR properties:
  - `a ^ a = 0`
  - `a ^ 0 = a`

### 🔹 Sliding Window Technique
- Efficient way to process fixed-size subarrays
- Avoids recomputation

---

## 🧠 Key Observations

- We are dealing with **fixed-size contiguous subarrays**
- XOR is **not cumulative like sum**, but:
  - We can still manage it by carefully removing and adding elements
- Brute force recalculates XOR repeatedly → inefficient

---

## 🎯 Intuition

Instead of computing XOR for every subarray from scratch:

1. Compute XOR of the **first window of size `k`**
2. Slide the window:
   - Remove the outgoing element’s effect
   - Add the incoming element’s effect
3. Track the **maximum XOR** encountered

This mirrors the **Sliding Window pattern**, similar to Day-05, but with XOR instead of sum.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For each starting index, compute XOR of the next `k` elements

### ✍️ Steps
- Loop from `i = 0` to `n-k`
- For each `i`, XOR elements from `i` to `i+k-1`

### ⏱️ Complexity
- **Time**: O(n × k)
- **Space**: O(1)

❌ Too slow for large inputs  
❌ Repeated XOR calculations

---

## 🟢 Approach 2: Sliding Window with XOR (Optimal & Expected)

### ⭐ Most Important Approach

This is the **best and expected solution**.

---

## 🔁 Sliding Window Technique (Fixed Size)

### 💡 Core Idea

- Maintain XOR of current window
- When sliding the window:
  - XOR the outgoing element (to remove it)
  - XOR the incoming element (to add it)

Thanks to the property:
```cpp
x ^ x = 0
```

we can safely remove elements using XOR.

---

## ✍️ Pseudocode

```cpp
currentXor = 0

for i from 0 to k-1:
currentXor ^= arr[i]

maxXor = currentXor

for i from k to n-1:
currentXor ^= arr[i-k] // remove outgoing element
currentXor ^= arr[i] // add incoming element
maxXor = max(maxXor, currentXor)

return maxXor
```

---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 2, 3, 4]
k = 2
```

### Step-by-Step

- First window (0–1):
```cpp
1 ^ 2 = 3
maxXor = 3
```

- Slide window (1–2):
```cpp
Remove 1 → 3 ^ 1 = 2
Add 3 → 2 ^ 3 = 1
maxXor = max(3, 1) = 3
```


- Slide window (2–3):
```cpp
Remove 2 → 1 ^ 2 = 3
Add 4 → 3 ^ 4 = 7
maxXor = max(3, 7) = 7
```


### ✅ Output

```cpp
7
```

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |
| Technique | Sliding Window + XOR |

---

## ⚠️ Edge Cases

- `k = 1` → maximum element in array
- `k = n` → XOR of entire array
- Array with all zeros
- Array with repeating elements

---

## 🧩 Interview Tips

- Emphasize **XOR properties**
- Explain why XOR allows element removal
- Compare with Sliding Window (sum version)
- Clarify difference between XOR and sum behavior

---

## ✅ Final Notes

- This is a **classic Sliding Window + Bitwise problem**
- Very useful for:
  - Bit manipulation practice
  - Pattern recognition in interviews
- Builds confidence in combining:
  - Array traversal
  - Window techniques
  - Bitwise logic

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-06 Completed Successfully!**  
🚀 *Sliding Window + XOR mastered step by step.*

