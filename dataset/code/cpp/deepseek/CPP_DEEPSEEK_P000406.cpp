#include <iostream>
#include <vector>
#include <algorithm>

struct Movie {
    int id;
    std::string genre;
    std::string title;
    int year;
};

bool compare(const Movie &a, const Movie &b) {
    return a.genre < b.genre;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Movie> movies(n);

    for (int i = 0; i < n; i++) {
        Movie movie;
        std::cin >> movie.id >> movie.genre >> movie.title >> movie.year;
        movies[i] = movie;
    }

    std::string genre;
    std::cin >> genre;

    std::vector<Movie> matchedMovies;

    std::sort(movies.begin(), movies.end(), compare);

    for (const Movie &movie : movies) {
        if (movie.genre == genre) {
            matchedMovies.push_back(movie);
        }
    }

    for (const Movie &movie : matchedMovies) {
        std::cout << movie.title << " (" << movie.year << ")\n";
    }

    return 0;
}