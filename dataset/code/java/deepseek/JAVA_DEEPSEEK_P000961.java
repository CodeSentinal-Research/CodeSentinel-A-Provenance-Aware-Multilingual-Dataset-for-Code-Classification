import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long C = scanner.nextLong();
        long X1 = scanner.nextLong();
        long X2 = scanner.nextLong();
        long Y1 = scanner.nextLong();
        long Y2 = scanner.nextLong();

        long count = 0;
        for (long X = X1; X <= X2; X++) {
            for (long Y = Y1; Y <= Y2; Y++) {
                if (A * X + B * Y == C) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}
