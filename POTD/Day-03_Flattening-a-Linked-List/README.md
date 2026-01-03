# Flattening a Linked List

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given a **special linked list** where:
- Each node has **two pointers**:
  - `next` → points to the next list on the right
  - `bottom` → points to a linked list downward

Each vertical (`bottom`) linked list is already **sorted**.

Your task is to **flatten the entire structure into a single sorted linked list** using only the `bottom` pointer.  
The `next` pointer should be ignored in the final flattened list.

---

## 📥 Input Description

- A head pointer of a linked list
- Each node contains:
  - `data`
  - `next` pointer
  - `bottom` pointer
- All individual bottom-linked lists are **sorted**

---

## 📤 Output Description

- Return the head of a **single sorted linked list**
- The final list must use **only `bottom` pointers**
- All `next` pointers should be ignored

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you must understand:

### 🔹 Linked Lists
- Singly linked list traversal
- Pointer manipulation
- Merging two sorted linked lists

### 🔹 Multi-level Linked Lists
- Nodes can point in **two directions**
- Similar to flattening a 2D structure

### 🔹 Recursion
- Breaking problem into smaller subproblems
- Useful for flattening step by step

---

## 🧠 Key Observations

- Each vertical list is **already sorted**
- The main list (`next`) connects multiple sorted lists
- This problem is similar to:
  - Merging **K sorted linked lists**
- Final result must be sorted and linear

---

## 🎯 Intuition

If we:
1. Flatten the list on the right (`next`)
2. Then merge the current list with the flattened right list

Eventually, we’ll get a **single sorted list**.

This is similar to:
- Merge Sort logic
- Divide → Solve → Merge

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Store All Elements & Sort (Not Recommended)

### 💡 Idea
- Traverse entire structure
- Store all values in an array
- Sort the array
- Rebuild linked list

### ❌ Why Not Recommended
- Extra space usage
- Loses pointer manipulation practice
- Interviewers expect pointer-based solution

### ⏱️ Complexity
- **Time**: O(N log N)
- **Space**: O(N)

---

## 🟡 Approach 2: Using Min Heap (Advanced)

### 💡 Idea
- Push heads of all vertical lists into a min heap
- Extract minimum and insert next bottom node

### ⏱️ Complexity
- **Time**: O(N log K)
- **Space**: O(K)

✔ Efficient  
❌ Overkill for this problem  
❌ Not expected in basic interviews

---

## 🟢 Approach 3: Recursive Merge (Optimal & Expected)

### ⭐ Most Important Approach

This is the **best and most commonly expected solution**.

---

## 🔗 Core Idea (Recursive Flatten + Merge)

1. Base Case:
   - If list is empty or has only one column → return it
2. Recursively flatten the `next` list
3. Merge current list with the flattened right list
4. Return merged list

---

## ✍️ Pseudocode

```cpp
function flatten(head):
if head is NULL or head.next is NULL:
return head

head.next = flatten(head.next)
head = merge(head, head.next)

return head


function merge(a, b):
if a is NULL: return b
if b is NULL: return a

if a.data < b.data:
    result = a
    result.bottom = merge(a.bottom, b)
else:
    result = b
    result.bottom = merge(a, b.bottom)

result.next = NULL
return result
```

---

## 🧪 Dry Run Example

### Given Structure
```cpp
5 → 10 → 19 → 28
| | | |
7 20 22 35
| | |
8 50 40
| |
30 45
```

---

### Step-by-Step

1️⃣ Flatten list starting from rightmost (`28`)  

→ produces sorted list  

2️⃣ Merge `19` list with flattened `28` list  

3️⃣ Merge `10` list with result  

4️⃣ Merge `5` list with result  

---

### ✅ Final Output (bottom pointers)

```cpp
5 → 7 → 8 → 10 → 19 → 20 → 22 → 28 → 30 → 35 → 40 → 45 → 50
```

---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(N)** |
| Space Complexity | **O(1)** (excluding recursion stack) |
| Technique | Recursive Merge |

---

## ⚠️ Edge Cases

- Empty list
- Single vertical list
- All nodes in one column
- Duplicate values

---

## 🧩 Interview Tips

- Explain similarity to **merge sort**
- Emphasize merging two sorted linked lists
- Mention why `next` pointer is set to NULL
- Draw structure before explaining

---

## ✅ Final Notes

- This is a **classic multi-level linked list problem**
- Frequently asked in:
  - Product-based companies
  - Linked list heavy interviews
- Builds mastery in:
  - Pointer handling
  - Recursion
  - Linked list merging

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-03 Completed Successfully!**  
🚀 *Linked Lists mastered one level deeper.*




