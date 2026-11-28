import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] congruences = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                congruences[i][j] = scanner.nextInt();
            }
        }
        System.out.println(solve(congruences));
    }

    private static long solve(int[][] congruences) {
        for (int[] congruence : congruences) {
            if (congruence[0] < 0 || congruence[1] < 0) {
                return -1;
            }
        }
        long M = 1;
        for (int[] congruence : congruences) {
            M *= congruence[1];
        }
        long[] Mi = new long[congruences.length];
        for (int i = 0; i < congruences.length; i++) {
            Mi[i] = M / congruences[i][1];
        }
        long[] xi = new long[congruences.length];
        for (int i = 0; i < congruences.length; i++) {
            xi[i] = pow(Mi[i], congruences[i][1] - 2, congruences[i][1]);
        }
        long result = 0;
        for (int i = 0; i < congruences.length; i++) {
            result += congruences[i][0] * Mi[i] * xi[i];
        }
        return result % M;
    }

    private static long pow(long a, long b, long m) {
        long result = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
}
