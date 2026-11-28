import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        int lcm = findLCM(a, findLCM(b, c));
        System.out.println(lcm);
    }

    private static int findLCM(int a, int b) {
        int max, step, lcm = 0;

        if(a > b) {
            max = a;
            step = b;
        } else {
            max = b;
            step = a;
       }

        for(int i = 1; i <= step; i++) {
            if((max * i) % step == 0) {
                lcm = max * i;
                break;
            }
        }

        return lcm;
    }
}
