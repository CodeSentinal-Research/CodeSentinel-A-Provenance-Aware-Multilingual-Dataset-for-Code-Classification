import java.util.*;
public class Solution {
    static void combSum(int[] cands, int target, int idx, List<Integer> cur) {
        if (target == 0) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
            System.out.println(sb.toString());
            return;
        }
        for (int i = idx; i < cands.length; i++) {
            if (cands[i] > target) break;
            cur.add(cands[i]);
            combSum(cands, target - cands[i], i, cur);
            cur.remove(cur.size() - 1);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] cands = new int[n];
            for (int i = 0; i < n; i++) cands[i] = scanner.nextInt();
            int target = scanner.nextInt();
            Arrays.sort(cands);
            combSum(cands, target, 0, new ArrayList<>());
        }
    }
}