import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int year = scanner.nextInt();
        scanner.nextLine();

        List<String> books = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            books.add(scanner.nextLine());
        }

        boolean found = false;
        for (String book : books) {
            String[] parts = book.split(":");
            if (Integer.parseInt(parts[1]) > year) {
                System.out.println(book);
                found = true;
           }
        }

        if (!found) {
            System.out.println("No book found");
        }
    }
}
