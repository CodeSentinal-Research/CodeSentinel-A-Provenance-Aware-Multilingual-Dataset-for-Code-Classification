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
        
        if(total % 3 != 0) {
            System.out.println(0);
            return;
        }
        
        long target = total / 3;
        long sum = 0;
        long count1 = 0;
        long count2 = 0;
        long ways = 0;
        
        for(int i=0; i<n-1; i++) {
            sum += nums[i];
            if(sum == 2 * target) ways += count1;
            if(sum == target) count1++;
        }
        System.out.println(ways);
    }
}
