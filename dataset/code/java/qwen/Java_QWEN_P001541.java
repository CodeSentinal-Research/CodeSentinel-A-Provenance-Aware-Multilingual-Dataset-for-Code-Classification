import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long sum = 0;
        for(int i=0; i<k; i++) sum += nums[i];
        long maxSum = sum;
        
        for(int i=k; i<n; i++) {
            sum += nums[i] - nums[i-k];
            maxSum = Math.max(maxSum, sum);
        }
        System.out.println(maxSum);
    }
}
