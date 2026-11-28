import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        casePerm(s, 0, new StringBuilder());
    }
    static void casePerm(String s, int i, StringBuilder curr) {
        if(i == s.length()) {
            System.out.println(curr.toString());
            return;
        }
        char c = s.charAt(i);
        if(Character.isLetter(c)) {
            curr.append(Character.toLowerCase(c));
            casePerm(s, i + 1, curr);
            curr.deleteCharAt(curr.length() - 1);
            
            curr.append(Character.toUpperCase(c));
            casePerm(s, i + 1, curr);
            curr.deleteCharAt(curr.length() - 1);
        } else {
            curr.append(c);
            casePerm(s, i + 1, curr);
            curr.deleteCharAt(curr.length() - 1);
        }
    }
}
