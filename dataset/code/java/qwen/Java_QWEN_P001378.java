import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pattern = sc.next();
        String str = sc.nextLine().trim();
        String[] words = str.split("\\s+");
        
        if(pattern.length() != words.length) {
            System.out.println("NO");
            return;
        }
        
        Map<Character, String> mapPT = new HashMap<>();
        Map<String, Character> mapTP = new HashMap<>();
        
        for(int i=0; i<pattern.length(); i++) {
            char p = pattern.charAt(i);
            String w = words[i];
            
            if(mapPT.containsKey(p) && !mapPT.get(p).equals(w)) {
                System.out.println("NO");
                return;
            }
            if(mapTP.containsKey(w) && mapTP.get(w) != p) {
                System.out.println("NO");
                return;
            }
            
            mapPT.put(p, w);
            mapTP.put(w, p);
        }
        System.out.println("YES");
    }
}
