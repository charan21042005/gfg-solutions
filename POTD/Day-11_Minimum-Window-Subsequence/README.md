# Minimum Window Subsequence

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given two strings:

- `S` → the main string  
- `T` → the target string  

Your task is to find the **minimum length substring of `S` such that `T` is a subsequence of that substring**.

⚠️ **Important:**  
This is **NOT** the same as *Minimum Window Substring*.

- ❌ Order does NOT matter in substring problem (frequency based)
- ✅ Order **DOES matter** here (subsequence based)

---

## 📥 Input Description

- A string `S`
- A string `T`
- `T` must appear as a **subsequence** inside the chosen window of `S`

---

## 📤 Output Description

- Return the **minimum window substring of `S`**
- If no such window exists, return an empty string `""`

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Substring
- Continuous segment of a string

### 🔹 Subsequence
- Characters appear in order
- Not necessarily contiguous

Example:
```cpp
S = "abcde"
T = "ace" → subsequence ✅
T = "aec" → NOT a subsequence ❌
```

### 🔹 Two Pointer Technique
- Forward scanning
- Backward contraction
- Careful pointer control

---

## 🧠 Key Observations

- We must **preserve order** of characters in `T`
- Frequency maps do NOT help here
- Brute force checking all substrings is too slow
- We need a **smart scanning strategy**

---

## 🎯 Intuition

The optimal strategy works in **two phases**:

### 🔁 Phase 1: Forward Scan
- Try to match `T` as a subsequence in `S`
- Once all characters of `T` are matched:
  - We have a **valid window ending at index `end`**

### 🔁 Phase 2: Backward Contraction
- Move backward from `end`
- Try to shrink the window while keeping `T` as a subsequence
- This gives the **minimum window for this match**

Repeat this process to find the **global minimum window**.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- Generate all substrings of `S`
- Check if `T` is a subsequence of each substring

### ⏱️ Complexity
- **Time:** O(n³)
- **Space:** O(1)

❌ Extremely slow  
❌ Not interview-acceptable  

---

## 🟢 Approach 2: Two Pointers (Optimal & Expected)

### ⭐ Most Important Approach

This is the **standard interview solution**.

⚠️ Important Note:
Although a greedy forward + backward two-pointer approach may work for some cases,
it is NOT reliable for all inputs on GFG (especially with overlapping subsequences
and repeated characters).

The Dynamic Programming solution is the ONLY approach that guarantees correctness
for all test cases and is therefore used in the final implementation.


---

## 🔁 Two-Pointer + Backtracking Strategy

### 💡 Core Idea

1. Scan `S` forward to match all characters of `T`
2. Once matched:
   - Fix `end`
3. Move backward to minimize the window
4. Update answer
5. Restart search from next position

---

## ✍️ Pseudocode
```cpp
minLen = infinity
start = -1

i = 0
while i < len(S):
j = 0
// Forward scan
while i < len(S):
    if S[i] == T[j]:
        j++
        if j == len(T):
            break
    i++

if j != len(T):
    break

end = i
j = len(T) - 1

// Backward contraction
while i >= 0:
    if S[i] == T[j]:
        j--
        if j < 0:
            break
    i--

i++
if end - i + 1 < minLen:
    minLen = end - i + 1
    start = i

i = i + 1

return substring from start with length minLen
```


---

## 🧪 Dry Run Example

### Input
```cpp
S = "abcdebdde"
T = "bde"
```


### Steps
- Forward match: `b → d → e`
- Backward shrink window
- Minimum window found: `"bdde"`

### ✅ Output
```cpp
"bdde"
```

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n × m)** |
| Space Complexity | **O(1)** |
| Technique | Two pointers + backtracking |

---

## ⚠️ Edge Cases

- `T` longer than `S`
- `T` not present as subsequence
- `S` or `T` empty
- Multiple valid windows → choose minimum

---

## 🧩 Interview Tips

- Clearly explain **difference between substring vs subsequence**
- Mention why frequency-based sliding window fails
- Walk through **forward + backward logic**
- Draw pointer movement if needed

---

## ✅ Final Notes

- This is a **high-value interview problem**
- Commonly confused with:
  - Minimum Window Substring
- Strengthens:
  - Pointer control
  - Subsequence logic
  - Window minimization

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-11 README Completed Successfully!**  
🚀 *Two-pointer subsequence window mastered.*

