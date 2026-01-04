# Check if Linked List is Palindrome

🔗 **Problem Link**:  
https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

🟠 **Difficulty:** Medium

---

## 📌 Problem Overview

You are given the **head of a singly linked list**.  
Your task is to **check whether the linked list is a palindrome**.

A linked list is said to be a **palindrome** if the sequence of values read **from left to right** is the same as **from right to left**.

---

## 📥 Input Description

- A pointer `head` pointing to the first node of a singly linked list
- Each node contains:
  - `data`
  - `next` pointer

---

## 📤 Output Description

- Return **true / 1** if the linked list is a palindrome
- Return **false / 0** otherwise

---

## 📚 Prerequisite Concepts (Must Know)

Before solving this problem, you should understand:

### 🔹 Singly Linked List
- One-directional traversal
- No direct access to previous node
- Pointer manipulation

### 🔹 Palindrome Concept
- Sequence that reads the same forward and backward
- Examples:
  - `1 → 2 → 2 → 1` ✅
  - `1 → 2 → 3` ❌

### 🔹 Fast & Slow Pointer Technique
- Used to find the **middle of the linked list**
- Commonly used in linked list interview problems

### 🔹 Reversing a Linked List
- Iterative pointer reversal
- Very important linked list skill

---

## 🧠 Key Observations

- We **cannot traverse backward** in a singly linked list
- Direct comparison from both ends is not possible
- We must manipulate pointers carefully
- The solution should ideally use **O(1) extra space**

---

## 🎯 Intuition

To check palindrome efficiently:
1. Find the **middle** of the linked list
2. Reverse the **second half**
3. Compare the **first half** and **second half**
4. If all corresponding nodes match → palindrome

This avoids extra memory and works in linear time.

---

## 🛠️ Approaches to Solve

---

## 🔴 Approach 1: Convert to Array (Brute Force)

### 💡 Idea
- Traverse linked list
- Store values in an array
- Check if array is palindrome

### ⏱️ Complexity
- **Time**: O(n)
- **Space**: O(n)

✔ Easy to understand  
❌ Uses extra space  
❌ Not optimal for interviews

---

## 🟡 Approach 2: Stack Method

### 💡 Idea
- Push first half elements into a stack
- Compare with second half while popping

### ⏱️ Complexity
- **Time**: O(n)
- **Space**: O(n)

✔ Better than brute force  
❌ Still uses extra space

---

## 🟢 Approach 3: Reverse Second Half (Optimal & Expected)

### ⭐ Most Important Approach

This is the **best and most commonly expected interview solution**.

---

## 🔗 Core Idea (Optimal Approach)

1. Use **slow & fast pointers** to find the middle
2. Reverse the second half of the list
3. Compare both halves node by node
4. If all values match → palindrome

---

## ✍️ Pseudocode
```cpp
if head is NULL or head.next is NULL:
return true

slow = head
fast = head

while fast and fast.next:
slow = slow.next
fast = fast.next.next

reverse second half starting from slow

first = head
second = reversed list

while second:
if first.data != second.data:
return false
first = first.next
second = second.next

return true
```

---

## 🧪 Dry Run Example

### Example 1

Input: 1 → 2 → 2 → 1


### Step-by-Step

- Find middle → slow at `2`
- Reverse second half → `1 → 2`
- Compare:
  - 1 == 1 ✅
  - 2 == 2 ✅

### ✅ Output
True

---

### Example 2

Input: 1 → 2 → 3


- Compare:
  - 1 != 3 ❌

### ❌ Output
False


---

## ⏱️ Time & Space Complexity

| Metric | Value |
|------|------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(1)** |
| Technique | Reverse Second Half |

---

## ⚠️ Edge Cases

- Empty list
- Single node list
- Two node list
- Odd length list
- Even length list

---

## 🧩 Interview Tips

- Always mention **why backward traversal is not possible**
- Explain slow–fast pointer usage clearly
- Mention space optimization
- If asked, explain how to **restore the list back** (optional)

---

## ✅ Final Notes

- This is a **must-know linked list interview problem**
- Very common in:
  - Product-based companies
  - Service-based coding rounds
- Strengthens understanding of:
  - Pointer manipulation
  - Linked list reversal
  - Two-pointer technique

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

---

📌 **Day-04 Completed Successfully!**  
🚀 *Linked Lists mastered with confidence.*


