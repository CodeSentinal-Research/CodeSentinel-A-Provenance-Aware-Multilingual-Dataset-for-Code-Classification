import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Set<Integer> distinct = new HashSet<>();
        for(int num : nums) {
            if(num > 0) distinct.add(num);
        }
        System.out.println(distinct.size());
    }
}
