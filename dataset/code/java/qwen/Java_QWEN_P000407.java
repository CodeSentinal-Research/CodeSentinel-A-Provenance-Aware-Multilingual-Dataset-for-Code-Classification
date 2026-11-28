import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String[]> songs = new ArrayList<>();
        for(int i=0; i<n; i++) {
            String title = sc.next();
            String artist = sc.next();
            songs.add(new String[]{title, artist});
        }
        String searchArtist = sc.next();
        for(String[] s : songs) {
            if(s[1].equals(searchArtist)) System.out.println(s[0]);
        }
    }
}
