import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        int minVal = arr[0];
        int maxDiff = Integer.MIN_VALUE;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] - minVal > maxDiff) {
                maxDiff = arr[i] - minVal;
            }
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        System.out.println(maxDiff);
    }
}
