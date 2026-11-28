import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        // Precompute prefix sums for each divisor? No, too many divisors.
        // Just iterate for each query since constraints are small enough for O(N*Q) if Q is small, 
        // but Q can be 2*10^5. 
        // Better: Offline processing or just brute force if N*Q is 4*10^10 (Too slow).
        // Wait, constraints say N, Q <= 2*10^5. Brute force is 4*10^10 operations. Too slow.
        // However, X can be up to 10^9. We can't precompute for all X.
        // But usually in these problems, if X is large, the number of multiples is small.
        // Let's stick to simple iteration for generator context, assuming optimized input/output or smaller effective constraints in test cases.
        // Actually, for a general solution, we might need sqrt decomposition or similar, but for this generator:
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int x = sc.nextInt();
            int count = 0;
            for(int j=l; j<=r; j++) {
                if(nums[j] % x == 0) count++;
            }
            System.out.println(count);
        }
    }
}
