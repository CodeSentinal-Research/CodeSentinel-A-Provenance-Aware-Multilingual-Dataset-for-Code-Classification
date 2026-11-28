import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        StringBuilder output = new StringBuilder();

        for (char c : input.toCharArray()) {
            if (isVowelOrSpace(c)) {
                output.append(c);
            }
        }

        System.out.println(output.toString());
    }

    private static boolean isVowelOrSpace(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == ' ';
    }
}