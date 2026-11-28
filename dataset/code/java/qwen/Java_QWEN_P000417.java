import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> books = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String title = sc.next();
            String author = sc.next();
            String genre = sc.next();
            books.add(new String[]{title, author, genre});
        }
        String author = sc.next();
        String genre = sc.next();
        for(String[] b : books) {
            if(b[1].equals(author) && b[2].equals(genre)) System.out.println(b[0]);
        }
    }
}
