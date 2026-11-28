import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num = sc.next();
        long target = sc.nextLong();
        addOps(num, target, 0, 0, 0, new StringBuilder());
    }
    
    static void addOps(String num, long target, int idx, long calc, long prev, StringBuilder expr) {
        if(idx == num.length()) {
            if(calc == target) System.out.println(expr.toString());
            return;
        }
        for(int i=idx; i<num.length(); i++) {
            if(i > idx && num.charAt(idx) == '0') break;
            long curr = Long.parseLong(num.substring(idx, i+1));
            int len = expr.length();
            if(idx == 0) {
                expr.append(curr);
                addOps(num, target, i+1, curr, curr, expr);
                expr.setLength(len);
            } else {
                expr.append("+").append(curr);
                addOps(num, target, i+1, calc + curr, curr, expr);
                expr.setLength(len);
                
                expr.append("-").append(curr);
                addOps(num, target, i+1, calc - curr, -curr, expr);
                expr.setLength(len);
                
                expr.append("*").append(curr);
                addOps(num, target, i+1, calc - prev + prev * curr, prev * curr, expr);
                expr.setLength(len);
            }
        }
    }
}
