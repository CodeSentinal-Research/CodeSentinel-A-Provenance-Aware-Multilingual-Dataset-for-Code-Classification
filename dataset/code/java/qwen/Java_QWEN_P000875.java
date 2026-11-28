import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        
        int flips = 0;
        for(int i=0; i<32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            
            int desired = bitA | bitB;
            if(desired != bitC) {
                if(bitC == 1) flips++;
                else {
                    if(bitA == 1 && bitB == 1) flips += 2;
                    else flips++;
                }
            }
        }
        System.out.println(flips);
    }
}
