import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        String[] dict = new String[n];
        for(int i=0; i<n; i++) dict[i] = sc.next();
        
        String best = "";
        for(String w : dict) {
            if(isSubsequence(w, s)) {
                if(w.length() > best.length() || (w.length() == best.length() && w.compareTo(best) < 0)) {
                    best = w;
                }
            }
        }
        System.out.println(best);
    }
    
    static boolean isSubsequence(String sub, String s) {
        int i = 0;
        for(char c : s.toCharArray()) {
            if(i < sub.length() && c == sub.charAt(i)) i++;
        }
        return i == sub.length();
    }
}
