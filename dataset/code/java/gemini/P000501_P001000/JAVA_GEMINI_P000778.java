import java.util.*;
public class Solution {
    static int minDiff = Integer.MAX_VALUE;
    static List<Integer> bestPart = new ArrayList<>();
    static void backtrack(int n, int[] nums, int idx, int count, int curSum, int total, List<Integer> curPart, int half) {
        if (count == half) {
            int diff = Math.abs(total - 2 * curSum);
            if (diff < minDiff) {
                minDiff = diff;
                bestPart = new ArrayList<>(curPart);
            }
            return;
        }
        if (idx == n || (half - count) > (n - idx)) return;
        curPart.add(nums[idx]);
        backtrack(n, nums, idx + 1, count + 1, curSum + nums[idx], total, curPart, half);
        curPart.remove(curPart.size() - 1);
        backtrack(n, nums, idx + 1, count, curSum, total, curPart, half);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            int total = 0;
            for (int i = 0; i < n; i++) { nums[i] = scanner.nextInt(); total += nums[i]; }
            backtrack(n, nums, 0, 0, 0, total, new ArrayList<>(), n / 2);
            System.out.println(minDiff);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < bestPart.size(); i++) sb.append(bestPart.get(i)).append(i + 1 == bestPart.size() ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}