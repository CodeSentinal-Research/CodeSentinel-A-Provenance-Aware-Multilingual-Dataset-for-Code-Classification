import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        int minMaxSum = Integer.MAX_VALUE;
        for(int i=0; i<n/2; i++) {
            minMaxSum = Math.max(minMaxSum, nums[i] + nums[n-1-i]);
        }
        System.out.println(minMaxSum);
    }
}
