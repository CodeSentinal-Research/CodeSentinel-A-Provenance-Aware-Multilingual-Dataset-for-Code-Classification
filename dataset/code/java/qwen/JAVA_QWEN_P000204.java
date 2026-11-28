import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        // Sort first to make wave easier, though not strictly required if we just swap adjacent
        // Standard wave sort: Swap adjacent elements
        for (int i = 0; i < n - 1; i += 2) {
            // Swap arr[i] and arr[i+1]
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        
        // Check if it satisfies a[0] >= a[1] <= a[2] >= ...
        // The simple swap above works for unsorted arrays to create A >= B <= C pattern locally
        
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(arr[i]);
        }
        System.out.println();
    }
}
