#include <stdio.h>
#include <stdlib.h>
 
// Recursive function to find the peak element in an array
int findPeakElement(int nums[], int low, int high, int n)
{
    // find the middle element. To avoid overflow, use mid = low + (high - low) / 2
    int mid = (low + high) / 2;
 
    // check if the middle element is greater than its neighbors
    if ((mid == 0 || nums[mid - 1] <= nums[mid]) &&
            (mid == n - 1 || nums[mid + 1] <= nums[mid])) {
        return mid;
    }
 
    // If the left neighbor of `mid` is greater than the middle element, find the peak recursively in the left subarray
    if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
        return findPeakElement(nums, low, mid - 1, n);
    }
 
    // If the right neighbor of `mid` is greater than the middle element, find the peak recursively in the right subarray
    return findPeakElement(nums, mid + 1, high, n);
}
 
int findPeak(int nums[], int n)
{
    // base case
    if (n == 0) {
        exit(-1);
    }
 
    int index = findPeakElement(nums, 0, n - 1, n);
    return nums[index];
}
 
int main()
{
    int nums[] = { 8, 9, 10, 2, 5, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printf("The peak element is %d", findPeak(nums, n));
 
    return 0;
}
