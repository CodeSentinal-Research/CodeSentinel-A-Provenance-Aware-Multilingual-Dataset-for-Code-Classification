import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int balance = 0, count = 0;
        for(int num : nums) {
            balance += (num > 0 ? 1 : -1);
            count += map.getOrDefault(balance, 0);
            map.put(balance, map.getOrDefault(balance, 0) + 1);
        }
        System.out.println(count);
    }
}
