import java.util.*;
public class Solution {
    static boolean findOneSubseq(int[] arr, int idx, List<Integer> cur, int curSum, int target) {
        if (idx == arr.length) {
            if (curSum == target && !cur.isEmpty()) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
                System.out.println(sb.toString());
                return true;
            }
            return false;
        }
        cur.add(arr[idx]);
        if (findOneSubseq(arr, idx + 1, cur, curSum + arr[idx], target)) return true;
        cur.remove(cur.size() - 1);
        if (findOneSubseq(arr, idx + 1, cur, curSum, target)) return true;
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            if (!findOneSubseq(nums, 0, new ArrayList<>(), 0, target)) {
                System.out.println(-1);
            }
        }
    }
}