import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        char c = scanner.next().charAt(0);
        scanner.close();

        int index = str.indexOf(c);
        if (index != -1) {
            StringBuilder sb = new StringBuilder(str.substring(0, index + 1));
            str = sb.reverse().toString() + str.substring(index + 1);
       }

        System.out.println(str);
    }
}
