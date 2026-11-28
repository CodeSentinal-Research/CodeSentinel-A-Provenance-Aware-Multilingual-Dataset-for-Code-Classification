import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(map.containsKey(sum)) {
                if(i - map.get(sum) > 1) {
                    System.out.println("YES");
                    return;
                }
            } else {
                map.put(sum, i);
            }
        }
        System.out.println("NO");
    }
}
