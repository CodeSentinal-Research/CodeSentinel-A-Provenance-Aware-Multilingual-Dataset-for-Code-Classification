import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] evenPrefix = new int[n+1];
        int[] oddPrefix = new int[n+1];
        for(int i=0; i<n; i++) {
            evenPrefix[i+1] = evenPrefix[i];
            oddPrefix[i+1] = oddPrefix[i];
            if(i % 2 == 0) evenPrefix[i+1] += nums[i];
            else oddPrefix[i+1] += nums[i];
        }
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            // Sum of elements at even indices relative to start of array? 
            // Problem says "alternate positions within each specified range, starting from the left endpoint"
            // This implies indices l, l+2, l+4...
            int sum = 0;
            for(int j=l; j<=r; j+=2) sum += nums[j];
            System.out.println(sum);
        }
    }
}
