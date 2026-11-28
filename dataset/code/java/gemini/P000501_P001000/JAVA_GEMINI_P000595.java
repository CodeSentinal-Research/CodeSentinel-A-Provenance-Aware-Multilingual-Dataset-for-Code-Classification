import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            String line1 = scanner.nextLine().trim();
            String line2 = scanner.hasNextLine() ? scanner.nextLine().trim() : "";
            List<Integer> l1 = new ArrayList<>(), l2 = new ArrayList<>();
            Scanner s1 = new Scanner(line1); while (s1.hasNextInt()) l1.add(s1.nextInt());
            Scanner s2 = new Scanner(line2); while (s2.hasNextInt()) l2.add(s2.nextInt());
            if (!l1.isEmpty() && l1.size() - 1 == l1.get(0)) l1.remove(0);
            if (!l2.isEmpty() && l2.size() - 1 == l2.get(0)) l2.remove(0);
            List<Integer> res = new ArrayList<>();
            int carry = 0, i = 0, j = 0;
            while (i < l1.size() || j < l2.size() || carry > 0) {
                int v1 = i < l1.size() ? l1.get(i) : 0;
                int v2 = j < l2.size() ? l2.get(j) : 0;
                int sum = v1 + v2 + carry;
                res.add(sum % 10);
                carry = sum / 10;
                i++; j++;
            }
            StringBuilder sb = new StringBuilder();
            for (int k = 0; k < res.size(); k++) {
                sb.append(res.get(k)).append(k + 1 == res.size() ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}