import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String bin = sc.next();
        long dec = 0;
        for (char c : bin.toCharArray()) {
            dec = dec * 2 + (c - '0');
        }
        System.out.println(dec);
    }
}
