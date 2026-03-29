/*                
Problem: Check if Array is Sorted          
Platform: Striver A2Z
Topic: Arrays
Difficulty: Easy

-----------------------------------

Brute Force:
- Compare every element with all elements after it
- If any arr[i] > arr[j] where j > i → array is not sorted
- Otherwise, array is sorted

Time Complexity: O(n^2)
Space Complexity: O(1)             

-----------------------------------

Optimal Approach:
- Traverse the array from index 1 to n-1
- Compare current element with previous element
- If arr[i] < arr[i-1] → return false
- If no such case is found → return true

Time Complexity: O(n)
Space Complexity: O(1)

-----------------------------------

Why this works:
- In a sorted array, every element must be greater than or equal to the previous one

-----------------------------------

Edge Cases:
- Empty array → considered sorted
- Single element → always sorted
- Duplicate elements → still sorted
- Negative numbers → works correctly

-----------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

bool sortedArray(int arr[],int n){
    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            return false;
        } else{
            return true;
        }
    }
}
int main(){
    int arr[]={1,4,5,35,53};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(sortedArray(arr, n)){
        cout << "Array is sorted";
    } else{
        cout << "Array is not sorted";
    }
}
