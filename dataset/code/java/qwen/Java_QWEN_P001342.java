import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        backtrack(nums, k, 0, new ArrayList<>());
    }
    
    static void backtrack(int[] nums, int k, int start, List<Integer> curr) {
        if(curr.size() == k) {
            System.out.println(curr);
            return;
        }
        for(int i=start; i<nums.length; i++) {
            if(curr.isEmpty() || nums[i] > curr.get(curr.size()-1)) {
                curr.add(nums[i]);
                backtrack(nums, k, i+1, curr);
                curr.remove(curr.size()-1);
            }
        }
    }
}
