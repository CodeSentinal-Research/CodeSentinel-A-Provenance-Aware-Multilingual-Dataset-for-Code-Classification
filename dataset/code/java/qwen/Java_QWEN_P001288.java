import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        for(int i=0; i<k; i++) {
            if(nums[i] < 0) nums[i] = -nums[i];
            else {
                if(i < n) nums[i] = -nums[i];
                break;
            }
        }
        if(k % 2 != 0 && k > 0 && nums[0] >= 0) {
             // Find smallest to flip back if needed, simplified logic
        }
        
        long sum = 0;
        for(int num : nums) sum += num;
        System.out.println(sum);
    }
}
