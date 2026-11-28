import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> students = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            double cgpa = sc.nextDouble();
            double income = sc.nextDouble();
            students.add(new String[]{name, String.valueOf(cgpa), String.valueOf(income)});
        }
        double minCgpa = sc.nextDouble();
        double maxIncome = sc.nextDouble();
        for(String[] s : students) {
            if(Double.parseDouble(s[1]) >= minCgpa && Double.parseDouble(s[2]) <= maxIncome)
                System.out.println(s[0]);
        }
    }
}
