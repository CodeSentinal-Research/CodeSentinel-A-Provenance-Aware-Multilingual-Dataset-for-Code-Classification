import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        int maxReach = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                System.out.println("NO");
                return;
            }
            maxReach = Math.max(maxReach, i + nums[i]);
        }
        System.out.println("YES");
    }
}
