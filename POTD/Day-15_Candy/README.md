# Candy

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/candy/1

🔴 **Difficulty:** Hard

---

## 📌 Problem Overview

There are `n` children standing in a line.  
Each child is assigned a **rating value** given in the integer array `arr[]`.

You are distributing candies to these children under the following conditions:

1️⃣ Each child must receive **at least one candy**  
2️⃣ A child with a **higher rating than an adjacent neighbor** must receive **more candies** than that neighbor  

Your task is to compute the **minimum total number of candies** required to satisfy these rules.

---

## 📥 Input Description

- `arr[]`: Integer array representing ratings of children  
- `n`: Number of children  

---

## 📤 Output Description

- Return an integer representing the **minimum number of candies** needed  

> ⚠️ Note: The answer always fits within a 32-bit integer.

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Greedy Algorithms
- Local decisions with global correctness
- Why one-direction greedy may fail

### 🔹 Array Traversal
- Left-to-right and right-to-left passes
- Maintaining auxiliary arrays

### 🔹 Neighbor Constraints
- Each element depends on both left and right neighbors

---

## 🧠 Key Observations

- Every child must get **at least 1 candy**
- A single pass is **not sufficient**
- A child may need more candies due to:
  - Left neighbor
  - Right neighbor
- Both directions must be respected

---

## 🎯 Intuition

If a child has a higher rating than:
- **Left neighbor** → must get more candies than left
- **Right neighbor** → must get more candies than right  

To satisfy **both conditions**, we:
- First handle left neighbors
- Then handle right neighbors
- Take the **maximum** candies needed from both sides

This guarantees **minimum candies with all constraints satisfied**.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Feasible)

### 💡 Idea
- Try all possible candy distributions
- Check constraints

### ❌ Problems
- Exponential combinations
- Completely infeasible

---

## 🟡 Approach 2: One-Pass Greedy (Incorrect)

### 💡 Idea
- Assign candies based only on left neighbor

### ❌ Why it fails
- Ignores right neighbor constraint
- Breaks cases like:  
  `[1, 3, 2]`

---

## 🟢 Approach 3: Two-Pass Greedy (Optimal & Expected)

### ⭐ Most Important Approach

This is the **only correct and interview-expected solution**.

---

## 🔁 Two-Pass Greedy Strategy

### 💡 Core Idea

1️⃣ Initialize all candies to `1`  
2️⃣ **Left to Right Pass**  
   - If `arr[i] > arr[i-1]`  
     → `candies[i] = candies[i-1] + 1`  
3️⃣ **Right to Left Pass**  
   - If `arr[i] > arr[i+1]`  
     → `candies[i] = max(candies[i], candies[i+1] + 1)`  
4️⃣ Sum all candies

---

## ✍️ Pseudocode
```cpp
candies = [1] * n

// Left to Right
for i = 1 to n-1:
if arr[i] > arr[i-1]:
candies[i] = candies[i-1] + 1

// Right to Left
for i = n-2 down to 0:
if arr[i] > arr[i+1]:
candies[i] = max(candies[i], candies[i+1] + 1)

return sum(candies)
```

---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 0, 2]
```

### Step 1: Initialize
```cpp
candies = [1, 1, 1]
```

### Step 2: Left to Right
- `2 > 0` → candies[2] = 2  
```cpp
candies = [1, 1, 2]
```

### Step 3: Right to Left
- `1 > 0` → candies[0] = 2  
```cpp
candies = [2, 1, 2]
```

### Total Candies
```cpp
2 + 1 + 2 = 5
```

✅ Correct

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |
| Technique | Two-Pass Greedy |

---

## ⚠️ Edge Cases

- All children have same rating
- Strictly increasing ratings
- Strictly decreasing ratings
- Single child

---

## 🧩 Interview Tips

- Always explain **why one pass fails**
- Emphasize the need to satisfy **both neighbors**
- Mention using `max()` in the second pass
- This problem is a **classic greedy benchmark**

---

## ✅ Final Notes

- Deceptively simple but conceptually deep
- A must-know **HARD greedy problem**
- Appears frequently in FAANG-level interviews


---

## 🎥 Video Explanations (Recommended)

If you prefer visual and step-by-step explanations, the following videos explain the **Candy problem** and the **two-pass greedy strategy** very clearly:

- ▶️ **Candy Problem – Greedy Two Pass Explanation**  
  https://www.youtube.com/watch?v=IIqVFvKE6RY

- ▶️ **Candy Problem – Intuition & Dry Run (Interview Perspective)**  
  https://youtu.be/mNHl2H8JwEs

These videos are helpful to:
- Build strong intuition
- Understand why **one-pass greedy fails**
- Visualize left-to-right and right-to-left passes


## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-15 README Completed Successfully!**  
🔥 *Hard problem conquered — streak continues strong.*

