import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        boolean isIncreasing = true;
        for(int i=1; i<k; i++) {
            if(nums[i] <= nums[i-1]) {
                isIncreasing = false;
                break;
            }
        }
        int count = isIncreasing ? 1 : 0;
        
        for(int i=k; i<n; i++) {
            // Check if new window is strictly increasing
            boolean valid = true;
            for(int j=i-k+1; j<i; j++) {
                if(nums[j+1] <= nums[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid) count++;
        }
        System.out.println(count);
    }
}
