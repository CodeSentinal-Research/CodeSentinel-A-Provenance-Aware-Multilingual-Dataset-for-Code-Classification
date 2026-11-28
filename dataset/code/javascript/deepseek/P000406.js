Here's a simple solution using JavaScript:

function searchMoviesByGenre(movies, genre) {
  let genreMovies = movies.filter(movie => movie.genre === genre);
  return genreMovies;
}

// Usage
let movies = [
  { title: 'Movie 1', genre: 'Action' },
  { title: 'Movie 2', genre: 'Comedy' },
  { title: 'Movie 3', genre: 'Action' },
  { title: 'Movie 4', genre: 'Comedy' },
  { title: 'Movie 5', genre: 'Drama' },
  { title: 'Movie 6', genre: 'Action' },
  { title: 'Movie 7', genre: 'Drama' },
  { title: 'Movie 8', genre: 'Action' },
  { title: 'Movie 9', genre: 'Comedy' },
  { title: 'Movie 10', genre: 'Drama' },
];

console.log(searchMoviesByGenre(movies, 'Action')); // Outputs: [ { title: 'Movie 1', genre: 'Action' }, { title: 'Movie 3', genre: 'Action' }, { title: 'Movie 6', genre: 'Action' } ]
console.log(searchMoviesByGenre(movies, 'Comedy')); // Outputs: [ { title: 'Movie 2', genre: 'Comedy' }, { title: 'Movie 4', genre: 'Comedy' }, { title: 'Movie 8', genre: 'Comedy' } ]
console.log(searchMoviesByGenre(movies, 'Drama')); // Outputs: [ { title: 'Movie 5', genre: 'Drama' }, { title: 'Movie 7', genre: 'Drama' }, { title: 'Movie 9', genre: 'Drama' }, { title: 'Movie 10', genre: 'Drama' } ]

This function `searchMoviesByGenre` uses the `filter` method to create a new array of movies that match the provided genre. It takes as parameters the array of movies and the genre to search for.