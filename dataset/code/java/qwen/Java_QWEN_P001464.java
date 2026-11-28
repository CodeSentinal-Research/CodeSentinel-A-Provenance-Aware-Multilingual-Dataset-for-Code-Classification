import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int k = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }
        while(k < n) nums[k++] = 0;
        
        for(int x : nums) System.out.print(x + " ");
    }
}
