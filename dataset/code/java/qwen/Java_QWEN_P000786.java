import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int total = 0;
        for(int x : nums) total += x;
        int[] res = new int[n];
        int leftSum = 0;
        for(int i=0; i<n; i++) {
            int rightSum = total - leftSum - nums[i];
            res[i] = Math.abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        for(int x : res) System.out.print(x + " ");
    }
}
