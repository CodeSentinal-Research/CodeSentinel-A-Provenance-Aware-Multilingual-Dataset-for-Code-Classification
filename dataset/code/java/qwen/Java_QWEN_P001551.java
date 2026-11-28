import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 0;
        long sum = 0;
        int left = 0;
        for(int right=0; right<n; right++) {
            sum += nums[right];
            while(sum > k && left <= right) {
                sum -= nums[left];
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
