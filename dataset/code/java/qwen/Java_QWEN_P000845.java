import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        
        int low = 0, high = Arrays.stream(nums).max().getAsInt();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canRob(nums, k, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canRob(int[] nums, int k, int capability) {
        int count = 0, i = 0;
        while(i < nums.length) {
            if(nums[i] <= capability) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= k;
    }
}
