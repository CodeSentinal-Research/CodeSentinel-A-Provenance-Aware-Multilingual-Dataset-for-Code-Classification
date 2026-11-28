import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            List<String> playlist = new ArrayList<>();
            int cur = 0;
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("addSong")) {
                    playlist.add(scanner.next());
                } else if (cmd.equals("removeSong")) {
                    String title = scanner.next();
                    int idx = playlist.indexOf(title);
                    if (idx != -1) {
                        playlist.remove(idx);
                        if (cur >= playlist.size()) cur = Math.max(0, playlist.size() - 1);
                    }
                } else if (cmd.equals("playNext")) {
                    if (!playlist.isEmpty()) {
                        cur = (cur + 1) % playlist.size();
                        System.out.println(playlist.get(cur));
                    }
                } else if (cmd.equals("playPrevious")) {
                    if (!playlist.isEmpty()) {
                        cur = (cur - 1 + playlist.size()) % playlist.size();
                        System.out.println(playlist.get(cur));
                    }
                } else if (cmd.equals("moveSong")) {
                    String title = scanner.next();
                    int pos = scanner.nextInt();
                    if (playlist.remove(title)) {
                        playlist.add(pos, title);
                    }
                } else if (cmd.equals("currentSong")) {
                    System.out.println(playlist.isEmpty() ? "" : playlist.get(cur));
                }
            }
        }
    }
}