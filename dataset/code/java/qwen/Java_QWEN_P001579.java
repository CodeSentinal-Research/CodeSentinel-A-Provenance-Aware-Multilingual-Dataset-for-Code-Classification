import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int negCount = 0;
        for(int i=0; i<k; i++) {
            if(nums[i] < 0) negCount++;
        }
        int maxNeg = negCount;
        
        for(int i=k; i<n; i++) {
            if(nums[i] < 0) negCount++;
            if(nums[i-k] < 0) negCount--;
            maxNeg = Math.max(maxNeg, negCount);
        }
        System.out.println(maxNeg);
    }
}
