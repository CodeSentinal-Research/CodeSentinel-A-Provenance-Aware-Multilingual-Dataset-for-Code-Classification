import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int positiveCount = 0;
        for(int i=0; i<k; i++) {
            if(nums[i] > 0) positiveCount++;
        }
        int count = (positiveCount == k) ? 1 : 0;
        
        for(int i=k; i<n; i++) {
            if(nums[i] > 0) positiveCount++;
            if(nums[i-k] > 0) positiveCount--;
            if(positiveCount == k) count++;
        }
        System.out.println(count);
    }
}
