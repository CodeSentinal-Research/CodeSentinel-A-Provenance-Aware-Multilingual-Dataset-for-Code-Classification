import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] strings = new String[n];
        for (int i = 0; i < n; i++) {
            strings[i] = scanner.next();
        }
        int maxLength = 0;
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (strings[i].length() > maxLength) {
                maxLength = strings[i].length();
                maxIndex = i;
           }
        }
        System.out.println(maxIndex);
    }
}
