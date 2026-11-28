import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        int N = Integer.parseInt(reader.readLine());
        Map<String, List<String>> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String[] paths = reader.readLine().split("\\s+");
            String content = paths[1];

            for (int j = 2; j < paths.length; j++) {
                content += " " + paths[j];
            }

            if (!map.containsKey(content)) {
                map.put(content, new ArrayList<>());
            }

            map.get(content).add(paths[0]);
        }

        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            if (entry.getValue().size() > 1) {
                for (String path : entry.getValue()) {
                    writer.println(path);
                }
            }
        }

        writer.flush();
    }
}
