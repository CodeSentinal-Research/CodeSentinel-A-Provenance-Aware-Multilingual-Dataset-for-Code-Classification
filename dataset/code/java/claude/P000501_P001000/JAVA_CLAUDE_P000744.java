import java.util.*;
public class Solution {
    public void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            int mi = i;
            for (int j = i+1; j < n; j++) if (arr[j] < arr[mi]) mi = j;
            int t = arr[mi]; arr[mi] = arr[i]; arr[i] = t;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        new Solution().selectionSort(arr);
        System.out.println(Arrays.toString(arr).replaceAll("[\[\],]","").trim());
    }
}
