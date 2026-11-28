import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long sumDiff = 0;
        for(int i=1; i<k; i++) {
            sumDiff += Math.abs(nums[i] - nums[i-1]);
        }
        System.out.print(sumDiff + " ");
        
        for(int i=k; i<n; i++) {
            sumDiff -= Math.abs(nums[i-k+1] - nums[i-k]);
            sumDiff += Math.abs(nums[i] - nums[i-1]);
            System.out.print(sumDiff + " ");
        }
    }
}
