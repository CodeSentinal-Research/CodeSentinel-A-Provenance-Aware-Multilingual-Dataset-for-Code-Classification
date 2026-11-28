import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int oddCount = 0;
        for(int i=0; i<k; i++) {
            if(nums[i] % 2 != 0) oddCount++;
        }
        int maxOdd = oddCount;
        
        for(int i=k; i<n; i++) {
            if(nums[i] % 2 != 0) oddCount++;
            if(nums[i-k] % 2 != 0) oddCount--;
            maxOdd = Math.max(maxOdd, oddCount);
        }
        System.out.println(maxOdd);
    }
}
