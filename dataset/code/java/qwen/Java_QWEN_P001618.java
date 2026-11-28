import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] prefixXor = new int[n];
        prefixXor[0] = nums[0];
        for(int i=1; i<n; i++) prefixXor[i] = prefixXor[i-1] ^ nums[i];
        
        for(int x : prefixXor) System.out.print(x + " ");
    }
}
