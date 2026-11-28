import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        for(int i=0; i<=n-k; i++) {
            System.out.print(Math.abs(nums[i] - nums[i+k-1]) + " ");
        }
    }
}
