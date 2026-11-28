import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long[] prefix = new long[n+1];
        for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + nums[i];
        
        int len = -1;
        for(int i=1; i<=n; i++) {
            if(prefix[i] > x) {
                len = i;
                break;
            }
        }
        System.out.println(len);
    }
}
