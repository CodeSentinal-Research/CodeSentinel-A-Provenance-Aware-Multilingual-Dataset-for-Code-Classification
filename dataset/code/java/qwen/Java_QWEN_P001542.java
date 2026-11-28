import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long sum = 0;
        for(int i=0; i<k; i++) sum += nums[i];
        
        System.out.printf("%.1f ", (double)sum/k);
        for(int i=k; i<n; i++) {
            sum += nums[i] - nums[i-k];
            System.out.printf("%.1f ", (double)sum/k);
        }
    }
}
