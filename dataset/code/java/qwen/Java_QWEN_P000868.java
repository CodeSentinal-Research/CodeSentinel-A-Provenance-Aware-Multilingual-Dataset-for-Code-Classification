import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int total = 0;
        for(int i=0; i<32; i++) {
            int countOnes = 0;
            for(int num : nums) {
                if(((num >> i) & 1) == 1) countOnes++;
            }
            total += countOnes * (n - countOnes);
        }
        System.out.println(total);
    }
}
