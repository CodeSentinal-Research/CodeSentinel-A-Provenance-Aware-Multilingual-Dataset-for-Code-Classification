import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        Map<Integer, Integer> count = new HashMap<>();
        int result = 0;
        for (int i = 0; i < N; i++) {
            int num = scanner.nextInt();
            int remainder = num % K;
            if (count.containsKey(remainder)) {
                result += count.get(remainder);
            }
            count.put(remainder, count.getOrDefault(remainder, 0) + 1);
        }
        System.out.println(result);
    }
}
