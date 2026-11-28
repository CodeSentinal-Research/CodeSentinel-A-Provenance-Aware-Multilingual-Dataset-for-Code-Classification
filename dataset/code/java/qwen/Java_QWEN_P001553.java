import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 0;
        int left = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        
        for(int right=0; right<n; right++) {
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);
            while(freq.size() > k) {
                freq.put(nums[left], freq.get(nums[left]) - 1);
                if(freq.get(nums[left]) == 0) freq.remove(nums[left]);
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
