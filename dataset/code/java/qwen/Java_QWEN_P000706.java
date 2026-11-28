import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        genBin(n, "");
    }
    static void genBin(int n, String curr) {
        if(curr.length() == n) {
            System.out.println(curr);
            return;
        }
        genBin(n, curr + "0");
        genBin(n, curr + "1");
    }
}
