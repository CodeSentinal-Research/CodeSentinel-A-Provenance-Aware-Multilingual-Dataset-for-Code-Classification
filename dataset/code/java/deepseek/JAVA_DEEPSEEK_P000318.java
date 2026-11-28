import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        String abbr = scanner.next();
        System.out.println(validWordAbbreviation(word, abbr) ? "Yes" : "No");
    }

    public static boolean validWordAbbreviation(String word, String abbr) {
        int i = 0, j = 0;
        while (i < word.length() && j < abbr.length()) {
            if (abbr.charAt(j) == '0') {
                return false;
            }
            if (Character.isDigit(abbr.charAt(j))) {
                int start = j;
                while (j < abbr.length() && Character.isDigit(abbr.charAt(j))) {
                    j++;
                }
                int num = Integer.parseInt(abbr.substring(start, j));
                if (i + num > word.length()) {
                    return false;
               }
            } else if (word.charAt(i) != abbr.charAt(j)) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        return i == word.length() && j == abbr.length();
    }
}
