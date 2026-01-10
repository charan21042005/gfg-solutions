# Count Number of Substrings

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given a **string `s` consisting of lowercase characters**.  
Your task is to **count the number of substrings that contain all three characters `'a'`, `'b'`, and `'c'` at least once**.

This problem is a **classic string + sliding window problem**, commonly asked to test:
- Understanding of **substrings**
- Efficient **window expansion and contraction**
- Logical counting of valid substrings

---

## 📥 Input Description

- A string `s` of length `n`
- Characters are from `{ 'a', 'b', 'c' }`

---

## 📤 Output Description

- Return an integer representing the **number of substrings containing all three characters `'a'`, `'b'`, and `'c'`**

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Strings & Substrings
- Substring = contiguous part of a string
- Total substrings in a string of length `n` = `n * (n + 1) / 2`

### 🔹 Sliding Window Technique
- Two pointers (`left` and `right`)
- Expand window to satisfy condition
- Shrink window to count efficiently

### 🔹 Frequency Counting
- Tracking presence of required characters
- Using array or hash map for counts

---

## 🧠 Key Observations

- We only care about **presence**, not frequency, of `'a'`, `'b'`, and `'c'`
- Brute force checking all substrings is inefficient
- Once a window contains all three characters:
  - Any extension of this window to the right will also be valid

---

## 🎯 Intuition

Instead of checking every substring:

1. Use a **sliding window**
2. Expand the window until it contains `'a'`, `'b'`, and `'c'`
3. Once valid:
   - All substrings starting at `left` and ending from `right` to end of string are valid
4. Shrink from the left to find new valid windows

This allows us to count multiple substrings **in one step**.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- Generate all substrings
- Check if each contains `'a'`, `'b'`, and `'c'`

### ⏱️ Complexity
- **Time**: O(n²)
- **Space**: O(1)

❌ Too slow  
❌ Fails for large strings

---

## 🟢 Approach 2: Sliding Window (Optimal & Expected)

### ⭐ Most Important Approach

This is the **standard interview solution**.

---

## 🔁 Sliding Window Strategy

### 💡 Core Idea

- Maintain a window `[left … right]`
- Track frequency of `'a'`, `'b'`, `'c'`
- When all three are present:
  - Count substrings
  - Shrink window from the left

---

## ✍️ Pseudocode
```cpp
freq[3] = {0, 0, 0}
left = 0
count = 0

for right from 0 to n-1:
freq[s[right]]++

while freq['a'] > 0 and freq['b'] > 0 and freq['c'] > 0:
    count += (n - right)
    freq[s[left]]--
    left++

return count
```

---

## 🧪 Dry Run Example

### Input
```cpp
s = "abcabc"
```

### Explanation

- At right = 2 → "abc" → valid
  - All substrings starting at left and ending at ≥ right are valid
- Count increases by `(n - right)`
- Move left forward and continue

### ✅ Output
```cpp
10
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

- String length < 3 → answer is 0
- String with missing `'a'`, `'b'`, or `'c'`
- All characters same
- Minimum valid substring `"abc"`

---

## 🧩 Interview Tips

- Clearly explain **why `(n - right)` substrings are counted**
- Emphasize **contiguous substrings**
- Mention brute force first, then optimize
- Use fixed-size array instead of hashmap for speed

---

## ✅ Final Notes

- This is a **must-know sliding window string problem**
- Very common in:
  - Product-based company interviews
  - Substring counting patterns
- Strengthens understanding of:
  - Window shrinking logic
  - Efficient counting techniques

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-10 README Completed Successfully!**  
🚀 *Sliding Window on Strings mastered step by step.*

