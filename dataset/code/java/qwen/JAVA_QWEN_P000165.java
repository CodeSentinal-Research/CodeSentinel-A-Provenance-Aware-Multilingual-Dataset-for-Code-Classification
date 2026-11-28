import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        long maxProd = arr[0];
        long minProd = arr[0];
        long result = arr[0];
        
        for (int i = 1; i < n; i++) {
            long temp = maxProd;
            maxProd = Math.max((long)arr[i], Math.max(maxProd * arr[i], minProd * arr[i]));
            minProd = Math.min((long)arr[i], Math.min(temp * arr[i], minProd * arr[i]));
            result = Math.max(result, maxProd);
        }
        System.out.println(result);
    }
}
