import java.io.*;
import java.util.*;

public class Main {
    static class Song {
        String title;
        String artist;

        Song(String title, String artist) {
            this.title = title;
            this.artist = artist;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Song> songs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] data = br.readLine().split(",");
            songs.add(new Song(data[0], data[1]));
        }
        String artist = br.readLine();
        for (Song song : songs) {
            if (song.artist.equals(artist)) {
                System.out.println(song.title);
            }
        }
    }
}
