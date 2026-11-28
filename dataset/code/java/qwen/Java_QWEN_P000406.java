import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> movies = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String title = sc.next();
            String genre = sc.next();
            movies.add(new String[]{title, genre});
        }
        String searchGenre = sc.next();
        for(String[] m : movies) {
            if(m[1].equals(searchGenre)) System.out.println(m[0]);
        }
    }
}
