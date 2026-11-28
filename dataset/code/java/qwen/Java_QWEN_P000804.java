import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int xor = 0, count = 0;
        for(int num : nums) {
            xor ^= num;
            count += map.getOrDefault(xor ^ k, 0);
            map.put(xor, map.getOrDefault(xor, 0) + 1);
        }
        System.out.println(count);
    }
}
