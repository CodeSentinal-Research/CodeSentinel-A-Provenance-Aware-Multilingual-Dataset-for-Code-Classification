import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long sum = 0;
        int maxLen = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum > 0) maxLen = i + 1;
        }
        System.out.println(maxLen);
    }
}
