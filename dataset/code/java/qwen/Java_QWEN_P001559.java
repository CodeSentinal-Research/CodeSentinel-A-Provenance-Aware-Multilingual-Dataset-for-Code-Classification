import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long product = 1;
        int count = 0;
        int left = 0;
        for(int right=0; right<n; right++) {
            product *= nums[right];
            while(left <= right && product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        System.out.println(count);
    }
}
