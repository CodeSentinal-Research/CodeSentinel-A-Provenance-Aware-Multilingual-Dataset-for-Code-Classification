import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        int peakIdx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1] && (i == n-1 || arr[i] > arr[i+1])) {
                peakIdx = i;
                break;
            }
        }
        // Check boundaries if no internal peak found
        if (n > 0 && (n == 1 || arr[0] >= arr[1])) peakIdx = 0;
        if (n > 1 && arr[n-1] >= arr[n-2]) peakIdx = n-1;
        
        System.out.println(peakIdx);
    }
}
