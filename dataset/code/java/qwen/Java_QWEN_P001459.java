import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        boolean[] present = new boolean[n+1];
        for(int num : nums) {
            if(num > 0 && num <= n) present[num] = true;
        }
        
        for(int i=1; i<=n; i++) {
            if(!present[i]) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(n+1);
    }
}
