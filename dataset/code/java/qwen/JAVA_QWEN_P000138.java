import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        
        int[] arr1 = new int[m];
        for (int i = 0; i < m; i++) arr1[i] = sc.nextInt();
        
        int[] arr2 = new int[n];
        for (int i = 0; i < n; i++) arr2[i] = sc.nextInt();
        
        int[] merged = new int[m + n];
        int i = 0, j = 0, k = 0;
        
        while (i < m && j < n) {
            if (arr1[i] <= arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }
        while (i < m) merged[k++] = arr1[i++];
        while (j < n) merged[k++] = arr2[j++];
        
        for (int idx = 0; idx < m + n; idx++) {
            if (idx > 0) System.out.print(" ");
            System.out.print(merged[idx]);
        }
        System.out.println();
    }
}
