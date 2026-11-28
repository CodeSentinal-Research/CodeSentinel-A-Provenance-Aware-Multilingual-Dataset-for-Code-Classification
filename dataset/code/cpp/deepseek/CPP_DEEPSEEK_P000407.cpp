#include <iostream>
#include <vector>
#include <algorithm>

struct Song {
    std::string title;
    std::string artist;
};

bool artistSearch(std::vector<Song>& songs, std::string artist) {
    int count = 0;
    for (Song song : songs) {
        if (song.artist == artist) {
            count++;
        }
    }

    for (Song song : songs) {
        if (song.artist == artist) {
            std::cout << "Song: " << song.title << ", Artist: " << song.artist << std::endl;
        }
    }

    return count > 0;
}

int main() {
    std::vector<Song> songs = {
        {"Song1", "Artist1"},
        {"Song2", "Artist2"},
        {"Song3", "Artist1"},
        {"Song4", "Artist3"},
        {"Song5", "Artist1"},
        {"Song6", "Artist4"},
    };

    std::string artist;
    std::cout << "Enter artist name: ";
    std::cin >> artist;

    if (artistSearch(songs, artist)) {
        std::cout << "Found songs for artist." << std::endl;
    } else {
        std::cout << "No songs found for artist." << std::endl;
    }

    return 0;
}