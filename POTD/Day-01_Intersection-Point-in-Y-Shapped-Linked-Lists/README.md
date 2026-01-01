# Intersection Point in Y Shapped Linked Lists

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

---

## 📌 Problem Overview

You are given **two singly linked lists** that merge at some point and form a **Y-shaped structure**.

Your task is to **find the data value of the node** at which the two linked lists intersect.

If the linked lists do **not intersect**, return **-1**.

---

## 📥 Input Description

- Two head pointers:
  - `head1` → head of first linked list
  - `head2` → head of second linked list
- The linked lists may have **different lengths**
- After the intersection point, **both lists share the same nodes**

---

## 📤 Output Description

- Return the **data value** of the intersection node
- If no intersection exists, return **-1**

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, it is important to understand:

### 🔹 Singly Linked List
- Each node contains:
  - `data`
  - `next` pointer
- Nodes are connected sequentially

### 🔹 Y-Shaped Linked List
- Two separate linked lists
- They **merge at one common node**
- After merging, they share the **same tail**

List 1: 1 → 2 → 3
↘
6 → 7 → NULL
↗
List 2: 4 → 5


Here, **6** is the intersection point.

---

## 🧠 Key Observations

- Intersection happens **by reference**, not by value
- After intersection:
  - Both lists point to the **same memory nodes**
- Comparing `data` is NOT sufficient
- We must detect the **same node**

---

## 🎯 Problem Intuition

If two linked lists intersect:
- The remaining length after the intersection node is **equal** for both lists
- By aligning both lists at the same distance from the end, we can find the intersection

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Brute Force (Not Recommended)

### 💡 Idea
- For every node in list 1:
  - Traverse list 2 and check if any node matches

### ❌ Drawback
- Very slow for large lists

### ⏱️ Complexity
- **Time**: O(N × M)
- **Space**: O(1)

---

## 🟡 Approach 2: Hashing (Extra Space)

### 💡 Idea
- Store all nodes of first list in a hash set
- Traverse second list
- First node found in the set is the intersection

### ⏱️ Complexity
- **Time**: O(N + M)
- **Space**: O(N)

---

## 🟢 Approach 3: Length Difference Method (Optimal)

### 💡 Core Idea
1. Find lengths of both linked lists
2. Calculate the absolute difference
3. Move the pointer of the longer list ahead by the difference
4. Traverse both lists together
5. First common node is the intersection

---

## ✍️ Pseudocode
```cpp
get length of list1 → len1
get length of list2 → len2

diff = abs(len1 - len2)

if len1 > len2:
move head1 ahead by diff
else:
move head2 ahead by diff

while head1 != NULL and head2 != NULL:
if head1 == head2:
return head1.data
head1 = head1.next
head2 = head2.next

return -1
```

---

## 🧪 Dry Run Example

### Example Input
List1: 10 → 15 → 30

List2: 3 → 6 → 9 →

15 → 30


### Step-by-Step Execution

- Length of List1 = 3
- Length of List2 = 5
- Difference = 2

Move List2 pointer ahead by 2:

List1: 10 → 15 → 30
List2: 9 → 15 → 30


Now traverse together:
- 10 ≠ 9
- 15 == 15 → Intersection found

### ✅ Output
15


---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(N + M)** |
| Space Complexity | **O(1)** |

---

## ⚠️ Edge Cases to Handle

- One or both lists are empty
- No intersection exists
- Intersection at the head node
- Lists of equal length

---

## 🧩 Interview Tips

- Always clarify: **intersection by reference**
- Mention why value comparison is incorrect
- Prefer **O(1) space solution**
- Draw Y-shaped diagram while explaining

---

## ✅ Final Notes

- This is a **classic Linked List interview problem**
- Frequently asked in:
  - Product-based companies
  - Service-based coding rounds
- Mastering this problem builds strong intuition for:
  - Linked list traversal
  - Pointer manipulation

---

📌 **Day 01 Completed Successfully!**  
🚀 *Consistency starts with clarity.*


