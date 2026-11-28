import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int key = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int i=1; i<n; i++) {
            if(nums[i-1] == key) {
                freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            }
        }
        
        int maxFreq = 0;
        int res = -1;
        for(Map.Entry<Integer, Integer> e : freq.entrySet()) {
            if(e.getValue() > maxFreq || (e.getValue() == maxFreq && e.getKey() < res)) {
                maxFreq = e.getValue();
                res = e.getKey();
            }
        }
        System.out.println(res);
    }
}
