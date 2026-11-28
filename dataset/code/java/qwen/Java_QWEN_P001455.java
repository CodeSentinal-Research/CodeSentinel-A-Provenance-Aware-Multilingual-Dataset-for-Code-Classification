import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        
        String longest = "";
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<=n; j++) {
                String sub = s.substring(i, j);
                if(s.indexOf(sub) != s.lastIndexOf(sub)) {
                    if(sub.length() > longest.length() || (sub.length() == longest.length() && sub.compareTo(longest) < 0)) {
                        longest = sub;
                    }
                }
            }
        }
        System.out.println(longest);
    }
}
