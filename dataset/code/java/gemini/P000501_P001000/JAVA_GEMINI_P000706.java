import java.util.*;
public class Solution {
    static void genBin(int n, String cur) {
        if (cur.length() == n) {
            System.out.println(cur);
            return;
        }
        genBin(n, cur + "0");
        genBin(n, cur + "1");
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            genBin(scanner.nextInt(), "");
        }
    }
}