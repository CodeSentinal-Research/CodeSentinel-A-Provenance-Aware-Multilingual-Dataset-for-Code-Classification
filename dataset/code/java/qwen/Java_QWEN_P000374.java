import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String isbn = sc.next();
            String title = sc.next();
            map.put(isbn, title);
        }
        String searchIsbn = sc.next();
        if(map.containsKey(searchIsbn)) System.out.println(map.get(searchIsbn));
        else System.out.println("Book Not Found");
    }
}
