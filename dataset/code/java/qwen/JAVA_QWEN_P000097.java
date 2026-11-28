import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        boolean hasZero = s.contains("0");
        boolean startsZero = s.startsWith("0");
        System.out.println(hasZero && !startsZero ? "Duck" : "Not Duck");
    }
}
