Sure, here's a simple example of how you might implement this in JavaScript:

function searchSongsByArtist(songs, artist) {
    // Filter songs by artist
    let matchingSongs = songs.filter(song => song.artist === artist);

    // Return matching songs
    return matchingSongs;
}

// Example usage:
let songs = [
    { title: 'Song 1', artist: 'Artist 1' },
    { title: 'Song 2', artist: 'Artist 1' },
    { title: 'Song 3', artist: 'Artist 2' },
    { title: 'Song 4', artist: 'Artist 3' },
];

console.log(searchSongsByArtist(songs, 'Artist 1')); // [ { title: 'Song 1', artist: 'Artist 1' }, { title: 'Song 2', artist: 'Artist 1' } ]
console.log(searchSongsByArtist(songs, 'Artist 2')); // [ { title: 'Song 3', artist: 'Artist 2' } ]

This function filters the given array of songs by artist and returns a new array containing only the songs that match the provided artist. The filter function uses a callback function to check if each song's artist matches the given artist. If it does, the song is included in the new array.