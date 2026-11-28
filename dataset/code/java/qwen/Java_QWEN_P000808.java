import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int balance = 0, maxLen = 0;
        for(int i=0; i<n; i++) {
            balance += (nums[i] % 2 == 0 ? 1 : -1);
            if(map.containsKey(balance)) {
                maxLen = Math.max(maxLen, i - map.get(balance));
            } else {
                map.put(balance, i);
            }
        }
        System.out.println(maxLen);
    }
}
