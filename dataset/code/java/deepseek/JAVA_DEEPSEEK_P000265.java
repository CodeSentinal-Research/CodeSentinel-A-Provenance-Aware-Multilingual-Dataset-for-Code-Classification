import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        StringBuilder output = new StringBuilder();

        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);
            if (output.indexOf(String.valueOf(currentChar)) == -1) {
                output.append(currentChar);
            }
       }

        System.out.println(output);
    }
}
