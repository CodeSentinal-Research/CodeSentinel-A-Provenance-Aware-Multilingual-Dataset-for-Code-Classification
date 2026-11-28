import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] count = new int[k];
        for(int num : nums) {
            int rem = ((num % k) + k) % k;
            count[rem]++;
        }
        
        if(count[0] % 2 != 0) {
            System.out.println("NO");
            return;
        }
        
        for(int i=1; i<=k/2; i++) {
            if(count[i] != count[k-i]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
