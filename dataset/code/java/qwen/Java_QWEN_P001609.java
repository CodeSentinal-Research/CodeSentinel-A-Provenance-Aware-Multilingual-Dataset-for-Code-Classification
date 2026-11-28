import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        long total = 0;
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
            total += nums[i];
        }
        
        int count = 0;
        long leftSum = 0;
        for(int i=0; i<n; i++) {
            if(leftSum == total - leftSum - nums[i]) count++;
            leftSum += nums[i];
        }
        System.out.println(count);
    }
}
