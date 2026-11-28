import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        Arrays.sort(nums);
        subsets2(nums, 0, new ArrayList<>(), new HashSet<>());
    }
    static void subsets2(int[] nums, int i, List<Integer> curr, Set<List<Integer>> seen) {
        if(i == nums.length) {
            if(!seen.contains(curr)) {
                System.out.println(curr);
                seen.add(new ArrayList<>(curr));
            }
            return;
        }
        subsets2(nums, i + 1, curr, seen);
        curr.add(nums[i]);
        subsets2(nums, i + 1, curr, seen);
        curr.remove(curr.size() - 1);
    }
}
