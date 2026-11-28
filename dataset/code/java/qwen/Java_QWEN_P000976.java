import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x1 = sc.nextDouble();
        double y1 = sc.nextDouble();
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();
        double x3 = sc.nextDouble();
        double y3 = sc.nextDouble();
        
        double area = Math.abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0;
        System.out.printf("%.6f
", area);
    }
}
