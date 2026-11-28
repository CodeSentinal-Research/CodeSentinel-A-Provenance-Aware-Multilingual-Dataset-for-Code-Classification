import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        long count = 0;
        for(int num : nums) {
            for(int i=0; i<32; i++) {
                int target = (1 << i) - num;
                if(freq.containsKey(target)) {
                    count += freq.get(target);
                }
            }
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        System.out.println(count);
    }
}
