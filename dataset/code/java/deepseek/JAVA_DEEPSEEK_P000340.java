import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        String brokenLetters = scanner.nextLine();

        int count = 0;
        for (String word : text.split(" ")) {
            boolean canType = true;
            for (char c : word.toCharArray()) {
                if (brokenLetters.indexOf(c) != -1) {
                    canType = false;
                    break;
                }
            }
            if (canType) {
                count++;
           }
        }

        System.out.println(count);
    }
}
