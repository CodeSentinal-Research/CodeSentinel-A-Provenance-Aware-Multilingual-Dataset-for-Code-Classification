import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String source = sc.next();
        String target = sc.next();
        int count = 0, i = 0;
        while (i < target.length()) {
            int prev = i;
            for (char c : source.toCharArray()) {
                if (i < target.length() && c == target.charAt(i)) i++;
            }
            if (prev == i) {
                System.out.println("-1"); return;
            }
            count++;
        }
        System.out.println(count);
    }
}
