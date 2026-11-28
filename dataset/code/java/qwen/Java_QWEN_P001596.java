import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] posPrefix = new int[n+1];
        for(int i=0; i<n; i++) posPrefix[i+1] = posPrefix[i] + (nums[i] > 0 ? 1 : 0);
        
        int q = sc.nextInt();
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(posPrefix[r+1] - posPrefix[l]);
        }
    }
}
