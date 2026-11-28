import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        int count = 0;
        for (String w : words) {
            int i = 0;
            for (char c : s.toCharArray()) {
                if (i < w.length() && c == w.charAt(i)) i++;
            }
            if (i == w.length()) count++;
        }
        System.out.println(count);
    }
}
