Here is a simple Python solution using dictionary to store the songs and their corresponding artist names. The function `get_songs_by_artist` retrieves all songs performed by a given artist.

def get_songs_by_artist(songs, artist):
    return [song for song, artist_in_song in songs.items() if artist_in_song == artist]

def main():
    songs = {
        'song1': 'artist1',
        'song2': 'artist2',
        'song3': 'artist3',
        'song4': 'artist1',
        'song5': 'artist2'
    }

    artist = input("Enter the artist name: ")

    matching_songs = get_songs_by_artist(songs, artist)

    print("Songs performed by the artist:", artist)
    for song in matching_songs:
        print(song)

if __name__ == "__main__":
    main()

In this code, we create a dictionary where the keys are the song names and the values are the artist names. Then we ask the user for an artist name. After that, we call the `get_songs_by_artist` function with our song data and the user's input. The function returns a list of songs that match the artist input. Finally, we print out these matching songs.