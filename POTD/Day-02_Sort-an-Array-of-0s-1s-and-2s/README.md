# Sort an Array of 0s, 1s and 2s

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

---

## 📌 Problem Overview

You are given an array consisting **only of 0s, 1s, and 2s**.  
Your task is to **sort the array in ascending order** without using any built-in sorting function.

This is a **classic array problem** and a **very popular interview question**, often used to test:
- Array traversal skills
- Pointer manipulation
- Understanding of in-place algorithms

---

## 📥 Input Description

- An integer array `arr[]`
- Size of array `n`
- Elements belong to the set `{0, 1, 2}`

---

## 📤 Output Description

- The same array sorted in ascending order:

All 0s → then all 1s → then all 2s


---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should be comfortable with:

### 🔹 Arrays
- Contiguous memory allocation
- Index-based access
- In-place modification

### 🔹 Counting & Traversal
- Counting frequency of elements
- Iterating through arrays

### 🔹 Two / Three Pointer Technique
- Using multiple indices to manage array partitions
- Core idea behind optimal solutions

---

## 🧠 Key Observations

- The array contains **only three unique values**
- We are NOT asked to preserve original order (not a stable sort)
- Sorting can be done **without extra space**
- Time complexity can be **O(n)**

---

## 🎯 Intuition

Since the array has only **0s, 1s, and 2s**, we can think of:
- Grouping all 0s first
- Then all 1s
- Then all 2s

The challenge is to do this:
- In **one traversal**
- Without extra memory
- Without sorting functions

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Using Sorting Function (Not Allowed)

### 💡 Idea
- Use built-in sort

### ❌ Why Not Recommended
- Interviewers expect logic, not library usage
- Time complexity may exceed expectations

---

## 🟡 Approach 2: Counting Method

### 💡 Idea
1. Count number of 0s, 1s, and 2s
2. Overwrite the array based on counts

### ✍️ Steps
- Traverse array → count 0s, 1s, 2s
- Rewrite array:
  - First all 0s
  - Then all 1s
  - Then all 2s

### ⏱️ Complexity
- **Time**: O(n)
- **Space**: O(1)

✔ Simple  
✔ Easy to explain  
❌ Requires two passes

---

## 🟢 Approach 3: Dutch National Flag Algorithm (Optimal)

### ⭐ Most Important Approach

This is the **best and expected solution in interviews**.

---

## 🇳🇱 Dutch National Flag Algorithm (DNF)

### 💡 Core Idea

We divide the array into **four regions** using **three pointers**:

| 0s | 1s | Unknown | 2s |


### 🧭 Pointers Used

| Pointer | Purpose |
|------|------|
| `low` | Boundary for 0s |
| `mid` | Current element |
| `high` | Boundary for 2s |

---

## ⚙️ Algorithm Rules

- If `arr[mid] == 0`
  - Swap `arr[low]` and `arr[mid]`
  - Increment `low` and `mid`

- If `arr[mid] == 1`
  - Just increment `mid`

- If `arr[mid] == 2`
  - Swap `arr[mid]` and `arr[high]`
  - Decrement `high` (do NOT increment `mid`)

---

## ✍️ Pseudocode

low = 0

mid = 0

high = n - 1

while mid <= high:

if arr[mid] == 0:

swap(arr[low], arr[mid])

low++

mid++

else if arr[mid] == 1:

mid++

else:

swap(arr[mid], arr[high])

high--


---

## 🧪 Dry Run Example

### Input

arr = [0, 2, 1, 2, 0]


### Initial State

low = 0, mid = 0, high = 4


### Step-by-Step

1️⃣ `arr[mid] = 0`  

→ swap with `low`, increment both  

[0, 2, 1, 2, 0]

low=1, mid=1


2️⃣ `arr[mid] = 2`  

→ swap with `high`, decrement high  

[0, 0, 1, 2, 2]

high=3


3️⃣ `arr[mid] = 0`  

→ swap with `low`  

[0, 0, 1, 2, 2]

low=2, mid=2


4️⃣ `arr[mid] = 1`  

→ mid++

mid=3


Loop ends → array sorted ✅

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |
| Passes | **Single pass** |

---

## ⚠️ Edge Cases

- All elements are same
- Already sorted array
- Reverse sorted array
- Array size = 1

---

## 🧩 Interview Tips

- Always mention **Dutch National Flag Algorithm**
- Explain pointer movement clearly
- State why `mid` is not incremented when swapping with `high`
- Draw partitions on paper if needed

---

## ✅ Final Notes

- This is a **must-know array problem**
- Frequently asked in:
  - Coding interviews
  - Online assessments
  - Competitive programming
- Builds strong understanding of:
  - In-place sorting
  - Pointer techniques

---

📌 **Day-02 Completed Successfully!**  
🚀 *Arrays mastered step by step.*









