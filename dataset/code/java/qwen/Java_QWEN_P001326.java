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
        backtrack(nums, idx+1, curr);
        curr.add(nums[idx]);
        backtrack(nums, idx+1, curr);
        curr.remove(curr.size()-1);
    }
}
