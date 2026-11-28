import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        // Binary search for insertion point
        int idx = Arrays.binarySearch(arr, target);
        if (idx < 0) idx = -insertionPoint - 1; // Correct logic below
        
        // Find closest k elements
        // Simple approach: sort by distance to target
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        
        Arrays.sort(indices, (a, b) -> {
            int distA = Math.abs(arr[a] - target);
            int distB = Math.abs(arr[b] - target);
            if (distA != distB) return distA - distB;
            return arr[a] - arr[b];
        });
        
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = arr[indices[i]];
        }
        
        Arrays.sort(result);
        for (int i = 0; i < k; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(result[i]);
        }
        System.out.println();
    }
}
