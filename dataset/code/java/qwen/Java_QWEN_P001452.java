import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num : nums) freq.put(num, freq.getOrDefault(num, 0) + 1);
        
        for(int i=0; i<q; i++) {
            int idx = sc.nextInt();
            int newVal = sc.nextInt();
            
            int oldVal = nums[idx];
            freq.put(oldVal, freq.get(oldVal) - 1);
            if(freq.get(oldVal) == 0) freq.remove(oldVal);
            
            nums[idx] = newVal;
            freq.put(newVal, freq.getOrDefault(newVal, 0) + 1);
            
            System.out.println(freq.size());
        }
    }
}
