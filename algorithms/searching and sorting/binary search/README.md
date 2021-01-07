# Binary Search

## What is binary search? How does it function?
- Binary search is a searching algorithm which takes a key element (that the user wants to search for) and compare it with the middle element in an array of elements. 
- If these two elements turn out to be equal, the search is said to be successful, since the desired element is found. 
- If the two elements are not the same, the array is divided into two parts. The left part of the array contains elements which are less than the middle element. The right part of the array contains elements which are greater than the middle element. 
- Hence, if the element that the user wants to search for is less than the middle element, we have to search in the left part of the array. Otherwise, we have to search in the right part of the array. 
- Repeat the same process of comparing the new middle element with the required element until the element is found, or until there are no more elements.

## Features of binary search
- The elements in the array should be sorted.
- Faster than linear search