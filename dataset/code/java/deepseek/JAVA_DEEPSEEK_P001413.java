import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int largestUniqueNum = -1;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1) {
                largestUniqueNum = entry.getKey();
                break;
            }
        }
        System.out.println(largestUniqueNum);
    }
}
