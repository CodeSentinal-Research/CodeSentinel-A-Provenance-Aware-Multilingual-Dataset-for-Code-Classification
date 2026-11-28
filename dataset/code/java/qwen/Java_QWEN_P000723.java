import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        long sum = 0;
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
            sum += nums[i];
        }
        int k = sc.nextInt();
        if(sum % k != 0) { System.out.println("false"); return; }
        long target = sum / k;
        Arrays.sort(nums);
        long[] groups = new long[k];
        System.out.println(canPartition(nums, n - 1, groups, target) ? "true" : "false");
    }
    static boolean canPartition(int[] nums, int idx, long[] groups, long target) {
        if(idx < 0) return true;
        for(int i=0; i<groups.length; i++) {
            if(groups[i] + nums[idx] <= target) {
                groups[i] += nums[idx];
                if(canPartition(nums, idx - 1, groups, target)) return true;
                groups[i] -= nums[idx];
            }
            if(groups[i] == 0) break;
        }
        return false;
    }
}
