import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long lcm = nums[0];
        for(int i=1; i<n; i++) {
            lcm = (lcm * nums[i]) / gcd(lcm, nums[i]);
            if(lcm > 1e18) { System.out.println(lcm % 1000000007); return; }
        }
        System.out.println(lcm);
    }
    static long gcd(long a, long b) {
        while(b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
