import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long sum = 0;
        long maxVal = 0;
        for(int num : nums) {
            sum += num;
            maxVal = Math.max(maxVal, num);
        }
        
        long low = (sum + n - 1) / n;
        long high = maxVal;
        while(low < high) {
            long mid = low + (high - low) / 2;
            if(canMinimize(nums, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canMinimize(int[] nums, long limit) {
        long excess = 0;
        for(int num : nums) {
            if(num > limit) return false;
            excess += limit - num;
        }
        return true;
    }
}
