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
        
        double d12 = dist(x1, y1, x2, y2);
        double d23 = dist(x2, y2, x3, y3);
        double d13 = dist(x1, y1, x3, y3);
        
        if(Math.abs(d12-d23)<1e-9 && Math.abs(d23-d13)<1e-9) System.out.println("Equilateral");
        else if(Math.abs(d12-d23)<1e-9 || Math.abs(d23-d13)<1e-9 || Math.abs(d12-d13)<1e-9) System.out.println("Isosceles");
        else System.out.println("Scalene");
    }
    static double dist(double x1, double y1, double x2, double y2) {
        return Math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }
}
