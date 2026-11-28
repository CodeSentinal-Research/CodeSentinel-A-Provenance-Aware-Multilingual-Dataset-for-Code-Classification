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
        
        long maxSum = windowSum;
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i-k];
            if (windowSum > maxSum) maxSum = windowSum;
        }
        System.out.println(maxSum);
    }
}
