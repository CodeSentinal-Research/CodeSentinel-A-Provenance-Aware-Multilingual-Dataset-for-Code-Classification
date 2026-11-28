import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char c = sc.next().charAt(0);
        int n = s.length();
        int[] res = new int[n];
        Arrays.fill(res, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == c) res[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            res[i] = Math.min(res[i], res[i - 1] + 1);
        }
        for (int i = n - 2; i >= 0; i--) {
            res[i] = Math.min(res[i], res[i + 1] + 1);
        }
        for (int x : res) System.out.print(x + " ");
    }
}
