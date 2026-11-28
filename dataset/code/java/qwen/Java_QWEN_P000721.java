import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        incSub(nums, 0, new ArrayList<>(), new HashSet<>());
    }
    static void incSub(int[] nums, int idx, List<Integer> curr, Set<List<Integer>> seen) {
        if(curr.size() >= 2) {
            if(!seen.contains(curr)) {
                System.out.println(curr);
                seen.add(new ArrayList<>(curr));
            }
        }
        for(int i=idx; i<nums.length; i++) {
            if(curr.isEmpty() || nums[i] >= curr.get(curr.size() - 1)) {
                curr.add(nums[i]);
                incSub(nums, i + 1, curr, seen);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
