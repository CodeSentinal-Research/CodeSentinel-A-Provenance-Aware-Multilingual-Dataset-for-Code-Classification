import java.util.*;
public class Main {
    static final int MOD = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        long count = 0;
        long[] pow2 = new long[n];
        pow2[0] = 1;
        for(int i=1; i<n; i++) pow2[i] = (pow2[i-1] * 2) % MOD;
        
        for(int i=0; i<n; i++) {
            int left = i, right = n - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[i] + nums[mid] <= target) left = mid + 1;
                else right = mid - 1;
            }
            if(right >= i) {
                count = (count + pow2[right - i]) % MOD;
            }
        }
        System.out.println(count);
    }
}
