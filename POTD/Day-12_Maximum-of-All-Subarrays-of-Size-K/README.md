# Maximum of All Subarrays of Size K

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]` and an integer `k`.  
Your task is to find the **maximum element of every contiguous subarray (window) of size `k`**.

This is a **classic sliding window problem** and one of the **most frequently asked interview questions**, especially to test:
- Sliding window optimization
- Deque (double-ended queue) usage
- Monotonic data structures

---

## 📥 Input Description

- An integer array `arr[]`
- An integer `k` (window size)
- Constraints ensure large input size, so an optimized solution is required

---

## 📤 Output Description

- Return a list containing the **maximum of each subarray of size `k`**

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should be comfortable with:

### 🔹 Sliding Window Technique
- Fixed-size window
- Move window one step at a time
- Efficient update of window result

### 🔹 Deque (Double-Ended Queue)
- Push and pop from both ends
- Maintain useful elements only

### 🔹 Monotonic Queue
- Elements stored in decreasing order
- Front always gives the maximum

---

## 🧠 Key Observations

- Brute force recalculates maximum for each window → inefficient
- Windows overlap heavily → repeated work
- We only care about:
  - Current window’s maximum
  - Elements that can become maximum in future windows

---

## 🎯 Intuition

To efficiently get the maximum of each window:

1. Maintain a **deque of indices**
2. Keep elements in **decreasing order**
3. Remove:
   - Indices outside the current window
   - Smaller elements from the back (they are useless)

This ensures:
- Front of deque always stores the index of the maximum element
- Each element is added and removed at most once

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For each window, scan all `k` elements to find the maximum

### ⏱️ Complexity
- **Time:** O(n × k)
- **Space:** O(1)

❌ Too slow for large inputs  
❌ Fails time limits

---

## 🟢 Approach 2: Deque + Sliding Window (Optimal & Expected)

### ⭐ Most Important Approach

This is the **industry-standard and interview-expected solution**.

---

## 🔁 Monotonic Deque Strategy

### 💡 Core Idea

- Store **indices** in deque
- Ensure values are in **descending order**
- The front of deque always contains the maximum of current window

---

## ✍️ Algorithm Steps

1. Traverse array from left to right
2. Remove indices from front if they are out of the current window
3. Remove indices from back if their value is smaller than current element
4. Add current index to deque
5. Once window size reaches `k`, record the maximum

---

## ✍️ Pseudocode
```cpp
deque dq
result = []

for i from 0 to n-1:
while dq not empty and dq.front() <= i - k:
dq.pop_front()

while dq not empty and arr[dq.back()] < arr[i]:
    dq.pop_back()

dq.push_back(i)

if i >= k - 1:
    result.push(arr[dq.front()])
```

---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
```

### Windows & Maximums

| Window | Elements | Max |
|------|----------|-----|
| 0–2 | [1, 3, -1] | 3 |
| 1–3 | [3, -1, -3] | 3 |
| 2–4 | [-1, -3, 5] | 5 |
| 3–5 | [-3, 5, 3] | 5 |
| 4–6 | [5, 3, 6] | 6 |
| 5–7 | [3, 6, 7] | 7 |

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(k)** |
| Technique | Deque + Sliding Window |

---

## ⚠️ Edge Cases

- `k = 1` → answer is the array itself
- `k = n` → only one window
- All elements equal
- Strictly increasing or decreasing array

---

## 🧩 Interview Tips

- Always mention **deque**
- Explain why brute force fails
- Use **indices**, not values
- Emphasize that each element is processed once → O(n)

---

## ✅ Final Notes

- This is a **must-know sliding window + deque problem**
- Extremely common in:
  - Coding interviews
  - Online assessments
- Mastering this unlocks many advanced window problems

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-12 README Completed Successfully!**  
🚀 *Deque-based sliding window mastered.*

