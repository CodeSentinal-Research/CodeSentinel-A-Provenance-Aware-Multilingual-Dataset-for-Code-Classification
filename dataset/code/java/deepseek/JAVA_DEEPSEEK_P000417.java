import java.io.*;
import java.util.*;

public class Main {
    static class Book {
        String title;
        String author;
        String genre;

        Book(String author, String title, String genre) {
            this.author = author;
            this.title = title;
            this.genre = genre;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Book> books = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] inputs = br.readLine().split(",");
            books.add(new Book(inputs[0], inputs[1], inputs[2]));
        }
        String author = br.readLine();
        String genre = br.readLine();
        for (Book book : books) {
            if (book.author.equals(author) && book.genre.equals(genre)) {
                System.out.println(book.title);
            }
        }
    }
}
