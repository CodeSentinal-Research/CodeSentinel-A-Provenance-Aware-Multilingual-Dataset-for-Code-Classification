import java.util.*;
public class Solution {
    static void genNoConsOnes(int n, String cur) {
        if (cur.length() == n) {
            System.out.println(cur);
            return;
        }
        genNoConsOnes(n, cur + "0");
        if (cur.isEmpty() || cur.charAt(cur.length() - 1) != '1') {
            genNoConsOnes(n, cur + "1");
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            genNoConsOnes(scanner.nextInt(), "");
        }
    }
}