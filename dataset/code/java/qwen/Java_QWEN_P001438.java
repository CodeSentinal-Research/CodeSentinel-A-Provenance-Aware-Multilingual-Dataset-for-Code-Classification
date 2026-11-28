import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num : nums) freq.put(num, freq.getOrDefault(num, 0) + 1);
        
        for(int count : freq.values()) {
            if(count % 2 != 0) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
