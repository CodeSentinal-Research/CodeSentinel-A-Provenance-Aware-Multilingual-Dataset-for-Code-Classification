Here is a basic solution using Python's built-in datatypes and functions. This program reads movie records and genres from a file, and then searches for movies in a given genre.

def read_movies(file_name):
    movies = {}
    with open(file_name, 'r') as file:
        for line in file:
            movie, genre = line.strip().split(':')
            if genre in movies:
                movies[genre].append(movie)
            else:
                movies[genre] = [movie]
    return movies

def search_genre(genre, movies):
    if genre in movies:
        print('Movies in the {} genre:'.format(genre))
        for movie in movies[genre]:
            print(movie)
    else:
        print('No movies found in the {} genre.'.format(genre))

def main():
    movies = read_movies('movies.txt')
    while True:
        genre = input('Enter a genre to search (or "q" to quit): ')
        if genre.lower() == 'q':
            break
        search_genre(genre, movies)

if __name__ == '__main__':
    main()

In this code, `read_movies` function reads movie records and genres from a file named `movies.txt`. Each line in the file is read as a string and then split into a movie name and a genre. The genre and movie are then added to a dictionary, keyed by genre.

The `search_genre` function searches for movies in a given genre and prints them. If the genre is not found in the dictionary, it prints a message indicating this.

The `main` function runs in a loop, reading input from the user. If the user enters 'q', it breaks out of the loop and ends the program. Otherwise, it calls `search_genre` with the user's input.