import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int ones = 0;
        for(int num : nums) if(num == 1) ones++;
        
        int minSwaps = Integer.MAX_VALUE;
        int zerosInWindow = 0;
        for(int i=0; i<ones; i++) {
            if(nums[i] == 0) zerosInWindow++;
        }
        minSwaps = zerosInWindow;
        
        for(int i=ones; i<n; i++) {
            if(nums[i] == 0) zerosInWindow++;
            if(nums[i-ones] == 0) zerosInWindow--;
            minSwaps = Math.min(minSwaps, zerosInWindow);
        }
        System.out.println(minSwaps);
    }
}
