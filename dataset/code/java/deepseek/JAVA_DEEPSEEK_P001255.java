import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(minAdditions(s));
    }

    public static int minAdditions(String s) {
        int open = 0, close = 0, pair = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                open++;
            } else {
                close++;
           
                if (close % 2 == 0) {
                    pair++;
                }
            }
        }
        return (open + pair) / 2;
    }
}
