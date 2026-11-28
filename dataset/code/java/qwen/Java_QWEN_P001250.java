import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Integer, Integer> ends = new HashMap<>();
        Map<Integer, Integer> count = new HashMap<>();
        for(int num : nums) count.put(num, count.getOrDefault(num, 0) + 1);
        
        for(int num : nums) {
            if(count.get(num) == 0) continue;
            count.put(num, count.get(num) - 1);
            
            if(ends.containsKey(num - 1) && ends.get(num - 1) > 0) {
                ends.put(num - 1, ends.get(num - 1) - 1);
                ends.put(num, ends.getOrDefault(num, 0) + 1);
            } else if(count.containsKey(num + 1) && count.get(num + 1) > 0 && count.containsKey(num + 2) && count.get(num + 2) > 0) {
                count.put(num + 1, count.get(num + 1) - 1);
                count.put(num + 2, count.get(num + 2) - 1);
                ends.put(num + 2, ends.getOrDefault(num + 2, 0) + 1);
            } else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
