import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        long minSum = arr[0];
        long currentSum = arr[0];
        
        for (int i = 1; i < n; i++) {
            currentSum = Math.min((long)arr[i], currentSum + arr[i]);
            minSum = Math.min(minSum, currentSum);
        }
        System.out.println(minSum);
    }
}
