import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int maxOps = sc.nextInt();
        
        int low = 1, high = Arrays.stream(nums).max().getAsInt();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(needOps(nums, mid) <= maxOps) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static int needOps(int[] nums, int limit) {
        int ops = 0;
        for(int num : nums) {
            ops += (num - 1) / limit;
        }
        return ops;
    }
}
