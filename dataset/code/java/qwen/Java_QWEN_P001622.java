import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int count = 0;
        long sum = 0;
        for(int num : nums) {
            sum += num;
            if(sum > 0) count++;
        }
        System.out.println(count);
    }
}
