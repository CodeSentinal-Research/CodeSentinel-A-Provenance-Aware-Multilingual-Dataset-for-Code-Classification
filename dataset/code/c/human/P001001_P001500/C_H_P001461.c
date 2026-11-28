// Problem: Two Sum II - Sorted Array
// Difficulty: Easy | Topic: Two Pointers
//
// Given a 1-indexed sorted array, find two numbers that add up to target.
// Return their indices (1-indexed) via out parameters.
//
// Key insight: Since array is sorted, use two pointers from both ends!
//
// ============ LANGUAGE BRIDGE (for JS/Python/Go devs) ============
//
// | JS/Python               | C equivalent                         |
// |-------------------------|--------------------------------------|
// | let l=0, r=arr.length-1 | int l=0, r=n-1;  (n passed separately)|
// | while (l < r)           | while (l < r)                        |
// | arr[l], arr[r]          | numbers[l], numbers[r]               |
// | return [l+1, r+1]       | *idx1 = l+1; *idx2 = r+1; return 1;  |
//
// C GOTCHAS:
// - Arrays don't know their length! You MUST pass `n` separately
// - Can't return multiple values - use pointers (out parameters)
// - int* idx1 means "pointer to int" - use *idx1 to set the value
// - & means "address of": two_sum(arr, n, target, &result1, &result2)
// - No bounds checking! arr[100] on size-5 array = undefined behavior

#include <stdio.h>
#include <assert.h>

// Returns 1 on success, 0 on failure
// Results stored in *idx1 and *idx2 (1-indexed)
int two_sum(int* numbers, int n, int target, int* idx1, int* idx2) {
    // TODO: Implement using two pointers technique
    // Hint: Use left pointer at start, right pointer at end
    // If sum too small, move left pointer right
    // If sum too big, move right pointer left
    int l = 0;
    int r = n -1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target) {
            *idx1 = l + 1;
            *idx2 = r + 1;
            return 1;
         } else if (sum < target) {
             l++;
         } else {
             r--;
         }
    }

    return 0; // Replace with your implementation
}

// ==================== TESTS ====================

void test_basic_case() {
    int nums[] = {2, 7, 11, 15};
    int idx1, idx2;
    int result = two_sum(nums, 4, 9, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 1 && idx2 == 2);
    printf("Test basic_case: PASSED\n");
}

void test_not_adjacent() {
    int nums[] = {2, 3, 4};
    int idx1, idx2;
    int result = two_sum(nums, 3, 6, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 1 && idx2 == 3);
    printf("Test not_adjacent: PASSED\n");
}

void test_negative_numbers() {
    int nums[] = {-1, 0};
    int idx1, idx2;
    int result = two_sum(nums, 2, -1, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 1 && idx2 == 2);
    printf("Test negative_numbers: PASSED\n");
}

void test_negative_target() {
    int nums[] = {-3, -1, 0, 1, 2};
    int idx1, idx2;
    int result = two_sum(nums, 5, -2, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 1 && idx2 == 4);
    printf("Test negative_target: PASSED\n");
}

void test_zero_target() {
    int nums[] = {-2, -1, 0, 1, 2};
    int idx1, idx2;
    int result = two_sum(nums, 5, 0, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 1 && idx2 == 5);
    printf("Test zero_target: PASSED\n");
}

void test_duplicates_in_array() {
    // 3 + 3 = 6 (only valid pair: 1+7=8, 1+3=4, 3+3=6)
    int nums[] = {1, 3, 3, 7};
    int idx1, idx2;
    int result = two_sum(nums, 4, 6, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 2 && idx2 == 3);
    printf("Test duplicates_in_array: PASSED\n");
}

void test_large_numbers() {
    int nums[] = {-500, 0, 500, 500};
    int idx1, idx2;
    int result = two_sum(nums, 4, 1000, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 3 && idx2 == 4);
    printf("Test large_numbers: PASSED\n");
}

void test_minimum_length() {
    int nums[] = {1, 2};
    int idx1, idx2;
    int result = two_sum(nums, 2, 3, &idx1, &idx2);
    assert(result == 1);
    assert(idx1 == 1 && idx2 == 2);
    printf("Test minimum_length: PASSED\n");
}

int main() {
    printf("\n=== Two Sum II - Two Pointers ===\n\n");

    test_basic_case();
    test_not_adjacent();
    test_negative_numbers();
    test_negative_target();
    test_zero_target();
    test_duplicates_in_array();
    test_large_numbers();
    test_minimum_length();

    printf("\n✓ All tests passed!\n\n");
    return 0;
}
