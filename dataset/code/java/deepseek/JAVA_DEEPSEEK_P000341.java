import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String firstWord = scanner.next();
        String secondWord = scanner.next();
        String targetWord = scanner.next();

        int firstValue = getValue(firstWord);
        int secondValue = getValue(secondWord);
        int targetValue = getValue(targetWord);

        if (firstValue + secondValue == targetValue) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static int getValue(String word) {
        int value = 0;
        for (char c : word.toCharArray()) {
            value = value * 10 + (c - 'a');
        }
        return value;
    }
}
