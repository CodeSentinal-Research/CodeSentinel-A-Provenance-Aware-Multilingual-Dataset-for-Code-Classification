import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        int v1 = 0, v2 = 0;
        String vowels = "aeiouAEIOU";
        for (int i = 0; i < n / 2; i++) {
            if (vowels.indexOf(s.charAt(i)) != -1) v1++;
        }
        for (int i = n / 2; i < n; i++) {
            if (vowels.indexOf(s.charAt(i)) != -1) v2++;
        }
        System.out.println(v1 == v2 ? "Yes" : "No");
    }
}
