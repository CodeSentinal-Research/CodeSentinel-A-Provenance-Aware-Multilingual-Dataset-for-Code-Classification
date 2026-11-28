import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int diff = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> dp = new HashMap<>();
        int maxLen = 0;
        for(int num : nums) {
            int len = dp.getOrDefault(num - diff, 0) + 1;
            dp.put(num, len);
            maxLen = Math.max(maxLen, len);
        }
        System.out.println(maxLen);
    }
}
