import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 0;
        int xorSum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        
        for(int i=0; i<n; i++) {
            xorSum ^= nums[i];
            if(map.containsKey(xorSum)) {
                maxLen = Math.max(maxLen, i - map.get(xorSum));
            } else {
                map.put(xorSum, i);
            }
        }
        System.out.println(maxLen);
    }
}
