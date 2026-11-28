import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String order = scanner.next();
        String S = scanner.next();
        System.out.println(customSortString(order, S));
    }

    public static String customSortString(String order, String S) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c: S.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        StringBuilder result = new StringBuilder();
        for (char c: order.toCharArray()) {
            if (count.containsKey(c)) {
                for (int i = 0; i < count.get(c); i++) {
                    result.append(c);
                }
                count.remove(c);
           }
        }

        for (Map.Entry<Character, Integer> entry: count.entrySet()) {
            for (int i = 0; i < entry.getValue(); i++) {
                result.append(entry.getKey());
            }
        }

        return result.toString();
    }
}
