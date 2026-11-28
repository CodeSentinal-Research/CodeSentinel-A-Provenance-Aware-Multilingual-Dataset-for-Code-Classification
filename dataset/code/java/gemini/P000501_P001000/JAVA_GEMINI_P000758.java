import java.util.*;
public class Solution {
    static long merge(int[] arr, int l, int m, int r) {
        int[] left = Arrays.copyOfRange(arr, l, m + 1);
        int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);
        int i = 0, j = 0, k = l;
        long inv = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                inv += left.length - i;
            }
        }
        while (i < left.length) arr[k++] = left[i++];
        while (j < right.length) arr[k++] = right[j++];
        return inv;
    }
    static long mergeSort(int[] arr, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        long inv = mergeSort(arr, l, m);
        inv += mergeSort(arr, m + 1, r);
        inv += merge(arr, l, m, r);
        return inv;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            System.out.println(mergeSort(nums, 0, n - 1));
        }
    }
}