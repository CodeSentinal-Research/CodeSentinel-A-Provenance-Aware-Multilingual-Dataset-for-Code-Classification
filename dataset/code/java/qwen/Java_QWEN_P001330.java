import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        backtrack(s, 0, new ArrayList<>());
    }
    
    static void backtrack(String s, int idx, List<String> curr) {
        if(idx == s.length()) {
            System.out.println(curr);
            return;
        }
        for(int i=idx; i<s.length(); i++) {
            if(isPalin(s, idx, i)) {
                curr.add(s.substring(idx, i+1));
                backtrack(s, i+1, curr);
                curr.remove(curr.size()-1);
            }
        }
    }
    
    static boolean isPalin(String s, int l, int r) {
        while(l < r) {
            if(s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}
