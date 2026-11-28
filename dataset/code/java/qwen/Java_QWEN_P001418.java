import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String allowed = sc.next();
        int n = sc.nextInt();
        Set<Character> allowedSet = new HashSet<>();
        for(char c : allowed.toCharArray()) allowedSet.add(c);
        
        int count = 0;
        for(int i=0; i<n; i++) {
            String word = sc.next();
            boolean consistent = true;
            for(char c : word.toCharArray()) {
                if(!allowedSet.contains(c)) {
                    consistent = false;
                    break;
                }
            }
            if(consistent) count++;
        }
        System.out.println(count);
    }
}
