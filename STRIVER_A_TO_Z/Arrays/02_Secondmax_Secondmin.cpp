/*                       
Problem: Second Largest and Second Smallest Element
Platform: Striver A2Z
Topic: Arrays
Difficulty: Easy

-----------------------------------

Brute Force:
- Sort the array in ascending order
- Traverse from start to find first element different from arr[0] → second smallest
- Traverse from end to find first element different from arr[n-1] → second largest

Time Complexity: O(n log n)
Space Complexity: O(1)

-----------------------------------

Better Approach:
- First find largest and smallest element
- Then traverse again:
    - If element < largest and > secondLargest → update secondLargest
    - If element > smallest and < secondSmallest → update secondSmallest

Time Complexity: O(2n)
Space Complexity: O(1)

-----------------------------------

Optimal Approach:
- Initialize:
    largest = arr[0], secondLargest = -1 (or) INT_MIN
    smallest = arr[0], secondSmallest = INT_MAX

- Traverse array once:
    - If arr[i] > largest:
        secondLargest = largest
        largest = arr[i]
    - Else if arr[i] < largest AND arr[i] > secondLargest:
        secondLargest = arr[i]

    - If arr[i] < smallest:
        secondSmallest = smallest
        smallest = arr[i]
    - Else if arr[i] > smallest AND arr[i] < secondSmallest:
        secondSmallest = arr[i]

Time Complexity: O(n)
Space Complexity: O(1)

-----------------------------------

Edge Cases:
- If n < 2 → return -1
- If all elements are equal → no second largest/smallest
- Handle negative numbers correctly
- Duplicates should not be counted as second largest/smallest

-----------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n){
    if(n<2)
    return -1;
    int largest=arr[0];
    int second_largest=INT_MIN;
    for(int i=0; i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        } else if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }
    return second_largest;
}
    int secondSmallest(int arr[] ,int n){
        if(n<2){
            return -1;
        }
        int smallest=arr[0];
        int second_smallest=INT_MAX;
        for(int i=0; i<n; i++){
            if(arr[i] < smallest){
                second_smallest=smallest;
                smallest=arr[i];
            } else if(arr[i] < second_smallest && arr[i]!=smallest){
                second_smallest=arr[i];
            }
        }
        return second_smallest;
    }

int main(){
    int arr[]={1,4,5,63,53,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sec_small=secondSmallest(arr,n);
    int sec_max=secondLargest(arr,n);
    cout<<"Second Smallest is "<<sec_small<<endl;
    cout<<"Second Largest is "<<sec_max<<endl;
    return 0;
}
