import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] congruences = new int[n][3];
        for (int i = 0; i < n; i++) {
            congruences[i][0] = scanner.nextInt();
            congruences[i][1] = scanner.nextInt();
            congruences[i][2] = scanner.nextInt();
        }
        System.out.println(earliestTimestamp(congruences));
    }

    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    private static long earliestTimestamp(int[][] congruences) {
        long lcm = 1;
        for (int[] congruence : congruences) {
            lcm = lcm(lcm, congruence[0]);
        }
        long timestamp = 0;
        while (true) {
            boolean satisfiesAll = true;
            for (int[] congruence : congruences) {
                if ((timestamp + congruence[2]) % congruence[0] != 0) {
                    satisfiesAll = false;
                    break;
                }
            }
            if (satisfiesAll) {
                return timestamp;
            }
            timestamp += lcm;
        }
    }
}
