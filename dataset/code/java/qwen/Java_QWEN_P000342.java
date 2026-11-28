import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char[] chars = s.toCharArray();
        for (int i = 1; i < chars.length; i += 2) {
            if (Character.isDigit(chars[i])) {
                int shift = chars[i] - '0';
                chars[i] = (char)(chars[i - 1] + shift);
            }
        }
        System.out.println(new String(chars));
    }
}
