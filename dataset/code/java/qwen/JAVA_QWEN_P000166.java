import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        long minProd = arr[0];
        long maxProd = arr[0];
        long result = arr[0];
        
        for (int i = 1; i < n; i++) {
            long temp = minProd;
            minProd = Math.min((long)arr[i], Math.min(minProd * arr[i], maxProd * arr[i]));
            maxProd = Math.max((long)arr[i], Math.max(temp * arr[i], maxProd * arr[i]));
            result = Math.min(result, minProd);
        }
        System.out.println(result);
    }
}
