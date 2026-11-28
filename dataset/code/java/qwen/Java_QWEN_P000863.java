import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int xor = 0;
        for(int num : nums) xor ^= num;
        
        int setBit = xor & -xor;
        int a = 0, b = 0;
        for(int num : nums) {
            if((num & setBit) != 0) a ^= num;
            else b ^= num;
        }
        System.out.println(a + " " + b);
    }
}
