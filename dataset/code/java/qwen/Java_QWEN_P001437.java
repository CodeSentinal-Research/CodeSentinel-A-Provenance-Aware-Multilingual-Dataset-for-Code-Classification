import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Set<Integer> set = new HashSet<>();
        for(int num : nums) {
            if(set.contains(num * 2) || (num % 2 == 0 && set.contains(num / 2))) {
                System.out.println("YES");
                return;
            }
            set.add(num);
        }
        System.out.println("NO");
    }
}
