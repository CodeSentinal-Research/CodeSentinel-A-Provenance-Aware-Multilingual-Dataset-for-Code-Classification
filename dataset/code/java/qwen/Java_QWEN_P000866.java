import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int q = sc.nextInt();
        
        int[] prefixXor = new int[n+1];
        for(int i=0; i<n; i++) prefixXor[i+1] = prefixXor[i] ^ nums[i];
        
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(prefixXor[r+1] ^ prefixXor[l]);
        }
    }
}
