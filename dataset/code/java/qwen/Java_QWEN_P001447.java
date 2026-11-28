import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        Map<String, String> parent = new HashMap<>();
        
        int p = sc.nextInt();
        for(int i=0; i<p; i++) {
            String a = sc.next();
            String b = sc.next();
            parent.put(a, b);
            parent.put(b, a);
        }
        
        String[] words1 = s1.split(" ");
        String[] words2 = s2.split(" ");
        
        if(words1.length != words2.length) {
            System.out.println("NO");
            return;
        }
        
        for(int i=0; i<words1.length; i++) {
            if(!isSimilar(words1[i], words2[i], parent)) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
    
    static boolean isSimilar(String w1, String w2, Map<String, String> parent) {
        if(w1.equals(w2)) return true;
        return parent.containsKey(w1) && parent.get(w1).equals(w2);
    }
}
