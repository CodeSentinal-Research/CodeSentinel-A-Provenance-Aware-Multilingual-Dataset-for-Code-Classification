import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num : nums) freq.put(num, freq.getOrDefault(num, 0) + 1);
        
        int res = -1;
        for(Map.Entry<Integer, Integer> e : freq.entrySet()) {
            if(e.getValue() == 1) {
                res = Math.max(res, e.getKey());
            }
        }
        System.out.println(res);
    }
}
