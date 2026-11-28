import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(minSwaps(s));
    }

    public static int minSwaps(String s) {
        int swap = 0;
        int balance = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) {
                swap++;
                balance++;
            }
        }
        return swap;
    }
}
