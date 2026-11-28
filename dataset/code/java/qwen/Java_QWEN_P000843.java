import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int p = sc.nextInt();
        Arrays.sort(nums);
        
        int low = 0, high = nums[n-1] - nums[0];
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canFormPairs(nums, p, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canFormPairs(int[] nums, int p, int maxDiff) {
        int pairs = 0, i = 0;
        while(i < nums.length - 1) {
            if(nums[i+1] - nums[i] <= maxDiff) {
                pairs++;
                i += 2;
            } else {
                i++;
            }
        }
        return pairs >= p;
    }
}
