import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        generate(n, 0, 0, "");
    }
    
    static void generate(int n, int open, int close, String curr) {
        if(curr.length() == 2*n) {
            System.out.println(curr);
            return;
        }
        if(open < n) generate(n, open+1, close, curr + "(");
        if(close < open) generate(n, open, close+1, curr + ")");
    }
}
