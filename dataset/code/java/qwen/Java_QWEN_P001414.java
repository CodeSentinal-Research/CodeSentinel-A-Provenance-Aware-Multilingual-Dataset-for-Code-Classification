import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Set<Integer> set = new HashSet<>();
        for(int num : nums) {
            set.add(Math.abs(num));
        }
        System.out.println(set.size());
    }
}
