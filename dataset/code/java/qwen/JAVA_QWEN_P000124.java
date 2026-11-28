import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        long[] prefix = new long[n];
        long[] suffix = new long[n];
        
        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        
        suffix[n-1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(prefix[i] * suffix[i]);
        }
        System.out.println();
    }
}
