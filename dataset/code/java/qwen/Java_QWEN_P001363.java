import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        generateBinary(n, "");
    }
    
    static void generateBinary(int n, String curr) {
        if(curr.length() == n) {
            System.out.println(curr);
            return;
        }
        generateBinary(n, curr + "0");
        if(curr.isEmpty() || curr.charAt(curr.length()-1) != '1') {
            generateBinary(n, curr + "1");
        }
    }
}
