import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> books = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String title = sc.next();
            int year = sc.nextInt();
            books.add(new String[]{title, String.valueOf(year)});
        }
        int yearThreshold = sc.nextInt();
        for(String[] b : books) {
            if(Integer.parseInt(b[1]) > yearThreshold) System.out.println(b[0]);
        }
    }
}
