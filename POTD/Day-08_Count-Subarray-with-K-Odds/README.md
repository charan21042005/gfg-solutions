# Count Subarrays with Exactly K Odds

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]` of size `n` and an integer `k`.  
Your task is to **count the number of contiguous subarrays that contain exactly `k` odd numbers**.

This problem is a **classic interview question** that tests:
- Understanding of **subarrays**
- **Prefix sum** and **hashing**
- Advanced **sliding window patterns**

---

## 📥 Input Description

- An integer array `arr[]`
- An integer `k`
- Constraint: `1 ≤ k ≤ n`

---

## 📤 Output Description

- Return a single integer representing the **number of subarrays with exactly `k` odd elements**

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Subarrays
- Contiguous segments of an array
- Subarrays vs subsequences

### 🔹 Odd / Even Identification
- A number is odd if `num % 2 == 1`
- We can transform the array into a binary form:
  - Odd → `1`
  - Even → `0`

### 🔹 Prefix Sum
- Cumulative sum of elements
- Helps answer range queries efficiently

### 🔹 Hashing
- Storing frequency of prefix sums
- Enables O(1) average lookup

---

## 🧠 Key Observations

- We only care about **odd numbers**
- Even numbers do not affect the odd count
- Transforming the array simplifies the problem
- Counting subarrays with **exactly `k` ones** becomes the goal

---

## 🎯 Intuition

There are **two clean and popular ways** to solve this problem optimally:

1. **Prefix Sum + Hash Map**
2. **Sliding Window using “At Most K” trick**

Both run in **O(n)** time and are interview-accepted.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For every subarray, count odd numbers

### ✍️ Steps
- Use two nested loops
- For each subarray, count odds

### ⏱️ Complexity
- **Time**: O(n²)
- **Space**: O(1)

❌ Too slow  
❌ Repeated calculations

---

## 🟢 Approach 2: Prefix Sum + Hash Map (Optimal & Popular)

### ⭐ Most Common Interview Solution

---

## 🔢 Prefix Sum Transformation

Convert array:
```cpp
odd[i] = 1 if arr[i] is odd else 0
```

Now the problem becomes:
> Count subarrays with **sum exactly = k**

---

## 💡 Core Idea
```cpp
If:
prefixSum[j] - prefixSum[i] = k
Then:
prefixSum[i] = prefixSum[j] - k
```

We store frequencies of prefix sums in a hash map.

---

## ✍️ Pseudocode (Prefix Sum Method)

```cpp
freq = map()
freq[0] = 1

count = 0
prefixSum = 0

for num in arr:
if num is odd:
prefixSum += 1

if (prefixSum - k) exists in freq:
    count += freq[prefixSum - k]

freq[prefixSum]++

return count
```


---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 1, 2, 1, 1]
k = 3
```
### Transformed Array
```cpp
[1, 1, 0, 1, 1]
```

### Valid Subarrays
- `[1, 1, 2, 1]`
- `[1, 2, 1, 1]`

### ✅ Output
```cpp
2
```

---

## 🟢 Approach 3: Sliding Window (At Most K Odds Trick)

### ⭐ Advanced & Very Powerful Pattern

---

## 💡 Core Idea
```cpp
Exactly K odds =
Subarrays with at most K odds

* Subarrays with at most (K - 1) odds
```


So we:
1. Write a helper function `countAtMost(k)`
2. Answer = `countAtMost(k) - countAtMost(k - 1)`

---

## ✍️ Pseudocode (At Most Method)
```cpp
function countAtMost(k):
left = 0
count = 0
oddCount = 0

for right from 0 to n-1:
    if arr[right] is odd:
        oddCount++

    while oddCount > k:
        if arr[left] is odd:
            oddCount--
        left++

    count += (right - left + 1)

return count

answer = countAtMost(k) - countAtMost(k - 1)
```


---

## ⏱️ Time & Space Complexity

| Approach | Time | Space |
|------|------|-------|
| Brute Force | O(n²) | O(1) |
| Prefix Sum + Map | **O(n)** | **O(n)** |
| Sliding Window (At Most) | **O(n)** | **O(1)** |

---

## ⚠️ Edge Cases

- `k = 0` (subarrays with no odd numbers)
- All elements odd
- All elements even
- Single-element array

---

## 🧩 Interview Tips

- Start with brute force → explain why it fails
- Mention **prefix sum + hashmap** clearly
- If interviewer pushes, present **At Most K trick**
- Emphasize **contiguous subarrays**

---

## ✅ Final Notes

- This is a **high-quality pattern problem**
- Appears in:
  - Subarray counting questions
  - Prefix sum & sliding window discussions
- Mastering this unlocks many similar problems

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-08 README Completed Successfully!**  
🚀 *Prefix Sum + Sliding Window mastered step by step.*

