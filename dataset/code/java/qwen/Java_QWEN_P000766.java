import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expr = sc.next();
        System.out.println(countTrue(expr, 0, expr.length()-1, true));
    }
    static long countTrue(String expr, int i, int j, boolean isTrue) {
        if(i > j) return 0;
        if(i == j) {
            if(isTrue) return expr.charAt(i) == 'T' ? 1 : 0;
            else return expr.charAt(i) == 'F' ? 1 : 0;
        }
        long ways = 0;
        for(int k=i+1; k<j; k+=2) {
            char op = expr.charAt(k);
            long lT = countTrue(expr, i, k-1, true);
            long lF = countTrue(expr, i, k-1, false);
            long rT = countTrue(expr, k+1, j, true);
            long rF = countTrue(expr, k+1, j, false);
            
            if(op == '&') {
                if(isTrue) ways += lT * rT;
                else ways += lT * rF + lF * rT + lF * rF;
            } else if(op == '|') {
                if(isTrue) ways += lT * rT + lT * rF + lF * rT;
                else ways += lF * rF;
            } else if(op == '^') {
                if(isTrue) ways += lT * rF + lF * rT;
                else ways += lT * rT + lF * rF;
            }
        }
        return ways;
    }
}
