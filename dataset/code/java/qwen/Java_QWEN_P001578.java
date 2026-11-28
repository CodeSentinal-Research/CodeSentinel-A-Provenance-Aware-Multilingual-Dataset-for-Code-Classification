import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        int count = 0;
        for(int i=0; i<k; i++) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }
        if(freq.size() == k) count++;
        
        for(int i=k; i<n; i++) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            freq.put(nums[i-k], freq.get(nums[i-k]) - 1);
            if(freq.get(nums[i-k]) == 0) freq.remove(nums[i-k]);
            
            if(freq.size() == k) count++;
        }
        System.out.println(count);
    }
}
