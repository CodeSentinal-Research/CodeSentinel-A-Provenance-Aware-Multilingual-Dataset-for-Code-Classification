import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> students = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            double gpa = sc.nextDouble();
            students.add(new String[]{name, String.valueOf(gpa)});
        }
        double threshold = sc.nextDouble();
        for(String[] s : students) {
            if(Double.parseDouble(s[1]) >= threshold) System.out.println(s[0]);
        }
    }
}
