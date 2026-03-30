/*                                                   
Problem: Removing Duplicates from a Sorted Array
Platform: LeetCode / Striver A2Z
Topic: Arrays
Difficulty: Easy

-----------------------------------

Brute Force:
- Use a set (STL) to store only unique elements
- Traverse the array and insert elements into the set
- Copy elements from set back into array

Time Complexity: O(n log n) (insertion in set takes log n)
Space Complexity: O(n)
    
-----------------------------------

Optimal Approach:
- Use two pointer technique

- Initialize pointer i = 0 (tracks unique elements)
- Traverse array with pointer j from 1 to n-1

- If arr[j] != arr[i]:
    -> increment i
    -> set arr[i] = arr[j]

- At the end, first (i+1) elements are unique

Time Complexity: O(n)
Space Complexity: O(1)

-----------------------------------

Why this works:
- Since array is already sorted, duplicates are adjacent
- We only keep track of unique elements in-place

-----------------------------------

Edge Cases:
- Empty array → return 0
- Single element → return 1
- All elements same → return 1
- Already unique array → return n

-----------------------------------
*/


#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 0; 

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; 
}


int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
