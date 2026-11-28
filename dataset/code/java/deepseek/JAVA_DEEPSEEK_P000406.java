import java.util.*;

public class Main {
    public static class Movie {
        String title;
        String genre;

        public Movie(String title, String genre) {
            this.title = title;
            this.genre = genre;
        }

        public String getTitle() {
            return title;
        }

        public String getGenre() {
            return genre;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<Movie> movies = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String title = scanner.nextLine();
            String genre = scanner.nextLine();
            movies.add(new Movie(title, genre));
        }

        String targetGenre = scanner.nextLine();

        for (Movie movie : movies) {
            if (movie.getGenre().equals(targetGenre)) {
                System.out.println(movie.getTitle());
            }
       }
    }
}
