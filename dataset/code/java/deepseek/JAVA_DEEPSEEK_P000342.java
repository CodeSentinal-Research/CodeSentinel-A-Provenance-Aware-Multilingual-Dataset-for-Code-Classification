import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        StringBuilder output = new StringBuilder();
        
        for (char c : input.toCharArray()) {
            if (Character.isLetter(c)) {
                output.append(c);
            } else {
                int newChar = c + 1;
                if (newChar > '9') {
                    newChar = '0';
                }
                output.append((char) newChar);
            }
        }
        
        System.out.println(output);
    }
}
