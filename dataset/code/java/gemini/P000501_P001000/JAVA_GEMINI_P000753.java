import java.util.*;
public class Solution {
    static void findAllSubseq(int[] arr, int idx, List<Integer> cur, int curSum, int target, List<List<Integer>> res) {
        if (idx == arr.length) {
            if (curSum == target && !cur.isEmpty()) res.add(new ArrayList<>(cur));
            return;
        }
        findAllSubseq(arr, idx + 1, cur, curSum, target, res);
        cur.add(arr[idx]);
        findAllSubseq(arr, idx + 1, cur, curSum + arr[idx], target, res);
        cur.remove(cur.size() - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            List<List<Integer>> res = new ArrayList<>();
            findAllSubseq(nums, 0, new ArrayList<>(), 0, target, res);
            res.sort((a, b) -> {
                for (int i = 0; i < Math.min(a.size(), b.size()); i++) {
                    if (!a.get(i).equals(b.get(i))) return a.get(i) - b.get(i);
                }
                return a.size() - b.size();
            });
            for (List<Integer> seq : res) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < seq.size(); i++) sb.append(seq.get(i)).append(i + 1 == seq.size() ? "" : " ");
                System.out.println(sb.toString());
            }
        }
    }
}