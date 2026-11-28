import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        int maxSum = 0;
        int currSum = 0;
        int left = 0;
        for(int right=0; right<n; right++) {
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);
            currSum += nums[right];
            while(freq.get(nums[right]) > 1) {
                freq.put(nums[left], freq.get(nums[left]) - 1);
                currSum -= nums[left];
                left++;
            }
            maxSum = Math.max(maxSum, currSum);
        }
        System.out.println(maxSum);
    }
}
