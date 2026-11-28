import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        int[] zeros = new int[n + 1];
        for (int i = 0; i < n; i++) {
            zeros[i + 1] = zeros[i] + (s.charAt(i) == '0' ? 1 : 0);
        }
        int maxScore = 0;
        for (int i = 1; i < n; i++) {
            int leftZeros = zeros[i];
            int rightOnes = (n - i) - (zeros[n] - zeros[i]);
            maxScore = Math.max(maxScore, leftZeros + rightOnes);
        }
        System.out.println(maxScore);
    }
}
