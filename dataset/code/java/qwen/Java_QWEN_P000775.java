import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        genBinNoConsec(n, "");
    }
    static void genBinNoConsec(int n, String curr) {
        if(curr.length() == n) {
            System.out.println(curr);
            return;
        }
        genBinNoConsec(n, curr + "0");
        if(curr.isEmpty() || curr.charAt(curr.length()-1) != '1') {
            genBinNoConsec(n, curr + "1");
        }
    }
}
