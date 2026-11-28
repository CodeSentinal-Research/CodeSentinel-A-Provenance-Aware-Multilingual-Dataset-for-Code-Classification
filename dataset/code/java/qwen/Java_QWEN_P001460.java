import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int xor = 0;
        for(int num : nums) xor ^= num;
        
        long count = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if((nums[i] ^ nums[j]) == 0) count++; // This is wrong logic for prefix XOR pairs
            }
        }
        
        // Correct logic for Count Equal XOR Prefix Pairs:
        // prefixXor[i] = nums[0] ^ ... ^ nums[i]
        // Count pairs (i, j) such that prefixXor[i] == prefixXor[j]
        
        int[] prefix = new int[n];
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] ^ nums[i];
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int p : prefix) freq.put(p, freq.getOrDefault(p, 0) + 1);
        
        long res = 0;
        for(int val : freq.values()) {
            res += (long)val * (val - 1) / 2;
        }
        System.out.println(res);
    }
}
