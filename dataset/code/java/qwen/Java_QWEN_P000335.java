import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] queries = new String[n];
        for(int i=0; i<n; i++) queries[i] = sc.next();
        String pattern = sc.next();
        
        for (String q : queries) {
            if (matches(q, pattern)) System.out.print("true ");
            else System.out.print("false ");
        }
    }
    static boolean matches(String query, String pattern) {
        int i = 0;
        for (char c : query.toCharArray()) {
            if (i < pattern.length() && c == pattern.charAt(i)) i++;
            else if (Character.isUpperCase(c)) return false;
        }
        return i == pattern.length();
    }
}
