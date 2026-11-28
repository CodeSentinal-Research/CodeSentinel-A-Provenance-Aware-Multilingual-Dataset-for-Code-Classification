import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int xor = 0;
        for(int i=0; i<=n; i++) xor ^= i;
        for(int num : nums) xor ^= num;
        System.out.println(xor);
    }
}
