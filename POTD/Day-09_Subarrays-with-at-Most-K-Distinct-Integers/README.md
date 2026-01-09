# Subarrays with At Most K Distinct Integers

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]` and an integer `k`.  
Your task is to **count the number of contiguous subarrays that contain at most `k` distinct integers**.

This is a **core Sliding Window + Hashing problem**, and it forms the foundation for many related problems like:
- Subarrays with **exactly K distinct**
- Longest substring with **at most K distinct characters**
- Count of good subarrays under constraints

---

## 📥 Input Description

- An integer array `arr[]`
- An integer `k`
- Constraints:  
  - `1 ≤ k ≤ n`  
  - Array elements can repeat

---

## 📤 Output Description

- Return a single integer representing the **number of subarrays having at most `k` distinct elements**

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Subarrays
- Contiguous segments of an array
- Total subarrays ending at index `r` = `r - l + 1`

### 🔹 Hash Map / Frequency Map
- Track frequency of elements in the current window
- Remove elements when their frequency becomes zero

### 🔹 Sliding Window Technique
- Expand window using `right` pointer
- Shrink window using `left` pointer when condition breaks

---

## 🧠 Key Observations

- Brute force checks every subarray → inefficient
- Windows overlap heavily → recomputation is wasteful
- We only need to maintain:
  - Current window
  - Count of distinct elements
- Hash map size directly gives **number of distinct elements**

---

## 🎯 Intuition

We use a **variable-size sliding window**:

- Expand `right` pointer to include new elements
- Track frequencies using a hash map
- If number of distinct elements exceeds `k`:
  - Shrink window from the left
- For every valid window ending at index `right`,
  - All subarrays starting from `left` to `right` are valid

Hence, for each `right`:
```cpp
Number of valid subarrays = right - left + 1
```

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For every subarray, count distinct elements using a set

### ⏱️ Complexity
- **Time**: O(n²)
- **Space**: O(n)

❌ Too slow  
❌ Not scalable

---

## 🟢 Approach 2: Sliding Window + Hash Map (Optimal & Expected)

### ⭐ Most Important Approach

This is the **standard interview solution**.

---

## 🔁 Sliding Window (At Most K Pattern)

### 💡 Core Idea

- Maintain a window `[left … right]`
- Use a hash map to store frequency of elements
- Ensure:
```cpp
Number of distinct elements ≤ k
```

---

## ✍️ Pseudocode
```cpp
freq = empty map
left = 0
count = 0

for right from 0 to n-1:
freq[arr[right]]++

while size(freq) > k:
    freq[arr[left]]--
    if freq[arr[left]] == 0:
        remove arr[left] from freq
    left++

count += (right - left + 1)

return count
```

---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 2, 1, 2, 3]
k = 2
```

### Window Analysis

| Right | Window | Distinct | Valid Subarrays |
|-----|--------|----------|----------------|
| 0 | [1] | 1 | 1 |
| 1 | [1,2] | 2 | 2 |
| 2 | [1,2,1] | 2 | 3 |
| 3 | [1,2,1,2] | 2 | 4 |
| 4 | shrink → [2,1,2,3] | 3 ❌ | shrink |
|   | [1,2,3] | 3 ❌ | shrink |
|   | [2,3] | 2 | 2 |

### ✅ Total Count
```cpp
1 + 2 + 3 + 4 + 2 = 12
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

- `k = 0` → answer is `0`
- `k = 1` → count subarrays with only one unique element
- All elements same
- All elements distinct

---

## 🧩 Interview Tips

- Emphasize **why sliding window works**
- Explain the formula `right - left + 1`
- Mention this is the base for:
  - **Exactly K distinct = AtMost(K) − AtMost(K−1)**
- Avoid using nested loops in explanation

---

## ✅ Final Notes

- This is a **foundational sliding window problem**
- Frequently asked in:
  - Product-based company interviews
  - Subarray counting patterns
- Mastering this unlocks many advanced problems

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-09 README Completed Successfully!**  
🚀 *At-Most-K Sliding Window pattern mastered.*

