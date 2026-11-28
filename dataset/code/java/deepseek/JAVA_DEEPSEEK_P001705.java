import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int maxWidth = 0;
        for (int i = 0; i < n; i++) {
            int index = scanner.nextInt();
            int level = scanner.nextInt();
            if (!map.containsKey(level)) {
                map.put(level, index);
            } else {
                maxWidth = Math.max(maxWidth, index - map.get(level) + 1);
                map.remove(level);
           }
        }
        System.out.println(maxWidth);
    }
}
