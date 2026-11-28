import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n == 0) System.out.println(0);
        else decToBin(n);
    }
    static void decToBin(long n) {
        if(n == 0) return;
        decToBin(n / 2);
        System.out.print(n % 2);
    }
}
