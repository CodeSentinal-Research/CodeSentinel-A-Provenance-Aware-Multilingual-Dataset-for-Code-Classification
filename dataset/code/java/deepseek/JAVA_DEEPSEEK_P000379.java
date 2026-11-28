import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, String> trains = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            trains.put(input[0], input[1] + " " + input[2]);
        }
        String trainNumber = br.readLine();
        if (trains.containsKey(trainNumber)) {
            System.out.println(trains.get(trainNumber));
       } else {
            System.out.println("Train Not Found");
        }
    }
}
