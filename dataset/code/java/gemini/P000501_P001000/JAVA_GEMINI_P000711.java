import java.util.*;
public class Solution {
    static void comb(int n, int k, int start, List<Integer> cur) {
        if (cur.size() == k) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
            System.out.println(sb.toString());
            return;
        }
        for (int i = start; i <= n; i++) {
            cur.add(i);
            comb(n, k, i + 1, cur);
            cur.remove(cur.size() - 1);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            comb(scanner.nextInt(), scanner.nextInt(), 1, new ArrayList<>());
        }
    }
}