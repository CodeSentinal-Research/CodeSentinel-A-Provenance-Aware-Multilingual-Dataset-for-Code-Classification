import java.util.*;
public class Solution {
    static void perm(int[] nums, List<Integer> cur, boolean[] used) {
        if (cur.size() == nums.length) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
            System.out.println(sb.toString());
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                used[i] = true;
                cur.add(nums[i]);
                perm(nums, cur, used);
                cur.remove(cur.size() - 1);
                used[i] = false;
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            Arrays.sort(nums);
            perm(nums, new ArrayList<>(), new boolean[n]);
        }
    }
}