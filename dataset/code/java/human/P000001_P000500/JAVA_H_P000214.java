/**
 * CYCLIC SORT PATTERN
 * 
 * ===================
 * INTUITION
 * ===================
 * 
 * This pattern is specifically for arrays where:
 * - Elements are in a KNOWN RANGE (like 1 to n, or 0 to n-1)
 * - Each element should be at a specific index
 * 
 * The idea: each number has a "home" position.
 * Number 1 belongs at index 0, number 2 at index 1, etc.
 * We just keep swapping until everyone is home.
 * 
 * It's like sorting mail into mailboxes - each letter has exactly one place to go.
 * 
 * When to use?
 * - "find missing number" (in range 0 to n or 1 to n)
 * - "find duplicate"
 * - "find all missing numbers"
 * - "find first missing positive"
 * - Problems where elements are in range [1, n] or [0, n-1]
 * 
 * Why it works:
 * - Each element visits at most 2 positions (wrong spot, then right spot)
 * - So total swaps is O(n), making it O(n) time
 * 
 * Time: O(n)
 * Space: O(1) - in-place!
 */

import java.util.*;

class CyclicSort {

    // =====================================================
    // BASIC CYCLIC SORT
    // =====================================================
    
    /**
     * Sort array containing numbers from 1 to n
     * Each number should be at index (number - 1)
     */
    public void cyclicSort(int[] nums) {
        int i = 0;
        
        while (i < nums.length) {
            int correctIndex = nums[i] - 1; // where this number should be
            
            if (nums[i] != nums[correctIndex]) {
                // swap to put nums[i] in its correct position
                swap(nums, i, correctIndex);
                // don't increment i - check the swapped element
            } else {
                i++;
            }
        }
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // =====================================================
    // FIND MISSING NUMBER
    // =====================================================
    
    /**
     * Missing Number (LeetCode 268)
     * Array contains n numbers from 0 to n, one is missing
     * 
     * Put each number at its index, then find which index is wrong
     */
    public int missingNumber(int[] nums) {
        int i = 0;
        int n = nums.length;
        
        while (i < n) {
            // nums[i] should be at index nums[i]
            // but n doesn't have a spot (only indices 0 to n-1)
            if (nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums, i, nums[i]);
            } else {
                i++;
            }
        }
        
        // find the position where number doesn't match index
        for (i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        
        return n; // all 0 to n-1 are present, so n is missing
    }
    
    // Alternative using XOR (clever but less intuitive)
    public int missingNumberXOR(int[] nums) {
        int xor = nums.length;
        for (int i = 0; i < nums.length; i++) {
            xor ^= i ^ nums[i];
        }
        return xor;
    }
    
    /**
     * Find All Numbers Disappeared in Array (LeetCode 448)
     * Array of n numbers from 1 to n, some appear twice, some missing
     * Find all missing numbers
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        // cyclic sort
        int i = 0;
        while (i < nums.length) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                swap(nums, i, correctIndex);
            } else {
                i++;
            }
        }
        
        // find positions where nums[i] != i + 1
        List<Integer> missing = new ArrayList<>();
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                missing.add(i + 1);
            }
        }
        
        return missing;
    }
    
    // =====================================================
    // FIND DUPLICATES
    // =====================================================
    
    /**
     * Find the Duplicate Number (LeetCode 287)
     * n+1 numbers from 1 to n, exactly one duplicate
     * 
     * Method 1: Cyclic sort approach
     */
    public int findDuplicate(int[] nums) {
        int i = 0;
        
        while (i < nums.length) {
            if (nums[i] != i + 1) {
                int correctIndex = nums[i] - 1;
                if (nums[i] != nums[correctIndex]) {
                    swap(nums, i, correctIndex);
                } else {
                    // found duplicate! nums[i] == nums[correctIndex]
                    return nums[i];
                }
            } else {
                i++;
            }
        }
        
        return -1;
    }
    
    // Method 2: Floyd's cycle detection (doesn't modify array)
    public int findDuplicateFloyd(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // find meeting point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // find entrance to cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    /**
     * Find All Duplicates in Array (LeetCode 442)
     * Array of n numbers from 1 to n, some appear twice
     * Find all duplicates
     */
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> duplicates = new ArrayList<>();
        
        // cyclic sort
        int i = 0;
        while (i < nums.length) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                swap(nums, i, correctIndex);
            } else {
                i++;
            }
        }
        
        // find positions where nums[i] != i + 1
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                duplicates.add(nums[i]);
            }
        }
        
        return duplicates;
    }
    
    // Alternative: mark as negative (doesn't require full sort)
    public List<Integer> findDuplicatesMarking(int[] nums) {
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < nums.length; i++) {
            int index = Math.abs(nums[i]) - 1;
            
            if (nums[index] < 0) {
                // already visited = duplicate
                result.add(index + 1);
            } else {
                nums[index] = -nums[index]; // mark as visited
            }
        }
        
        return result;
    }
    
    // =====================================================
    // FIRST MISSING POSITIVE
    // =====================================================
    
    /**
     * First Missing Positive (LeetCode 41)
     * Given unsorted array, find smallest missing positive integer
     * 
     * This is the hardest problem in this pattern
     * Key: only care about numbers 1 to n (array length)
     * Any number <= 0 or > n can be ignored
     */
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        int i = 0;
        
        while (i < n) {
            // only process if nums[i] is in range [1, n]
            // and not already in correct position
            int correctIndex = nums[i] - 1;
            
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIndex]) {
                swap(nums, i, correctIndex);
            } else {
                i++;
            }
        }
        
        // find first position where nums[i] != i + 1
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1; // all 1 to n are present
    }
    
    /**
     * Set Mismatch (LeetCode 645)
     * Array should be 1 to n, but one number got duplicated
     * and one is missing. Find both.
     */
    public int[] findErrorNums(int[] nums) {
        int i = 0;
        
        while (i < nums.length) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                swap(nums, i, correctIndex);
            } else {
                i++;
            }
        }
        
        // find the wrong position
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return new int[] { nums[i], i + 1 }; // [duplicate, missing]
            }
        }
        
        return new int[] {};
    }
    
    // =====================================================
    // KEY PATTERN
    // =====================================================
    /*
     * Core template:
     * 
     * int i = 0;
     * while (i < nums.length) {
     *     int correctIndex = nums[i] - 1;  // or just nums[i] for 0-indexed
     *     
     *     if (nums[i] should be moved && nums[i] != nums[correctIndex]) {
     *         swap(nums, i, correctIndex);
     *     } else {
     *         i++;
     *     }
     * }
     * 
     * Then scan to find anomalies (missing or duplicate)
     * 
     * Key points:
     * - Only swap when number is in valid range
     * - Avoid infinite loops by checking nums[i] != nums[correctIndex]
     * - After sorting, scan for discrepancies
     * 
     * When elements are 1 to n: correctIndex = nums[i] - 1
     * When elements are 0 to n-1: correctIndex = nums[i]
     */
}
