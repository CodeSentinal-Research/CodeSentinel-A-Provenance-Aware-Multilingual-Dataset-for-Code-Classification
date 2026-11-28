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
        
        for(int num : nums) {
            if(used.contains(num)) continue;
            if(Arrays.binarySearch(nums, num + k) >= 0) {
                count++;
                used.add(num);
                used.add(num + k);
            }
        }
        System.out.println(count);
    }
}
