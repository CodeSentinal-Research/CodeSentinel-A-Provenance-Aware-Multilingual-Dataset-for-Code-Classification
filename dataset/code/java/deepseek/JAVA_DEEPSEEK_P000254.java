import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int count = 0;
        String consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        for (int i = 0; i < s.length(); i++) {
            if (consonants.indexOf(s.charAt(i)) >= 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}
