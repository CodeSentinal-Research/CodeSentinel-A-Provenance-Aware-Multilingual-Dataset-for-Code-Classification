import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        int[] inc = new int[n];
        int[] dec = new int[n];
        Arrays.fill(inc, 1);
        Arrays.fill(dec, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) inc[i] = Math.max(inc[i], inc[j] + 1);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) dec[i] = Math.max(dec[i], dec[j] + 1);
            }
        }
        
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            maxLen = Math.max(maxLen, inc[i] + dec[i] - 1);
        }
        System.out.println(maxLen);
    }
}
