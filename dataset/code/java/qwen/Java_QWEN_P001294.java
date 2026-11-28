import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        long sum = 0;
        int count = 0;
        for(int i=n-1; i>=0; i--) {
            sum += nums[i];
            if(sum > 0) count++;
            else break;
        }
        System.out.println(count);
    }
}
