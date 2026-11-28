import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Map<Integer, Integer> cnt = new HashMap<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("add")) {
                    int x = scanner.nextInt();
                    cnt.put(x, cnt.getOrDefault(x, 0) + 1);
                } else if (cmd.equals("search")) {
                    int x = scanner.nextInt();
                    System.out.println(cnt.getOrDefault(x, 0) > 0 ? "true" : "false");
                } else if (cmd.equals("erase")) {
                    int x = scanner.nextInt();
                    if (cnt.getOrDefault(x, 0) > 0) {
                        cnt.put(x, cnt.get(x) - 1);
                        System.out.println("true");
                    } else {
                        System.out.println("false");
                    }
                }
            }
        }
    }
}