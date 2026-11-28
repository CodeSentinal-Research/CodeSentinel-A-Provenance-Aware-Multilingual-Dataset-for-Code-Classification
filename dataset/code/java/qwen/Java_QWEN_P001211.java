import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        long sum = 0;
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
            sum += nums[i];
        }
        
        if(sum % k != 0) { System.out.println("NO"); return; }
        long target = sum / k;
        boolean[] used = new boolean[n];
        Arrays.sort(nums);
        System.out.println(canPartition(nums, used, 0, 0, target, k) ? "YES" : "NO");
    }
    
    static boolean canPartition(int[] nums, boolean[] used, int start, long currSum, long target, int k) {
        if(k == 1) return true;
        if(currSum == target) return canPartition(nums, used, 0, 0, target, k - 1);
        
        for(int i=start; i<nums.length; i++) {
            if(!used[i] && currSum + nums[i] <= target) {
                used[i] = true;
                if(canPartition(nums, used, i + 1, currSum + nums[i], target, k)) return true;
                used[i] = false;
            }
        }
        return false;
    }
}
