import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        
        int low = Arrays.stream(nums).max().getAsInt();
        int high = Arrays.stream(nums).sum();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canSplit(nums, k, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canSplit(int[] nums, int k, int limit) {
        int splits = 1, sum = 0;
        for(int num : nums) {
            if(sum + num > limit) { splits++; sum = num; }
            else sum += num;
        }
        return splits <= k;
    }
}
