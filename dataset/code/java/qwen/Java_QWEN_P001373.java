import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> lastSeen = new HashMap<>();
        for(int i=0; i<n; i++) {
            if(lastSeen.containsKey(nums[i]) && i - lastSeen.get(nums[i]) <= k) {
                System.out.println("YES");
                return;
            }
            lastSeen.put(nums[i], i);
        }
        System.out.println("NO");
    }
}
