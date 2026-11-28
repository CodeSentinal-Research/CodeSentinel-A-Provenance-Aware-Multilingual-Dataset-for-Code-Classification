import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < 2 * n; i++) {
            int num = scanner.nextInt();
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int i = 0; i < 2 * n; i++) {
            int num = scanner.nextInt();
            if (map.get(num) == 0) {
                System.out.println(num);
                break;
            }
        }
    }
}
