import java.util.*;
public class Solution {
    static void findSubseq(int[] nums, int idx, List<Integer> cur, Set<List<Integer>> res) {
        if (cur.size() >= 2) res.add(new ArrayList<>(cur));
        for (int i = idx; i < nums.length; i++) {
            if (cur.isEmpty() || nums[i] >= cur.get(cur.size() - 1)) {
                cur.add(nums[i]);
                findSubseq(nums, i + 1, cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            Set<List<Integer>> res = new LinkedHashSet<>();
            findSubseq(nums, 0, new ArrayList<>(), res);
            List<List<Integer>> sortedRes = new ArrayList<>(res);
            sortedRes.sort((a, b) -> {
                for (int i = 0; i < Math.min(a.size(), b.size()); i++) {
                    if (!a.get(i).equals(b.get(i))) return a.get(i) - b.get(i);
                }
                return a.size() - b.size();
            });
            for (List<Integer> seq : sortedRes) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < seq.size(); i++) sb.append(seq.get(i)).append(i + 1 == seq.size() ? "" : " ");
                System.out.println(sb.toString());
            }
        }
    }
}