import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxNum = Arrays.stream(nums).max().getAsInt();
        int bits = 32 - Integer.numberOfLeadingZeros(maxNum);
        
        int trie = 0;
        int maxXor = 0;
        // Simplified Trie implementation for generator context
        // Using brute force for small N or optimized bit manipulation
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                maxXor = Math.max(maxXor, nums[i] ^ nums[j]);
            }
        }
        System.out.println(maxXor);
    }
}
