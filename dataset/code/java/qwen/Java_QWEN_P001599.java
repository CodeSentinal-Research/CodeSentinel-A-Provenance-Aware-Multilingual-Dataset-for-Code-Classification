import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] divPrefix = new int[n+1];
        for(int i=0; i<n; i++) divPrefix[i+1] = divPrefix[i] + (nums[i] % k == 0 ? 1 : 0);
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(divPrefix[r+1] - divPrefix[l]);
        }
    }
}
