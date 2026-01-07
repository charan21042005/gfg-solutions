# Count Distinct Elements in Every Window

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]` of size `n` and an integer `k`.  
Your task is to **count the number of distinct elements in every contiguous subarray (window) of size `k`**.

This problem is a **classic Sliding Window + Hashing problem** and is frequently asked in interviews to test:
- Window-based thinking
- Frequency tracking
- Efficient use of hash maps

---

## 📥 Input Description

- An integer array `arr[]` of size `n`
- An integer `k` (window size)
- Constraint: `1 ≤ k ≤ n`

---

## 📤 Output Description

- Return a list / array where each element represents the **count of distinct numbers** in the corresponding window of size `k`

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Arrays & Subarrays
- Contiguous segments of an array
- Fixed-size sliding window problems

### 🔹 Hashing / Hash Map
- Storing frequency of elements
- Constant-time insert, delete, lookup

### 🔹 Sliding Window Technique
- Maintaining window state while moving forward
- Updating data structures incrementally

---

## 🧠 Key Observations

- Brute force recalculates distinct count for each window
- Windows **overlap**, so recomputation is wasteful
- We can **reuse information from the previous window**
- Hash map helps track **frequency of elements**

---

## 🎯 Intuition

Instead of counting distinct elements from scratch for every window:

1. Use a hash map to store **frequency of elements** in the current window
2. The number of keys in the map = number of distinct elements
3. When the window slides:
   - Decrease frequency of outgoing element
   - Remove it from map if frequency becomes 0
   - Increase frequency of incoming element

This ensures efficient computation.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For each window, use a set to count distinct elements

### ✍️ Steps
- For each starting index `i`:
  - Insert `k` elements into a set
  - Store set size

### ⏱️ Complexity
- **Time**: O(n × k)
- **Space**: O(k)

❌ Too slow for large inputs  
❌ Repeated work

---

## 🟢 Approach 2: Sliding Window + Hash Map (Optimal & Expected)

### ⭐ Most Important Approach

This is the **best and expected solution**.

---

## 🔁 Sliding Window with Frequency Map

### 💡 Core Idea

- Maintain a hash map `freq`
- Keys → elements in window  
- Values → frequency of each element

At any time:
```cpp
Number of distinct elements = size of freq map
```

---

## ✍️ Pseudocode
```cpp
freq = empty map
result = empty list

// First window
for i from 0 to k-1:
freq[arr[i]]++

add size(freq) to result

// Slide window
for i from k to n-1:
// remove outgoing element
freq[arr[i-k]]--
if freq[arr[i-k]] == 0:
remove arr[i-k] from freq

// add incoming element
freq[arr[i]]++

add size(freq) to result


return result
```

---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 2, 1, 3, 4, 2, 3]
k = 4
```

### Windows & Distinct Counts

| Window | Elements | Distinct Count |
|------|---------|----------------|
| 0–3 | [1, 2, 1, 3] | 3 |
| 1–4 | [2, 1, 3, 4] | 4 |
| 2–5 | [1, 3, 4, 2] | 4 |
| 3–6 | [3, 4, 2, 3] | 3 |

### ✅ Output
```cpp
[3, 4, 4, 3]
```

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(k)** |
| Technique | Sliding Window + Hash Map |

---

## ⚠️ Edge Cases

- `k = 1` → result is all 1s
- `k = n` → only one window
- All elements same
- All elements distinct

---

## 🧩 Interview Tips

- Always mention **why brute force is inefficient**
- Emphasize **frequency map**, not set
- Explain removal of elements when frequency hits 0
- Relate this problem to other sliding window problems

---

## ✅ Final Notes

- This is a **must-know Sliding Window problem**
- Very common in:
  - Coding interviews
  - Online assessments
- Strengthens understanding of:
  - Hash maps
  - Window-based optimizations

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-07 Completed Successfully!**  
🚀 *Sliding Window + Hashing mastered step by step.*

