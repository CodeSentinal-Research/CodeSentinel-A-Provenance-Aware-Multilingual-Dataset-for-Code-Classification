import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] deliciousness = new long[n];
        for (int i = 0; i < n; i++) {
            deliciousness[i] = scanner.nextLong();
        }
        long count = countGoodMeals(deliciousness);
        System.out.println(count);
    }

    private static long countGoodMeals(long[] deliciousness) {
        long count = 0;
        Map<Long, Long> map = new HashMap<>();
        for (long value : deliciousness) {
            map.put(value, map.getOrDefault(value, 0L) + 1);
        }
        for (long value : map.keySet()) {
            long powerOfTwo = 1;
            while (powerOfTwo <= value) {
                powerOfTwo <<= 1;
            }
            if (powerOfTwo == value) {
                count += map.get(value);
            }
        }
        return count;
    }
}
