# Minimum Number of Workers

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/minimum-sprinklers/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given an integer array `arr[]` of size `n`.

Each index represents a **time unit (hour)** in a working day from `0` to `n-1`.

- If `arr[i] != -1`, the person at index `i` can work and cover the time interval:

[i - arr[i], i + arr[i]]

- If `arr[i] == -1`, the person is **unavailable** and cannot cover any time.

Your task is to find the **minimum number of people (workers)** required to fully cover the working day from **time `0` to `n-1`**.

If it is **not possible** to cover the entire interval, return `-1`.

---

## 📥 Input Description

- `arr[]`: integer array where `arr[i]` denotes coverage range
- `n`: size of the array

---

## 📤 Output Description

- Return the **minimum number of workers** needed
- Return `-1` if full coverage is not possible

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Interval Coverage
- Each worker covers a continuous interval
- We must cover a full target range `[0, n-1]`

### 🔹 Greedy Algorithms
- Choose the interval that extends coverage the farthest
- Local optimal choice leads to global optimum

### 🔹 Sorting / Scanning
- Convert ranges into usable intervals
- Process intervals efficiently

---

## 🧠 Key Observations

- This is a **classic interval covering problem**
- Similar to:
- Minimum sprinklers
- Minimum taps to water a garden
- One worker can cover multiple time units
- Some time units may be impossible to cover

---

## 🎯 Intuition

Instead of thinking in terms of workers, think in terms of **intervals**.

Each valid worker provides an interval:
```cpp
left = max(0, i - arr[i])
right = min(n - 1, i + arr[i])
```

We want to:
- Start covering from time `0`
- At each step, choose the worker whose interval:
  - Starts **at or before** the current time
  - Extends **farthest to the right**

This greedy choice ensures:
- Minimum number of workers
- Maximum coverage at each step

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Feasible)

### 💡 Idea
- Try all combinations of workers
- Check if full coverage is possible

### ❌ Problems
- Exponential complexity
- Completely impractical

---

## 🟡 Approach 2: DP (Overkill)

### 💡 Idea
- Dynamic programming on coverage
- Track minimum workers for each prefix

### ❌ Problems
- High space & time usage
- Not required

---

## 🟢 Approach 3: Greedy Interval Coverage (Optimal & Expected)

### ⭐ Most Important Approach

This is the **correct and interview-expected solution**.

---

## 🔁 Greedy Interval Coverage Strategy

### 💡 Core Idea

1️⃣ Convert workers into valid intervals  
2️⃣ Sort / scan intervals by start  
3️⃣ Greedily select the interval that:
- Starts before or at current coverage
- Extends coverage the farthest

---

## ⚙️ Algorithm Steps

1. Initialize `currentEnd = 0`
2. Initialize `maxReach = 0`
3. Traverse all workers:
   - For those whose interval starts ≤ `currentEnd`
   - Track the maximum reachable right endpoint
4. Once no more extension is possible:
   - Fix a worker
   - Move `currentEnd = maxReach`
5. Repeat until:
   - `currentEnd >= n-1` → success
   - No extension possible → return `-1`

---

## ✍️ Pseudocode
```cpp
intervals = []

for i in range(n):
if arr[i] != -1:
L = max(0, i - arr[i])
R = min(n-1, i + arr[i])
intervals.append((L, R))

currentEnd = 0
maxReach = 0
count = 0
i = 0

while currentEnd < n:
found = false
while i < intervals.size and intervals[i].start <= currentEnd:
maxReach = max(maxReach, intervals[i].end)
i++
found = true

if not found:
    return -1

count++
currentEnd = maxReach + 1

return count
```


---

## 🧪 Dry Run Example

### Input
```cpp
arr = [1, 2, 1, 0]
```

### Intervals
```cpp
Index 0 → [0,1]
Index 1 → [0,3]
Index 2 → [1,3]
Index 3 → [3,3]
```


### Greedy Selection
- Choose interval `[0,3]`
- Covers entire range `[0,3]`

✅ Output: `1`

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |
| Technique | Greedy Interval Coverage |

---

## ⚠️ Edge Cases

- All `arr[i] = -1`
- First interval does not start at `0`
- Gaps in coverage
- Single worker covers entire range

---

## 🧩 Interview Tips

- Always relate to **interval covering**
- Explain why greedy works
- Mention similarity to **sprinklers / taps problems**
- Focus on extending coverage as far as possible

---

## ✅ Final Notes

- This is a **classic greedy interval problem**
- Appears in many variations across platforms
- Clean logic > complex structures

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-16 README Completed Successfully!**  
🚀 *Interval coverage + greedy mastery continues.*


