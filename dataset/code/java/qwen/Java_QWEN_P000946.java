import java.util.*;
public class Main {
    static Map<String, Boolean> memo = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(canWin(s));
    }
    static boolean canWin(String s) {
        if(memo.containsKey(s)) return memo.get(s);
        
        for(int i=0; i<s.length()-1; i++) {
            if(s.charAt(i) == '+' && s.charAt(i+1) == '+') {
                String next = s.substring(0, i) + "--" + s.substring(i+2);
                if(!canWin(next)) {
                    memo.put(s, true);
                    return true;
                }
            }
        }
        memo.put(s, false);
        return false;
    }
}
