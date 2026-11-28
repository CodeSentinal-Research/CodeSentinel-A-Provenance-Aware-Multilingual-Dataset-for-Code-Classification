import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> balanceMap = new HashMap<>();
        balanceMap.put(0, -1);
        int balance = 0;
        int maxLen = 0;
        
        for(int i=0; i<n; i++) {
            balance += (nums[i] % 2 == 0 ? 1 : -1);
            if(balanceMap.containsKey(balance)) {
                maxLen = Math.max(maxLen, i - balanceMap.get(balance));
            } else {
                balanceMap.put(balance, i);
            }
        }
        System.out.println(maxLen);
    }
}
