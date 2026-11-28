import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = scanner.nextInt();
                if (res.isEmpty() || res.get(res.size() - 1) != x) res.add(x);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < res.size(); i++) {
                sb.append(res.get(i)).append(i + 1 == res.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}