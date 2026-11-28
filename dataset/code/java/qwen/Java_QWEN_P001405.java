import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> map = new HashMap<>();
        long count = 0;
        for(int num : nums) {
            int rev = reverse(num);
            int key = num - rev;
            count += map.getOrDefault(key, 0);
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        System.out.println(count);
    }
    
    static int reverse(int x) {
        int res = 0;
        while(x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
}
