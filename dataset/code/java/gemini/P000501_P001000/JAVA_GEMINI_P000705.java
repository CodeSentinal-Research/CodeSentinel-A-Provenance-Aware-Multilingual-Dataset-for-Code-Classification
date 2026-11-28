import java.util.*;
public class Solution {
    static void genSubseq(int[] arr, int idx, List<Integer> cur) {
        if (idx == arr.length) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cur.size(); i++) {
                sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
            }
            System.out.println(sb.toString());
            return;
        }
        genSubseq(arr, idx + 1, cur);
        cur.add(arr[idx]);
        genSubseq(arr, idx + 1, cur);
        cur.remove(cur.size() - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            genSubseq(nums, 0, new ArrayList<>());
        }
    }
}