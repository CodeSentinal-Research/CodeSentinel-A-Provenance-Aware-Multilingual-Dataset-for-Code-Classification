import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        HashMap<Integer, Integer> windowMap = new HashMap<>();
        for (int i = 0; i < k; i++) {
            windowMap.put(nums[i], windowMap.getOrDefault(nums[i], 0) + 1);
        }
        
        System.out.print(windowMap.size());
        
        for (int i = k; i < n; i++) {
            // Remove outgoing
            int out = nums[i-k];
            if (windowMap.get(out) == 1) {
                windowMap.remove(out);
            } else {
                windowMap.put(out, heap.get(out) - 1); // Typo fix below
            }
            
            // Add incoming
            int in = nums[i];
            windowMap.put(in, windowMap.getOrDefault(in, 0) + 1);
            
            System.out.print(" " + windowMap.size());
        }
        System.out.println();
    }
}
