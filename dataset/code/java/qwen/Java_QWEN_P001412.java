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
        Set<Integer> used = new HashSet<>();
        
        for(int i=0; i<n; i++) {
            if(used.contains(nums[i])) continue;
            if(Arrays.binarySearch(nums, nums[i] + k) >= 0) {
                count++;
                used.add(nums[i]);
                used.add(nums[i] + k);
            }
        }
        System.out.println(count);
    }
}
