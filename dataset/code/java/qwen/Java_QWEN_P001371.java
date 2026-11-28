import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(map.containsKey(sum - target)) {
                System.out.println(map.get(sum - target) + 1 + " " + i);
                return;
            }
            if(!map.containsKey(sum)) map.put(sum, i);
        }
        System.out.println("-1");
    }
}
