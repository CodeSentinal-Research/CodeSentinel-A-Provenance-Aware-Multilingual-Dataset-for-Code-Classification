import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long maxAbs = 0;
        long sum = 0;
        for(int num : nums) {
            sum += num;
            maxAbs = Math.max(maxAbs, Math.abs(sum));
        }
        System.out.println(maxAbs);
    }
}
