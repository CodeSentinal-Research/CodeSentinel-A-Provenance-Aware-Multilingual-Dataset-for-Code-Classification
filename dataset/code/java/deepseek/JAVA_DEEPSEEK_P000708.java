import java.util.Scanner;

public class Main {
    static int count = 0;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        hanoi(n, 'A', 'B', 'C');
        System.out.println("Total moves: " + count);
    }

    static void hanoi(int n, char from, char aux, char to) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + from + " to " + to);
            count++;
            return;
        }
        hanoi(n - 1, from, to, aux);
        System.out.println("Move disk " + n + " from " + from + " to " + to);
        count++;
        hanoi(n - 1, aux, from, to);
    }
}
