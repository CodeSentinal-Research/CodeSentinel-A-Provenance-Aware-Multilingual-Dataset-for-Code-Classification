#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 1A: Find smallest positive integer missing from unsorted array
int findSmallestMissingPositiveUnsorted(int arr[], int size) {
    // Using a hash set approach with array (for positive integers)
    int* present = (int*)malloc((size + 2) * sizeof(int));
    for (int i = 0; i <= size + 1; i++) {
        present[i] = 0;
    }
    
    // Mark which numbers are present
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] <= size) {
            present[arr[i]] = 1;
        }
    }
    
    // Find the smallest missing positive
    for (int i = 1; i <= size + 1; i++) {
        if (!present[i]) {
            free(present);
            return i;
        }
    }
    
    free(present);
    return size + 1;
}

// 1B: Count occurrences of each word in text
void countWordOccurrences(const char* text) {
    printf("\n=== 1B: Count Word Occurrences ===\n");
    
    // Make a copy for strtok
    char* textCopy = (char*)malloc(strlen(text) + 1);
    strcpy(textCopy, text);
    
    // Dynamic array to store words and counts
    char** words = (char**)malloc(sizeof(char*) * 100);
    int* counts = (int*)malloc(sizeof(int) * 100);
    int uniqueCount = 0;
    
    // Tokenize and count
    char* token = strtok(textCopy, " .,!?;:\n\t");
    while (token != NULL) {
        // Convert to lowercase for case-insensitive comparison
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        
        // Check if word already exists
        int found = 0;
        for (int i = 0; i < uniqueCount; i++) {
            if (strcmp(words[i], token) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }
        
        // Add new word if not found
        if (!found) {
            words[uniqueCount] = (char*)malloc(strlen(token) + 1);
            strcpy(words[uniqueCount], token);
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
        
        token = strtok(NULL, " .,!?;:\n\t");
    }
    
    // Display results
    printf("Word Occurrences:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }
    
    // Free memory
    for (int i = 0; i < uniqueCount; i++) {
        free(words[i]);
    }
    free(words);
    free(counts);
    free(textCopy);
}

// 1C: Find smallest missing positive from SORTED array
int findSmallestMissingPositive(int arr[], int size) {
    // For sorted array, we can directly check
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
}

// 1D: Binary search for word in sorted array
int binarySearchWords(char* words[], int size, char* target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(words[mid], target);
        
        if (cmp == 0) {
            return mid;  // Found at index mid
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Not found
}

// Main function with test cases
int main() {
    printf("=== DSA Assignment: Arrays and Search ===\n\n");
    
    // 1A: Test
    printf("=== 1A: Find Smallest Missing Positive (Unsorted) ===\n");
    int arr1A[] = {1, 2, 0, 4, 5};
    printf("Array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr1A[i]);
    printf("\nSmallest missing positive: %d\n\n", findSmallestMissingPositiveUnsorted(arr1A, 5));
    
    int arr1A2[] = {3, 4, -1, 1};
    printf("Array: ");
    for (int i = 0; i < 4; i++) printf("%d ", arr1A2[i]);
    printf("\nSmallest missing positive: %d\n\n", findSmallestMissingPositiveUnsorted(arr1A2, 4));
    
    // 1B: Test
    char text[] = "Hello world hello programming world!";
    countWordOccurrences(text);
    
    // 1C: Test
    printf("\n=== 1C: Find Smallest Missing Positive (Sorted) ===\n");
    int arr1C[] = {1, 2, 3, 5, 6};
    printf("Sorted Array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr1C[i]);
    printf("\nSmallest missing positive: %d\n\n", findSmallestMissingPositive(arr1C, 5));
    
    // 1D: Test
    printf("=== 1D: Binary Search for Word ===\n");
    char* words[] = {"apple", "banana", "cherry", "grape", "orange", "peach"};
    char* target = "grape";
    int index = binarySearchWords(words, 6, target);
    printf("Words: apple, banana, cherry, grape, orange, peach\n");
    printf("Target: %s\n", target);
    if (index != -1) {
        printf("Found at index: %d\n", index);
    } else {
        printf("Not found\n");
    }
    
    printf("\nTarget: mango\n");
    index = binarySearchWords(words, 6, "mango");
    if (index != -1) {
        printf("Found at index: %d\n", index);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}