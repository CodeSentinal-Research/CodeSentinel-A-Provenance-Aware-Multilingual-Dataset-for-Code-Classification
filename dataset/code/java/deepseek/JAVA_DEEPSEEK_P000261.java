import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        StringBuilder output = new StringBuilder();

        for (char c : input.toCharArray()) {
            if (Character.isUpperCase(c)) {
                output.append(Character.toLowerCase(c));
            } else {
                output.append(Character.toUpperCase(c));
           }
        }

        System.out.println(output.toString());
    }
}
