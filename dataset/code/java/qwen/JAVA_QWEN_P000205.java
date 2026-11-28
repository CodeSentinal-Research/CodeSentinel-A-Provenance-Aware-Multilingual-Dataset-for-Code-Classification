import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        
        for (int i = 0; i < n; i++) arr1[i] = sc.nextInt();
        for (int i = 0; i < n; i++) arr2[i] = sc.nextInt();
        
        // Merge both into one sorted array to find median easily
        int[] merged = new int[2 * n];
        int i = 0, j = 0, k = 0;
        while (i < n && j < n) {
            if (arr1[i] <= arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }
        while (i < n) merged[k++] = arr1[i++];
        while (j < n) merged[k++] = arr2[j++];
        
        double median;
        if (n == 0) {
            median = 0;
        } else {
            // Total length is 2*n (even)
            median = (merged[n - 1] + merged[n]) / 2.0;
        }
        
        System.out.println(median);
    }
}
