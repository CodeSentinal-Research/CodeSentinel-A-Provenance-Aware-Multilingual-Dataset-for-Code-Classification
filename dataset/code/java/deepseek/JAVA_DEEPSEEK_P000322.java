import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        System.out.println(detectCapitalUse(word) ? "Yes" : "No");
    }

    public static boolean detectCapitalUse(String word) {
        if (word.equals(word.toUpperCase())) {
            return true;
       }
        if (word.equals(word.toLowerCase())) {
            return true;
        }
        if (Character.isUpperCase(word.charAt(0)) && word.substring(1).equals(word.substring(1).toLowerCase())) {
            return true;
        }
        return false;
    }
}
