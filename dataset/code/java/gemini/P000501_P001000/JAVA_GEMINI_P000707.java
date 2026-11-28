import java.util.*;
public class Solution {
    static void genPar(int n, int o, int c, String cur) {
        if (cur.length() == 2 * n) {
            System.out.println(cur);
            return;
        }
        if (o < n) genPar(n, o + 1, c, cur + "(");
        if (c < o) genPar(n, o, c + 1, cur + ")");
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            genPar(scanner.nextInt(), 0, 0, "");
        }
    }
}