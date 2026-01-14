# Police and Thieves

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an array `arr[]` consisting of characters:
- `'P'` → Policeman
- `'T'` → Thief

Each policeman can catch **at most one thief** under the following conditions:
1. A policeman can catch a thief only if the distance between them is **≤ k**
2. Each thief can be caught by **only one policeman**

Your task is to find the **maximum number of thieves** that can be caught.

---

## 📥 Input Description

- `arr[]`: Array of characters containing only `'P'` and `'T'`
- `k`: Maximum distance a policeman can reach

---

## 📤 Output Description

- Return an integer representing the **maximum number of thieves caught**

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Greedy Algorithms
- Make locally optimal choices
- Ensure maximum global outcome

### 🔹 Two-Pointer Technique
- Traverse two sorted lists efficiently
- Reduce time complexity

### 🔹 Absolute Distance
- `|police_index - thief_index| ≤ k`

---

## 🧠 Key Observations

- Policemen and thieves are fixed in order
- A greedy match gives the best outcome
- Matching nearest possible pairs prevents blocking future matches

---

## 🎯 Intuition

Instead of checking every policeman against every thief (inefficient), we can:

1. Store positions of all policemen
2. Store positions of all thieves
3. Use **two pointers** to greedily match them

💡 **Why greedy works?**
- Matching the closest valid policeman-thief pair ensures maximum remaining opportunities

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For every policeman, check all thieves within distance `k`

### ⏱️ Complexity
- **Time:** O(n²)
- **Space:** O(1)

❌ Too slow for large inputs  
❌ Fails time limits

---

## 🟢 Approach 2: Greedy + Two Pointers (Optimal & Expected)

### ⭐ Most Important Approach

This is the **optimal and interview-expected solution**.

---

## 🔁 Two-Pointer Strategy

### 💡 Core Idea

- Maintain two lists:
  - `police[]` → indices of policemen
  - `thieves[]` → indices of thieves
- Use pointers `i` and `j` to traverse both lists

---

## ⚙️ Algorithm Steps

1. Traverse `arr[]` and store:
   - Indices of `'P'` in `police[]`
   - Indices of `'T'` in `thieves[]`
2. Initialize pointers `i = 0`, `j = 0`
3. While both pointers are within bounds:
   - If `|police[i] - thieves[j]| ≤ k`:
     - Count a successful catch
     - Move both pointers
   - Else if `police[i] < thieves[j]`:
     - Move policeman pointer
   - Else:
     - Move thief pointer

---

## ✍️ Pseudocode
```cpp
police = []
thieves = []

for i in range(n):
if arr[i] == 'P':
police.append(i)
else if arr[i] == 'T':
thieves.append(i)

i = 0, j = 0, count = 0

while i < len(police) and j < len(thieves):
if abs(police[i] - thieves[j]) <= k:
count++
i++, j++
else if police[i] < thieves[j]:
i++
else:
j++

return count
```


---

## 🧪 Dry Run Example

### Input
```cpp
arr = ['P', 'T', 'T', 'P', 'T']
k = 1
```

### Positions
```cpp
police = [0, 3]
thieves = [1, 2, 4]
```

### Matching
- Police at `0` catches thief at `1`
- Police at `3` catches thief at `2`

✅ Output: `2`

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |
| Technique | Greedy + Two Pointers |

---

## ⚠️ Edge Cases

- No policemen or no thieves
- `k = 0`
- All elements same
- Large `k` covering whole array

---

## 🧩 Interview Tips

- Always explain **why greedy works**
- Mention why brute force is inefficient
- Use position arrays + two pointers
- Emphasize optimal matching

---

## ✅ Final Notes

- This is a **classic greedy matching problem**
- Very common in interviews and practice platforms
- Clean logic matters more than complex data structures

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-14 README Completed Successfully!**  
🚀 *Greedy + two-pointer mastery continues.*

