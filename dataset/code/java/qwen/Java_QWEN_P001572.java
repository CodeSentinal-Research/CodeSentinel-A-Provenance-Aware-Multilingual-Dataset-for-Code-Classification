import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int sum = 0;
        int count = 0;
        for(int i=0; i<k; i++) sum += nums[i];
        if(sum % 2 == 0) count++;
        
        for(int i=k; i<n; i++) {
            sum += nums[i] - nums[i-k];
            if(sum % 2 == 0) count++;
        }
        System.out.println(count);
    }
}
