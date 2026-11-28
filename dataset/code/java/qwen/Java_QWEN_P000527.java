import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expression = sc.next();
        System.out.println(evaluate(expression) ? "true" : "false");
    }
    static boolean evaluate(String expr) {
        if(expr.equals("t")) return true;
        if(expr.equals("f")) return false;
        char op = expr.charAt(0);
        String inner = expr.substring(2, expr.length() - 1);
        List<String> args = splitArgs(inner);
        if(op == '!') return !evaluate(args.get(0));
        if(op == '&') {
            for(String arg : args) if(!evaluate(arg)) return false;
            return true;
        }
        if(op == '|') {
            for(String arg : args) if(evaluate(arg)) return true;
            return false;
        }
        return false;
    }
    static List<String> splitArgs(String s) {
        List<String> res = new ArrayList<>();
        int depth = 0;
        int start = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(') depth++;
            else if(s.charAt(i) == ')') depth--;
            else if(s.charAt(i) == ',' && depth == 0) {
                res.add(s.substring(start, i));
                start = i + 1;
            }
        }
        res.add(s.substring(start));
        return res;
    }
}
