import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] matchsticks = new int[n];
        for (int i = 0; i < n; i++) {
            matchsticks[i] = scanner.nextInt();
        }
        System.out.println(makesquare(matchsticks));
    }

    public static boolean makesquare(int[] nums) {
        if(nums == null || nums.length < 4)
            return false;
        
        int sum = 0;
        for(int num : nums)
            sum += num;
        
        if(sum % 4 != 0)
            return false;
        
        int target = sum / 4;
        return dfs(nums, 0, new int[4], target);
    }
    
    public static boolean dfs(int[] nums, int index, int[] sums, int target) {
        if(index == nums.length) {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3] && sums[3] == target;
        }
        
        for(int i = 0; i < 4; i++) {
            if(sums[i] + nums[index] <= target) {
                sums[i] += nums[index];
                if(dfs(nums, index + 1, sums, target))
                    return true;
                sums[i] -= nums[index];
            }
        }
        
        return false;
    }
}
