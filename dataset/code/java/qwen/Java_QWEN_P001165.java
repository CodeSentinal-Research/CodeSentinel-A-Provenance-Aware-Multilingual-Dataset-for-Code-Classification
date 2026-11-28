import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        long maxProd = nums[0];
        long minProd = nums[0];
        long res = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                long temp = maxProd;
                maxProd = minProd;
                minProd = temp;
            }
            maxProd = Math.max(nums[i], maxProd * nums[i]);
            minProd = Math.min(nums[i], minProd * nums[i]);
            res = Math.max(res, maxProd);
        }
        System.out.println(res);
    }
}
