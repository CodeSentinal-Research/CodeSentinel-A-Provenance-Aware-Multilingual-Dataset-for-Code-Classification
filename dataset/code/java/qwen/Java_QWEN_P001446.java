import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        if(s1.length() != s2.length()) {
            System.out.println("NO");
            return;
        }
        
        Map<Character, Character> map1 = new HashMap<>();
        Map<Character, Character> map2 = new HashMap<>();
        
        for(int i=0; i<s1.length(); i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            
            if(map1.containsKey(c1) && map1.get(c1) != c2) {
                System.out.println("NO");
                return;
            }
            if(map2.containsKey(c2) && map2.get(c2) != c1) {
                System.out.println("NO");
                return;
            }
            
            map1.put(c1, c2);
            map2.put(c2, c1);
        }
        System.out.println("YES");
    }
}
