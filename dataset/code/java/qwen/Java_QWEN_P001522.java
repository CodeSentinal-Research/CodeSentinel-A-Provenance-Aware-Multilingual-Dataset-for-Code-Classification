import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        
        int target = totalSum - x;
        if(target < 0) {
            System.out.println(-1);
            return;
        }
        
        int maxLen = -1;
        int currSum = 0;
        int left = 0;
        for(int right=0; right<n; right++) {
            currSum += nums[right];
            while(currSum > target && left <= right) {
                currSum -= nums[left];
                left++;
            }
            if(currSum == target) {
                maxLen = Math.max(maxLen, right - left + 1);
            }
        }
        
        System.out.println(maxLen == -1 ? -1 : n - maxLen);
    }
}
