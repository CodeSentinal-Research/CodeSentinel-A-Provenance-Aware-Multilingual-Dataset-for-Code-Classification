import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        TreeSet<Long> set = new TreeSet<>();
        set.add((long) k);
        long minLength = Long.MAX_VALUE;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            long a = scanner.nextLong();
            sum += a;
            Long ceiling = set.ceiling(sum - k);
            if (ceiling != null) {
                minLength = Math.min(minLength, sum - ceiling);
            }
            set.add(sum);
        }
        if (minLength == Long.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(minLength);
        }
    }
}
