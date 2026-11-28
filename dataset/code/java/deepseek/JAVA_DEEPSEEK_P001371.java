import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int target = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (map.containsKey(target - num)) {
                System.out.println(map.get(target - num) + " " + i);
                return;
            } else {
                map.put(num, i);
            }
        }
        System.out.println(-1);
    }
}
