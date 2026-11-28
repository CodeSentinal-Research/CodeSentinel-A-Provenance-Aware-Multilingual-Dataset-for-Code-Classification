import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(reverseVowels(s));
    }

    public static String reverseVowels(String s) {
        int i = 0, j = s.length() - 1;
        String vowels = "aeiouAEIOU";

        char[] chars = s.toCharArray();

        while (i < j) {
            if (vowels.indexOf(chars[i]) == -1) {
                i++;
                continue;
            }
            if (vowels.indexOf(chars[j]) == -1) {
                j--;
                continue;
            }
            // Swap characters
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;

            i++;
            j--;
        }

        return new String(chars);
    }
}
