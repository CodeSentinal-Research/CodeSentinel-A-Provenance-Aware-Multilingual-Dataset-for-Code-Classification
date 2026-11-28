import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxVal = Integer.MIN_VALUE;
        for(int i=0; i<k; i++) {
            maxVal = Math.max(maxVal, nums[i]);
        }
        System.out.println(maxVal);
    }
}
