import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        int count = 0;
        int i = 0;
        while(i < n) {
            int j = i + 1;
            while(j < n && nums[j] == nums[i]) j++;
            if(Arrays.binarySearch(nums, nums[i] + k) >= 0) {
                count++;
            }
            i = j;
        }
        System.out.println(count);
    }
}
