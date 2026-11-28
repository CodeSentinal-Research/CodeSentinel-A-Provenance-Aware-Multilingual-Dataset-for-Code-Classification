import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        
        Set<String> palindromes = new HashSet<>();
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isPalin(s, i, j)) {
                    palindromes.add(s.substring(i, j+1));
                }
            }
        }
        System.out.println(palindromes.size());
    }
    
    static boolean isPalin(String s, int l, int r) {
        while(l < r) {
            if(s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}
