import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        String s = sc.next();
        
        int count = 0;
        for (String w : words) {
            if (s.startsWith(w)) count++;
        }
        System.out.println(count);
    }
}
