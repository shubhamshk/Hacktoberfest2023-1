#include <iostream>
#include <vector>

// Binary search function to find the index of a target element in a sorted array
int binarySearch(const std::vector<int>& arr, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is smaller than the middle element, then it can only be present in the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, target, low, mid - 1);
        }

        // Else the target can only be present in the right subarray
        return binarySearch(arr, target, mid + 1, high);
    }

    // If the element is not present in the array
    return -1;
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;

    std::cout << "Enter the element to search: ";
    std::cin >> target;

    int result = binarySearch(sortedArray, target, 0, sortedArray.size() - 1);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
