import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
        }
        System.out.println(res);
    }
}
