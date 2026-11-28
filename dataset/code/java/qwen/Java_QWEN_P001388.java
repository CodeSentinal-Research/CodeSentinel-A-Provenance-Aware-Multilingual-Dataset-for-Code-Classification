import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> window = new HashMap<>();
        for(int i=0; i<k; i++) {
            window.put(nums[i], window.getOrDefault(nums[i], 0) + 1);
        }
        System.out.print(window.size() + " ");
        
        for(int i=k; i<n; i++) {
            window.put(nums[i-k], window.get(nums[i-k]) - 1);
            if(window.get(nums[i-k]) == 0) window.remove(nums[i-k]);
            window.put(nums[i], window.getOrDefault(nums[i], 0) + 1);
            System.out.print(window.size() + " ");
        }
    }
}
