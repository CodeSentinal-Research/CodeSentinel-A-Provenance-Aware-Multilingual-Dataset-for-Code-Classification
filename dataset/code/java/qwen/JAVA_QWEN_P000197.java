import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        long windowSum = 0;
        
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
            if (i < k) windowSum += nums[i];
        }
        
        long minSum = windowSum;
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i-k];
            if (windowSum < minSum) minSum = windowSum;
        }
        System.out.println(minSum);
    }
}
