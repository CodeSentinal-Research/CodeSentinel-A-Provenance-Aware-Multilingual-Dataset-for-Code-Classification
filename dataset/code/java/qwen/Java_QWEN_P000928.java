import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        
        BigInteger ba = new BigInteger(a, 2);
        BigInteger bb = new BigInteger(b, 2);
        System.out.println(ba.add(bb).toString(2));
    }
}
