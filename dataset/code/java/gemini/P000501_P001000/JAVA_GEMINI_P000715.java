import java.util.*;
public class Solution {
    static void subsetsWithDup(int[] nums, int idx, List<Integer> cur) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
        System.out.println(sb.toString());
        for (int i = idx; i < nums.length; i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            cur.add(nums[i]);
            subsetsWithDup(nums, i + 1, cur);
            cur.remove(cur.size() - 1);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            Arrays.sort(nums);
            subsetsWithDup(nums, 0, new ArrayList<>());
        }
    }
}