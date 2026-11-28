import java.util.*;
public class Solution {
    static void subsetSum(int[] arr, int idx, int curSum, List<Integer> res) {
        if (idx == arr.length) {
            res.add(curSum);
            return;
        }
        subsetSum(arr, idx + 1, curSum, res);
        subsetSum(arr, idx + 1, curSum + arr[idx], res);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            List<Integer> res = new ArrayList<>();
            subsetSum(nums, 0, 0, res);
            Collections.sort(res);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < res.size(); i++) {
                sb.append(res.get(i)).append(i + 1 == res.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}