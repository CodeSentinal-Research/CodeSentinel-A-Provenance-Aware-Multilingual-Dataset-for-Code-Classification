import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        int start = 0;
        long currentSum = 0;
        
        for (int end = 0; end < n; end++) {
            currentSum += nums[end];
            while (currentSum > target && start <= end) {
                currentSum -= nums[start];
                start++;
            }
            if (currentSum == target) {
                System.out.println((start + 1) + " " + (end + 1));
                return;
            }
        }
        System.out.println(-1);
    }
}
