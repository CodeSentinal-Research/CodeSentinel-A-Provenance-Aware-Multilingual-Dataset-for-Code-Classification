import java.util.*;
public class Solution {
    static int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        int parent = kthGrammar(n - 1, (k + 1) / 2);
        if (parent == 0) return (k % 2 != 0 ? 0 : 1);
        else return (k % 2 != 0 ? 1 : 0);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            System.out.println(kthGrammar(scanner.nextInt(), scanner.nextInt()));
        }
    }
}