import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long product = 1;
        for(int i=0; i<k; i++) product *= nums[i];
        long maxProd = product;
        
        for(int i=k; i<n; i++) {
            product = product / nums[i-k] * nums[i];
            maxProd = Math.max(maxProd, product);
        }
        System.out.println(maxProd);
    }
}
