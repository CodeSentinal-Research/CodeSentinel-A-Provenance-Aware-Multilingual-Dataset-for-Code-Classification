import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        
        Set<String> res = new TreeSet<>();
        for(int i=0; i<=n-10; i++) {
            String sub = s.substring(i, i+10);
            if(s.indexOf(sub, i+1) != -1) {
                res.add(sub);
            }
        }
        
        for(String r : res) System.out.println(r);
    }
}
