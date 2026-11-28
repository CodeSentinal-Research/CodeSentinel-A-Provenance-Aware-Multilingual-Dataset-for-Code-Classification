import java.util.*;

public class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] count = new int[1001];
        for (int x : arr1) count[x]++;

        int idx = 0;
        for (int x : arr2) {
            while (count[x] > 0) {
                arr1[idx++] = x;
                count[x]--;
            }
        }

        for (int i = 0; i <= 1000; i++) {
            while (count[i] > 0) {
                arr1[idx++] = i;
                count[i]--;
            }
        }
        return arr1;
    }
}