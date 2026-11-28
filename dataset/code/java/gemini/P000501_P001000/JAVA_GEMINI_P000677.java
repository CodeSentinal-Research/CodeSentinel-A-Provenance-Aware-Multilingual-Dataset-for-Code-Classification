import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            TreeMap<String, String> d = new TreeMap<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("put")) {
                    d.put(scanner.next(), scanner.next());
                } else if (cmd.equals("get")) {
                    String k = scanner.next();
                    System.out.println(d.getOrDefault(k, "-1"));
                } else if (cmd.equals("remove")) {
                    d.remove(scanner.next());
                } else if (cmd.equals("firstKey")) {
                    System.out.println(d.isEmpty() ? "" : d.firstKey());
                } else if (cmd.equals("lastKey")) {
                    System.out.println(d.isEmpty() ? "" : d.lastKey());
                } else if (cmd.equals("nextKey")) {
                    String k = scanner.next();
                    String nxt = d.higherKey(k);
                    System.out.println(nxt == null ? "" : nxt);
                } else if (cmd.equals("previousKey")) {
                    String k = scanner.next();
                    String prev = d.lowerKey(k);
                    System.out.println(prev == null ? "" : prev);
                }
            }
        }
    }
}