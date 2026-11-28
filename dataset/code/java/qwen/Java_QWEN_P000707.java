import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        genPar(n, 0, 0, "");
    }
    static void genPar(int n, int open, int close, String curr) {
        if(curr.length() == 2 * n) {
            System.out.println(curr);
            return;
        }
        if(open < n) genPar(n, open + 1, close, curr + "(");
        if(close < open) genPar(n, open, close + 1, curr + ")");
    }
}
