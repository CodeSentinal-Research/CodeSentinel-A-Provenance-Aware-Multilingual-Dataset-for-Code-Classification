import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        String abbr = sc.next();
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (Character.isLetter(abbr.charAt(j))) {
                if (word.charAt(i) != abbr.charAt(j)) {
                    System.out.println("No"); return;
                }
                i++; j++;
            } else {
                if (abbr.charAt(j) == '0') {
                    System.out.println("No"); return;
                }
                int num = 0;
                while (j < abbr.length() && Character.isDigit(abbr.charAt(j))) {
                    num = num * 10 + (abbr.charAt(j) - '0');
                    j++;
                }
                i += num;
            }
        }
        System.out.println(i == word.length() && j == abbr.length() ? "Yes" : "No");
    }
}
