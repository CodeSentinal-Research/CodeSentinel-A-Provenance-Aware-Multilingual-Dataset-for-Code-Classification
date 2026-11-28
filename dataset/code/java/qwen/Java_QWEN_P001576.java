import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int zeroCount = 0;
        for(int i=0; i<k; i++) {
            if(nums[i] == 0) zeroCount++;
        }
        int count = (zeroCount > 0) ? 1 : 0;
        
        for(int i=k; i<n; i++) {
            if(nums[i] == 0) zeroCount++;
            if(nums[i-k] == 0) zeroCount--;
            if(zeroCount > 0) count++;
        }
        System.out.println(count);
    }
}
