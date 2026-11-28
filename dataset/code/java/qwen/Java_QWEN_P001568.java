import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 0;
        int zeros = 0;
        int left = 0;
        for(int right=0; right<n; right++) {
            if(nums[right] == 0) zeros++;
            while(zeros > 1) {
                if(nums[left] == 0) zeros--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        // If all are 1s, we must delete one, so length is n-1
        if(maxLen == n) maxLen--;
        System.out.println(maxLen);
    }
}
