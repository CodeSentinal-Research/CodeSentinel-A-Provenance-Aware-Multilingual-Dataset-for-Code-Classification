import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        
        long gcdAb = a;
        long tempB = b;
        while (tempB != 0) {
            long t = tempB;
            tempB = gcdAb % tempB;
            gcdAb = t;
        }
        long lcmAb = (a * b) / gcdAb;
        
        long gcdLcmC = lcmAb;
        long tempC = c;
        while (tempC != 0) {
            long t = tempC;
            tempC = gcdLcmC % tempC;
            gcdLcmC = t;
        }
        System.out.println((lcmAb * c) / gcdLcmC);
    }
}
