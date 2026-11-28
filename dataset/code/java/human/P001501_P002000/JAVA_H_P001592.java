import java.util.HashMap;

public class Longest_SubArray_with_sum_K_2 {
    // better approach -> Time Complexity ~ O(N^2) & Space Complexity O(N): By Hashing and Prefix Sum concept 
    // Also works if array have negatives and its the optimal approach if array have negatives:
    static void findSubArray_3(int[] arr, int k){
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefixSum = 0;
        int maxLength = 0; 

        for (int i = 0; i < arr.length; i++) {
            //calculate the prefix sum till index i:
            prefixSum += arr[i];

            if(prefixSum == k){
                maxLength = Integer.max(maxLength, i+1);
            }

            // calculate the sum of remaining part i.e. x-k:
            int remaining = prefixSum - k;

            // update maxLength:
            if (map.containsKey(remaining)) {
                int len = i - map.get(remaining);
                maxLength = Integer.max(maxLength, len);
            }
            //Finally, update the map checking the conditions:
            if (! map.containsKey(prefixSum)) { // To count zeroes also in length because we need to find the maximum length
                map.put(prefixSum, i);
            }
        }
        System.out.println(maxLength);
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,1,1,1,1,4,2,3};
        int k = 3;

        findSubArray_3(arr, k);
    }
}
/*
Approach:
The steps are as follows:

First, we will declare a map to store the prefix sums and the indices.
Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:
We will add the current element i.e. a[i] to the prefix sum.
If the sum is equal to k, we should consider the length of the current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
We will calculate the prefix sum i.e. x-k, of the remaining subarray.
If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible and so we will consider the earliest index where the sum x-k has occurred. [Detailed discussion in the edge case section]


Complexity Analysis
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Space Complexity: O(N) as we are using a map data structure.
 */