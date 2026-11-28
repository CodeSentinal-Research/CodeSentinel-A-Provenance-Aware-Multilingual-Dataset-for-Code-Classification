import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 1;
        int currLen = 1;
        for(int i=1; i<n; i++) {
            if((nums[i] > nums[i-1] && (i==1 || nums[i-2] > nums[i-1])) || 
               (nums[i] < nums[i-1] && (i==1 || nums[i-2] < nums[i-1]))) {
                currLen++;
                maxLen = Math.max(maxLen, currLen);
            } else {
                currLen = 2;
            }
        }
        System.out.println(maxLen);
    }
}
