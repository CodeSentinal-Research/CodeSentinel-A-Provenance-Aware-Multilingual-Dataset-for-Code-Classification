import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int units = sc.nextInt();
        double bill = 0;
        if (units <= 100) bill = units * 10;
        else if (units <= 200) bill = 1000 + (units - 100) * 15;
        else if (units <= 300) bill = 2500 + (units - 200) * 20;
        else bill = 4500 + (units - 300) * 25;
        System.out.println(bill);
    }
}
