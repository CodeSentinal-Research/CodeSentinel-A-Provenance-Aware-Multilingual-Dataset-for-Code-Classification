import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        
        if(s.length() != t.length()) {
            System.out.println("NO");
            return;
        }
        
        Map<Character, Character> mapST = new HashMap<>();
        Map<Character, Character> mapTS = new HashMap<>();
        
        for(int i=0; i<s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            
            if(mapST.containsKey(c1) && mapST.get(c1) != c2) {
                System.out.println("NO");
                return;
            }
            if(mapTS.containsKey(c2) && mapTS.get(c2) != c1) {
                System.out.println("NO");
                return;
            }
            
            mapST.put(c1, c2);
            mapTS.put(c2, c1);
        }
        System.out.println("YES");
    }
}
