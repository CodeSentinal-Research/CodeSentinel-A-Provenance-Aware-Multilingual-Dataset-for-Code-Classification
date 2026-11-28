import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] res = new int[n];
        int left = 0, right = n - 1;
        int idx = n - 1;
        while(left <= right) {
            if(Math.abs(nums[left]) > Math.abs(nums[right])) {
                res[idx--] = nums[left] * nums[left];
                left++;
            } else {
                res[idx--] = nums[right] * nums[right];
                right--;
            }
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
