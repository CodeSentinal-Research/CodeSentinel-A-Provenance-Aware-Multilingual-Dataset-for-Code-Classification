import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        long count = 0;
        int left = 0;
        for(int right=0; right<n; right++) {
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);
            while(freq.size() > k) {
                freq.put(nums[left], freq.get(nums[left]) - 1);
                if(freq.get(nums[left]) == 0) freq.remove(nums[left]);
                left++;
            }
            count += (right - left + 1);
        }
        System.out.println(count);
    }
}
