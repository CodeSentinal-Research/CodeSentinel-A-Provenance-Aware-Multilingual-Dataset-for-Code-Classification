import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        int maxFreq = 1;
        int left = 0;
        long sum = 0;
        
        for(int right=0; right<n; right++) {
            sum += nums[right];
            while((long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }
            maxFreq = Math.max(maxFreq, right - left + 1);
        }
        System.out.println(maxFreq);
    }
}
