import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> courses = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String title = sc.next();
            String instructor = sc.next();
            courses.add(new String[]{title, instructor});
        }
        String searchInstructor = sc.next();
        for(String[] c : courses) {
            if(c[1].equals(searchInstructor)) System.out.println(c[0]);
        }
    }
}
