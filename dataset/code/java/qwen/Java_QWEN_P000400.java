import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> employees = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            double salary = sc.nextDouble();
            employees.add(new String[]{name, String.valueOf(salary)});
        }
        double minSal = sc.nextDouble();
        double maxSal = sc.nextDouble();
        for(String[] e : employees) {
            double sal = Double.parseDouble(e[1]);
            if(sal >= minSal && sal <= maxSal) System.out.println(e[0]);
        }
    }
}
