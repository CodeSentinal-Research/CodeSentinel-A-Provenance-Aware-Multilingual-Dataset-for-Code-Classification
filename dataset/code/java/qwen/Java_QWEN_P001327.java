import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        backtrack(nums, 0, new ArrayList<>());
    }
    
    static void backtrack(int[] nums, int idx, List<Integer> curr) {
        if(idx == nums.length) {
            System.out.println(curr);
            return;
        }
        // Skip duplicates
        int nextIdx = idx;
        while(nextIdx < nums.length && nums[nextIdx] == nums[idx]) nextIdx++;
        
        backtrack(nums, nextIdx, curr);
        
        curr.add(nums[idx]);
        backtrack(nums, nextIdx, curr);
        curr.remove(curr.size()-1);
    }
}
