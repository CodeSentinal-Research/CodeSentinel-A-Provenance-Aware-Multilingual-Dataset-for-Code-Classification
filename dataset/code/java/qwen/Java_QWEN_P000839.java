import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int threshold = sc.nextInt();
        
        int low = 1, high = Arrays.stream(nums).max().getAsInt();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(getSum(nums, mid) <= threshold) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static int getSum(int[] nums, int divisor) {
        int sum = 0;
        for(int num : nums) sum += (num + divisor - 1) / divisor;
        return sum;
    }
}
