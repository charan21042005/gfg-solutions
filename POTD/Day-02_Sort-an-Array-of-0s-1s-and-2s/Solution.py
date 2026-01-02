class Solution:
    def sort012(self, arr):
        low = 0                  # boundary for 0s
        mid = 0                  # current index
        high = len(arr) - 1      # boundary for 2s

        # Traverse array until mid crosses high
        while mid <= high:

            # Case 1: element is 0
            if arr[mid] == 0:
                arr[low], arr[mid] = arr[mid], arr[low]
                low += 1
                mid += 1

            # Case 2: element is 1
            elif arr[mid] == 1:
                mid += 1

            # Case 3: element is 2
            else:
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1
                # mid is not incremented here
