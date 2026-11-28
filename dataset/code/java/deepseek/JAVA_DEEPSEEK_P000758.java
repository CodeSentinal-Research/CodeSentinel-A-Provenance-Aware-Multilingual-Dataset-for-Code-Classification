import java.io.*;
import java.util.*;

public class Main {
    static long count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] numsStr = br.readLine().split(" ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
       
            count += mergeSort(nums, 0, n - 1);
        }
        System.out.println(count);
    }

    static long mergeSort(int[] arr, int l, int r) {
        long inv_count = 0;
        if (l < r) {
            int m = (l + r) / 2;
            inv_count += mergeSort(arr, l, m);
            inv_count += mergeSort(arr, m + 1, r);
            inv_count += merge(arr, l, m, r);
        }
        return inv_count;
    }

    static long merge(int[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
        long inv_count = 0;
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
                inv_count += (m + 1) - (l + i);
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
        return inv_count;
    }
}
