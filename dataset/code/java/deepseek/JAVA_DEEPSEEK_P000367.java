import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] strings = new String[n];
        for (int i = 0; i < n; i++) {
            strings[i] = scanner.next();
        }
        int minLengthIndex = 0;
        for (int i = 1; i < n; i++) {
            if (strings[i].length() < strings[minLengthIndex].length()) {
                minLengthIndex = i;
            }
       }
        System.out.println(minLengthIndex);
    }
}
