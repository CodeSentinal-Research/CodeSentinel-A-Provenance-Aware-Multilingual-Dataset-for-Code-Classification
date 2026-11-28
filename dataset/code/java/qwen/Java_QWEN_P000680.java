import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printNums(n);
    }
    static void printNums(int n) {
        if(n < 1) return;
        System.out.print(n + " ");
        printNums(n - 1);
    }
}
