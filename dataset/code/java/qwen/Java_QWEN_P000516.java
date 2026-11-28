import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        int left = 0, right = n - 1;
        while(left < n && nums[left] == sorted[left]) left++;
        while(right >= 0 && nums[right] == sorted[right]) right--;
        System.out.println(left < right ? right - left + 1 : 0);
    }
}
