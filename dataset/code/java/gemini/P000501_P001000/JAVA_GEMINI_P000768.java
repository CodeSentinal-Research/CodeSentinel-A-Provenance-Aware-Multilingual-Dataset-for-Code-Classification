import java.util.*;
public class Solution {
    static long numTrees(int n) {
        long c = 1;
        for (int i = 0; i < n; i++) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return c;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            System.out.println(numTrees(scanner.nextInt()));
        }
    }
}