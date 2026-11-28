import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (map.containsKey(num ^ k)) {
                count += map.get(num ^ k);
            }
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        System.out.println(count);
    }
}
