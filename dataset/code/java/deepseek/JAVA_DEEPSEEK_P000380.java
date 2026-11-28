import java.io.*;
import java.util.*;

public class Main {
    static class Hotel {
        int id;
        String name;
        String address;

        Hotel(int id, String name, String address) {
            this.id = id;
            this.name = name;
            this.address = address;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Hotel> hotels = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] data = br.readLine().split(" ");
            int id = Integer.parseInt(data[0]);
            String name = data[1];
            String address = data[2];
            hotels.add(new Hotel(id, name, address));
        }
        int searchId = Integer.parseInt(br.readLine());
        boolean found = false;
        for (Hotel hotel : hotels) {
            if (hotel.id == searchId) {
                System.out.println(hotel.id + " " + hotel.name + " " + hotel.address);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Hotel Not Found");
        }
    }
}
