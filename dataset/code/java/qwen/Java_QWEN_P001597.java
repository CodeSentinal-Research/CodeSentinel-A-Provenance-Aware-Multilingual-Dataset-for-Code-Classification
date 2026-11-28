import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, int[]> countMap = new HashMap<>();
        for(int i=0; i<n; i++) {
            countMap.computeIfAbsent(nums[i], k -> new int[n+1]);
            countMap.get(nums[i])[i+1] = 1;
        }
        
        // Build prefix sums for each value
        for(int[] arr : countMap.values()) {
            for(int i=1; i<=n; i++) arr[i] += arr[i-1];
        }
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int x = sc.nextInt();
            if(countMap.containsKey(x)) {
                System.out.println(countMap.get(x)[r+1] - countMap.get(x)[l]);
            } else {
                System.out.println(0);
            }
        }
    }
}
