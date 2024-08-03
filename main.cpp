#include <iostream>

class MergeSort {
public:
    int arraySize; // Number of elements in the array
    int array[10]; // Array to store elements (size limited to 10)
    void getArray(); // Method to get array elements from the user
    void mergeSort(int[], int, int); // Method to perform merge sort
    void merge(int[], int, int, int); // Method to merge sorted subarrays
    void display(); // Method to display the sorted array
};

// Method to get array elements from the user
void MergeSort::getArray() {
    std::cout << "\nEnter the number of elements: ";
    std::cin >> arraySize; // Read the number of elements
    if (arraySize > 10) {
        std::cerr << "Error: Number of elements exceeds array size limit." << std::endl;
        arraySize = 10; // Limit the number of elements to the array size
    }
    std::cout << "\nEnter the array elements to sort: ";
    for (int i = 0; i < arraySize; i++) {
        std::cin >> array[i]; // Read each element into the array
    }
}

// Method to perform merge sort on the array
void MergeSort::mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2; // Find the middle point
        mergeSort(arr, low, mid); // Recursively sort the first half
        mergeSort(arr, mid + 1, high); // Recursively sort the second half
        merge(arr, low, mid, high); // Merge the sorted halves
    }
}

// Method to merge two sorted subarrays into a single sorted subarray
void MergeSort::merge(int arr[], int low, int mid, int high) {
    int leftIndex = low; // Starting index of the left subarray
    int rightIndex = mid + 1; // Starting index of the right subarray
    int mergedIndex = low; // Starting index for the merged array
    int tempArray[10]; // Temporary array to store merged results

    // Merge elements from both subarrays
    while (leftIndex <= mid && rightIndex <= high) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            tempArray[mergedIndex++] = arr[leftIndex++]; // Add smaller element to tempArray
        } else {
            tempArray[mergedIndex++] = arr[rightIndex++]; // Add smaller element to tempArray
        }
    }

    // Copy any remaining elements from the left subarray
    while (leftIndex <= mid) {
        tempArray[mergedIndex++] = arr[leftIndex++];
    }

    // Copy any remaining elements from the right subarray
    while (rightIndex <= high) {
        tempArray[mergedIndex++] = arr[rightIndex++];
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = tempArray[i];
    }
}

// Method to display the sorted array
void MergeSort::display() {
    std::cout << "\nThe sorted elements: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << array[i] << " "; // Print each element of the sorted array
    }
    std::cout << std::endl;
}

int main() {
    MergeSort sorter; // Create an instance of MergeSort
    sorter.getArray(); // Get the array elements from the user
    sorter.mergeSort(sorter.array, 0, sorter.arraySize - 1); // Perform merge sort
    sorter.display(); // Display the sorted array
    return 0;
}
