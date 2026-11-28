import java.util.*;
public class Main {
    static int[] prefix;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        prefix = new int[n+1];
        for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + nums[i];
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(prefix[r+1] - prefix[l]);
        }
    }
}
