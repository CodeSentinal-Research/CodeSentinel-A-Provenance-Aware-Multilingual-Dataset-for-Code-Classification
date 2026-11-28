import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long[] prefix = new long[n+1];
        for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + nums[i];
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            double avg = (double)(prefix[r+1] - prefix[l]) / (r - l + 1);
            System.out.printf("%.2f
", avg);
        }
    }
}
