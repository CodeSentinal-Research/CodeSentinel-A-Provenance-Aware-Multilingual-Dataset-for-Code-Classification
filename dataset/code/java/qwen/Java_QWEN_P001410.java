import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long totalPairs = (long)n * (n - 1) / 2;
        long goodPairs = 0;
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i=0; i<n; i++) {
            int key = nums[i] - i;
            goodPairs += map.getOrDefault(key, 0);
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        
        System.out.println(totalPairs - goodPairs);
    }
}
