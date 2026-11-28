import java.util.*;
public class Main {
    static String[] morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Set<String> transformations = new HashSet<>();
        
        for(int i=0; i<n; i++) {
            String word = sc.next();
            StringBuilder sb = new StringBuilder();
            for(char c : word.toCharArray()) {
                sb.append(morse[c-'a']);
            }
            transformations.add(sb.toString());
        }
        System.out.println(transformations.size());
    }
}
