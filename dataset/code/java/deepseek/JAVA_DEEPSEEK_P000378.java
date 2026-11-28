import java.io.*;
import java.util.*;

public class Main {
    static class Flight {
        String flightNumber;
        String departure;
        String arrival;
        String time;

        Flight(String flightNumber, String departure, String arrival, String time) {
            this.flightNumber = flightNumber;
            this.departure = departure;
            this.arrival = arrival;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Flight> flights = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            flights.add(new Flight(input[0], input[1], input[2], input[3]));
        }
        String flightNumberToFind = br.readLine();
        boolean found = false;
        for (Flight flight : flights) {
            if (flight.flightNumber.equals(flightNumberToFind)) {
                System.out.println(flight.flightNumber + " " + flight.departure + " " + flight.arrival + " " + flight.time);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Flight Not Found");
        }
    }
}
