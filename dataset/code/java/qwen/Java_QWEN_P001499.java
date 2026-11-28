import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char c = sc.nextLine().charAt(0);
        
        int idx = s.indexOf(c);
        if(idx == -1) {
            System.out.println(s);
        } else {
            StringBuilder sb = new StringBuilder(s.substring(0, idx + 1));
            sb.reverse();
            sb.append(s.substring(idx + 1));
            System.out.println(sb.toString());
        }
    }
}
