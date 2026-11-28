import java.util.*;
public class Main {
    static int moves = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        hanoi(n, 'A', 'B', 'C');
        System.out.println(moves);
    }
    static void hanoi(int n, char from, char aux, char to) {
        if(n == 0) return;
        hanoi(n - 1, from, to, aux);
        System.out.println("Move disk " + n + " from " + from + " to " + to);
        moves++;
        hanoi(n - 1, aux, from, to);
    }
}
