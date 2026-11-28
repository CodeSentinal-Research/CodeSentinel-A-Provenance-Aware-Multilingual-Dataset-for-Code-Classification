import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int[] prefix = new int[s.length()+1];
        for(int i=0; i<s.length(); i++) {
            prefix[i+1] = prefix[i] + (s.charAt(i) - 'a' + 1);
        }
        
        for(int i=1; i<=s.length(); i++) System.out.print(prefix[i] + " ");
    }
}
