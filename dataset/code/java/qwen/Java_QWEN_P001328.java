import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        backtrack(nums, 0, new boolean[n], new ArrayList<>());
    }
    
    static void backtrack(int[] nums, int idx, boolean[] used, List<Integer> curr) {
        if(curr.size() == nums.length) {
            System.out.println(curr);
            return;
        }
        for(int i=0; i<nums.length; i++) {
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            curr.add(nums[i]);
            backtrack(nums, idx+1, used, curr);
            curr.remove(curr.size()-1);
            used[i] = false;
        }
    }
}
