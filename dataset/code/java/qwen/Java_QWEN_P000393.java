import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] contacts = new String[n];
        for(int i=0; i<n; i++) contacts[i] = sc.next();
        String prefix = sc.next();
        for(String c : contacts) {
            if(c.startsWith(prefix)) System.out.println(c);
        }
    }
}
