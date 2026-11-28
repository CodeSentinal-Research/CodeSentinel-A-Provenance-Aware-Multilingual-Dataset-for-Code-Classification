import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> vals = new ArrayList<>();
            for (int i = 0; i < n; i++) vals.add(scanner.nextInt());
            vals.remove(n / 2);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < vals.size(); i++) {
                sb.append(vals.get(i)).append(i + 1 == vals.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}