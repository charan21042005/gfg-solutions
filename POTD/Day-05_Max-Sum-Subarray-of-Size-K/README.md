# Max Sum Subarray of Size K

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

🟢 **Difficulty:** Easy

---

## 📌 Problem Overview

You are given an array of integers `arr[]` and an integer `k`.  
Your task is to **find the maximum sum of any contiguous subarray of size `k`**.

This problem is a **foundational Sliding Window problem** and is extremely important for:
- Arrays
- Subarray-based problems
- Interview problem-solving patterns

---

## 📥 Input Description

- An integer array `arr[]` of size `n`
- An integer `k` (size of the subarray)
- `1 ≤ k ≤ n`

---

## 📤 Output Description

- Return a single integer representing the **maximum sum** of any subarray of size `k`

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Arrays
- Contiguous memory allocation
- Index-based traversal
- Subarrays (continuous segments)

### 🔹 Sliding Window Technique
- Fixed-size window
- Efficient reuse of previous computations
- Optimizing brute-force solutions

---

## 🧠 Key Observations

- We are dealing with **contiguous elements**
- Window size `k` is **fixed**
- Brute force recalculates sums repeatedly
- Sliding window avoids redundant work

---

## 🎯 Intuition

Instead of calculating the sum of every subarray from scratch:

- Compute the sum of the **first window of size `k`**
- Slide the window one step at a time:
  - **Add** the new incoming element
  - **Remove** the outgoing element

This allows us to compute the result in **O(n)** time.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For every index `i`, calculate sum of `k` elements starting from `i`

### ✍️ Steps
- Loop from `i = 0` to `n-k`
- For each `i`, compute sum of `arr[i]` to `arr[i+k-1]`

### ⏱️ Complexity
- **Time**: O(n × k)
- **Space**: O(1)

❌ Inefficient for large inputs  
❌ Repeated calculations

---

## 🟢 Approach 2: Sliding Window (Optimal & Expected)

### ⭐ Most Important Approach

This is the **best and expected solution in interviews**.

---

## 🔁 Sliding Window Technique (Fixed Size)

### 💡 Core Idea

- Maintain a window of size `k`
- Track the sum of elements inside the window
- Slide window by:
  - Removing leftmost element
  - Adding next element on the right

---

## ✍️ Pseudocode

```cpp
windowSum = sum of first k elements
maxSum = windowSum

for i from k to n-1:
windowSum = windowSum + arr[i] - arr[i-k]
maxSum = max(maxSum, windowSum)

return maxSum
```


---

## 🧪 Dry Run Example

### Input
```cpp
arr = [100, 200, 300, 400]
k = 2
```

### Step-by-Step

- Initial window (0 to 1):  
  `100 + 200 = 300` → maxSum = 300

- Slide window:
  - Remove `100`
  - Add `300`
  - New sum = `200 + 300 = 500` → maxSum = 500

- Slide window again:
  - Remove `200`
  - Add `400`
  - New sum = `300 + 400 = 700` → maxSum = 700

### ✅ Output

```cpp
700
```

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |
| Technique | Sliding Window |

---

## ⚠️ Edge Cases

- `k = 1` → maximum element in array
- `k = n` → sum of entire array
- Array with negative numbers
- Array with all same elements

---

## 🧩 Interview Tips

- Always mention **Sliding Window**
- Explain why brute force is inefficient
- Emphasize **fixed window size**
- Clarify difference between:
  - Subarray (contiguous)
  - Subsequence (not contiguous)

---

## ✅ Final Notes

- This is a **must-know beginner Sliding Window problem**
- Frequently asked as:
  - First sliding window question
  - Warm-up interview problem
- Builds strong foundation for:
  - Variable window problems
  - Advanced array optimizations

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-05 Completed Successfully!**  
🚀 *Sliding Window mastered step by step.*
