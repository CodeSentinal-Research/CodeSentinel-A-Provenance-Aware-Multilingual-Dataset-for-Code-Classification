import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            TreeMap<Integer, Integer> poly = new TreeMap<>(Collections.reverseOrder());
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("insert")) {
                    int c = scanner.nextInt(), e = scanner.nextInt();
                    poly.put(e, poly.getOrDefault(e, 0) + c);
                    if (poly.get(e) == 0) poly.remove(e);
                } else if (cmd.equals("delete")) {
                    int e = scanner.nextInt();
                    poly.remove(e);
                } else if (cmd.equals("evaluate")) {
                    long x = scanner.nextLong();
                    long ans = 0;
                    for (Map.Entry<Integer, Integer> entry : poly.entrySet()) {
                        ans += entry.getValue() * Math.round(Math.pow(x, entry.getKey()));
                    }
                    System.out.println(ans);
                } else if (cmd.equals("display")) {
                    if (poly.isEmpty()) {
                        System.out.println("0");
                    } else {
                        StringBuilder sb = new StringBuilder();
                        boolean first = true;
                        for (Map.Entry<Integer, Integer> entry : poly.entrySet()) {
                            if (!first) sb.append(" + ");
                            if (entry.getKey() > 0) sb.append(entry.getValue()).append("x^").append(entry.getKey());
                            else sb.append(entry.getValue());
                            first = false;
                        }
                        System.out.println(sb.toString());
                    }
                }
            }
        }
    }
}