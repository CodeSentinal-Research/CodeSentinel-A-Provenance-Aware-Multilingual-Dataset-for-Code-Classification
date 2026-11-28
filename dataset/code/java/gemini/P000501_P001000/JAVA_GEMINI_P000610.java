import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> res = new ArrayList<>();
            int curSum = 0;
            scanner.nextInt(); // skip first 0
            for (int i = 1; i < n; i++) {
                int x = scanner.nextInt();
                if (x == 0) {
                    res.add(curSum);
                    curSum = 0;
                } else {
                    curSum += x;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < res.size(); i++) {
                sb.append(res.get(i)).append(i + 1 == res.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}