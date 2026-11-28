import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printNums(1, n);
    }
    static void printNums(int curr, int n) {
        if(curr > n) return;
        System.out.print(curr + " ");
        printNums(curr + 1, n);
    }
}
