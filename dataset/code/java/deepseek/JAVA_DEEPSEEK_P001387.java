import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            map1.put(num, map1.getOrDefault(num, 0) + 1);
        }
        for (int i = 0; i < m; i++) {
            int num = scanner.nextInt();
            map2.put(num, map2.getOrDefault(num, 0) + 1);
        }
        if (map1.equals(map2)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
