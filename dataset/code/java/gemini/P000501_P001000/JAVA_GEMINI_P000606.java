import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int cap = scanner.nextInt(), q = scanner.nextInt();
            LinkedHashMap<Integer, Integer> cache = new LinkedHashMap<Integer, Integer>(cap, 0.75f, true) {
                protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
                    return size() > cap;
                }
            };
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("put")) {
                    cache.put(scanner.nextInt(), scanner.nextInt());
                } else if (cmd.equals("get")) {
                    int k = scanner.nextInt();
                    System.out.println(cache.getOrDefault(k, -1));
                }
            }
        }
    }
}