import javax.sound.sampled.*;
import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.net.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Random;

public class ServerGUI1 extends JFrame {
    private JTextArea logArea;
    private static final String DB_URL = "jdbc:mysql://localhost:3306/varun";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "varun03";
    private Connection connection;
    public ServerGUI1() {
        setTitle("Server");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600); // Set initial size to 800x600
        setLocationRelativeTo(null); // Center the JFrame on the screen
        logArea = new JTextArea();
        logArea.setEditable(false);
        logArea.setFont(new Font("Arial", Font.PLAIN, 18)); // Set font size for logArea
        JScrollPane scrollPane = new JScrollPane(logArea);
        scrollPane.setPreferredSize(new Dimension(700, 500)); // Set preferred size for scrollPane
        add(scrollPane);
        setVisible(true);
        try {
            // Establish connection to the database
            connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
            logArea.append("Connected to the database\n");
        } catch (SQLException e) {
            logArea.append("Failed to connect to the database\n");
            e.printStackTrace();
        }
        startServer();
    }
    private void startServer() {
        try (ServerSocket serverSocket = new ServerSocket(7778)) {
            logArea.append("Server started....\n");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                logArea.append("Client connected: " + clientSocket.getInetAddress() + "\n");
                handleClient(clientSocket);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private void handleClient(Socket clientSocket) {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
             PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {
            // Request name, email, phone number, car number
            String name = getInput("Enter your name:");
            while (!isValidName(name)) {
                name = getInput("Invalid name format.\nPlease enter your name (only alphabetic characters):");
            }
            String email = getEmail();
            String phoneNumber = getPhoneNumber();
            String carNumber = getCarNumber();
            // Initialize score
            int score = 0;
            // Question 1: Random number
            int generatedNumber1 = new Random().nextInt(100);
            int answer1 = Integer.parseInt(JOptionPane.showInputDialog(this, "Question 1: Guess the number (0-99): " + generatedNumber1));
            if (answer1 == generatedNumber1) {
                JOptionPane.showMessageDialog(this, "Correct!");
                score += 20;
            } else {
                playSound(); // Play the custom sound
                JOptionPane.showMessageDialog(this, "Incorrect.");
            }
            // Question 2: Simple addition
            int num1 = new Random().nextInt(50);
            int num2 = new Random().nextInt(50);
            int answer2 = Integer.parseInt(JOptionPane.showInputDialog(this, "Question 2: What is " + num1 + " + " + num2 + "?"));
            if (answer2 == num1 + num2) {
                JOptionPane.showMessageDialog(this, "Correct!");
                score += 20;
            } else {
                playSound(); // Play the custom sound
                JOptionPane.showMessageDialog(this, "Incorrect.");
            }
            // Question 3: Odd or Even
            int generatedNumber3 = new Random().nextInt(100);
            String answer3 = JOptionPane.showInputDialog(this, "Question 3: Is " + generatedNumber3 + " odd or even? (Enter 'odd' or 'even')");
            if ((generatedNumber3 % 2 == 0 && answer3.equalsIgnoreCase("even")) ||
                    (generatedNumber3 % 2 != 0 && answer3.equalsIgnoreCase("odd"))) {
                JOptionPane.showMessageDialog(this, "Correct!");
                score += 20;
            } else {
                playSound(); // Play the custom sound
                JOptionPane.showMessageDialog(this, "Incorrect.");
            }
            // Question 4: Random string
            String generatedString = generateRandomString(6);
            String answer4 = JOptionPane.showInputDialog(this, "Question 4: Enter the following string: " + generatedString);
            if (answer4.equals(generatedString)) {
                JOptionPane.showMessageDialog(this, "Correct!");
                score += 20;
            } else {
                playSound(); // Play the custom sound
                JOptionPane.showMessageDialog(this, "Incorrect.");
            }
            // Question 5: Color identification
            String color = getRandomColor();
            JOptionPane.showMessageDialog(this, "Question 5: Identify the color :");
            JPanel colorPanel = new JPanel();
            colorPanel.setBackground(getColorFromString(color));
            colorPanel.setMaximumSize(new Dimension(50, 50));
            colorPanel.setPreferredSize(new Dimension(50, 50));
            JOptionPane.showMessageDialog(this, colorPanel, "", JOptionPane.PLAIN_MESSAGE);
            String answer5 = JOptionPane.showInputDialog(this, "Enter the color:");
            if (answer5 != null && answer5.equalsIgnoreCase(color)) {
                JOptionPane.showMessageDialog(this, "Correct!");
                score += 20;
            } else {
                playSound(); // Play the custom sound
                JOptionPane.showMessageDialog(this, "Incorrect.");
            }
            // Determine if driver can drive
            String response;
            if (score >= 100) {
                response = "You may proceed.\tYou are fit to drive.";
                JOptionPane.showMessageDialog(this, "Your score: " + score + "%. " + response);
            } else if (score >= 80) {
                response = "You may proceed with caution. You have one reattempt chance.";
                // Generate random numbers for additional question
                Random random = new Random();
                int additionalNum1 = random.nextInt(10);
                int additionalNum2 = random.nextInt(10);
                int correctAnswer = additionalNum1 + additionalNum2;
                int additionalAnswer = Integer.parseInt(JOptionPane.showInputDialog(this, "Additional Question: What is " + additionalNum1 + " + " + additionalNum2 + "?"));
                if (additionalAnswer == correctAnswer) {
                    JOptionPane.showMessageDialog(this, "Correct!");
                    score += 20;
                    JOptionPane.showMessageDialog(this, "Your score: " + score + "%.\tyou can ride the car");
                } else {
                    playCustomSound(); // Play the custom sound
                    JOptionPane.showMessageDialog(this, "Incorrect.");
                    response = " You cannot ride the car Police has noted your car number: " + carNumber;
                    JOptionPane.showMessageDialog(this, "Your score: " + score + "%. " + response);
                    // Send the message to the client
                    out.println("Car number " + carNumber + " is drunken.\nYou cannot ride your car number is been noted by police");
                }
            } else {
                response = "You are not fit to drive.\tSending message to the police station.";
                playCustomSound(); // Play the custom sound
                JOptionPane.showMessageDialog(this, "Your score: " + score + "%. " + response + "\nYour car number is been noted" + carNumber);
            }
            // Insert data into database
            insertData(name, email, phoneNumber, carNumber, score);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private static String generateRandomString(int length) {
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        StringBuilder sb = new StringBuilder(length);
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            sb.append(characters.charAt(random.nextInt(characters.length())));
        }
        return sb.toString();
    }
    private static String getRandomColor() {
        String[] colors = {"red", "green", "blue", "yellow", "orange", "purple", "pink", "brown", "black", "white"};
        Random random = new Random();
        return colors[random.nextInt(colors.length)];
    }
    private Color getColorFromString(String colorName) {
        switch (colorName.toLowerCase()) {
            case "red":
                return Color.RED;
            case "green":
                return Color.GREEN;
            case "blue":
                return Color.BLUE;
            case "yellow":
                return Color.YELLOW;
            case "orange":
                return Color.ORANGE;
            case "purple":
                return new Color(128, 0, 128); // Purple
            case "pink":
                return Color.PINK;
            case "brown":
                return new Color(139, 69, 19); // Brown
            case "black":
                return Color.BLACK;
            case "white":
                return Color.WHITE;
            default:
                return Color.BLACK;
        }
    }
    private boolean isValidName(String name) {
        if (name == null || name.isEmpty()) {
            return false;
        }
        return name.matches("[a-zA-Z]+");
    }
    private String getEmail() {
        while (true) {
            String email = JOptionPane.showInputDialog(this, "Enter your email:");
            if (isValidEmail(email)) {
                return email;
            } else {
                JOptionPane.showMessageDialog(this, "Invalid email format.\nPlease enter a valid email address (e.g., example@gmail.com)");
            }
        }
    }
    private boolean isValidEmail(String email) {
        if (email == null) {
            return false;
        }
        return email.matches("^\\w+@[a-zA-Z_]+?\\.[a-zA-Z]{2,3}$");
    }
    private String getPhoneNumber() {
        while (true) {
            String phoneNumber = JOptionPane.showInputDialog(this, "Enter your phone number:");
            if (isValidPhoneNumber(phoneNumber)) {
                return phoneNumber;
            } else {
                JOptionPane.showMessageDialog(this, "Invalid phone number format.\nPlease enter a 10-digit phone number (e.g., 1234567890)");
            }
        }
    }
    private boolean isValidPhoneNumber(String phoneNumber) {
        if (phoneNumber == null) {
            return false;
        }
        return phoneNumber.matches("^\\d{10}$");
    }
    private String getCarNumber() {
        while (true) {
            String carNumber = JOptionPane.showInputDialog(this, "Enter your car number (Format: XX1234):");
            if (isValidCarNumber(carNumber)) {
                return carNumber;
            } else {
                JOptionPane.showMessageDialog(this, "Invalid car number format.\nPlease enter a valid car number (e.g., AB1234)");
            }
        }
    }
    private boolean isValidCarNumber(String carNumber) {
        if (carNumber == null) {
            return false;
        }
        return carNumber.matches("^[A-Z]{2}\\d{4}$");
    }
    private void playSound() {
        try {
            File soundFile = new File("C:\\Users\\varun\\OneDrive\\Desktop\\sound\\mixkit-electric-fence-alert-2969.wav");
            AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(soundFile);
            Clip clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.start();
        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException e) {
            e.printStackTrace();
        }
    }
    private void playCustomSound() {
        try {
            File soundFile = new File("C:\\Users\\varun\\OneDrive\\Desktop\\sound\\mixkit-emergency-car-arrival-1655.wav");
            AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(soundFile);
            Clip clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.start();
        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException e) {
            e.printStackTrace();
        }
    }
    private String getInput(String message) {
        JTextArea textArea = new JTextArea();
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setFont(new Font("Arial", Font.PLAIN, 18));
        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setPreferredSize(new Dimension(300, 150));
        JOptionPane.showMessageDialog(this, scrollPane, message, JOptionPane.PLAIN_MESSAGE);
        return textArea.getText();
    }
    private void insertData(String name, String email, String phoneNumber, String carNumber, int score) {
        try {
            // Prepare SQL statement
            String sql = "INSERT INTO driver (name, email, phone_number, car_number, score) VALUES (?, ?, ?, ?, ?)";
            PreparedStatement statement = connection.prepareStatement(sql);
            // Set parameters
            statement.setString(1, name);
            statement.setString(2, email);
            statement.setString(3, phoneNumber);
            statement.setString(4, carNumber);
            statement.setInt(5, score);
            // Execute the query
            statement.executeUpdate();
            logArea.append("Data inserted into the database\n");
        } catch (SQLException e) {
            logArea.append("Failed to insert data into the database\n");
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        try {
            // Set look and feel to Nimbus
            UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
            // Customize UIManager
            UIManager.put("OptionPane.background", new Color(119, 136, 153)); // Set background color to LightSlateGray
            UIManager.put("OptionPane.messageForeground", Color.WHITE); // Set text color of JOptionPane
            UIManager.put("OptionPane.messageFont", new Font("Arial", Font.BOLD, 18)); // Set font size of JOptionPane
            UIManager.put("OptionPane.buttonBackground", new Color(30, 30, 30)); // Set background color of buttons
            UIManager.put("OptionPane.buttonForeground", Color.WHITE); // Set text color of buttons
            UIManager.put("Panel.background", new Color(119, 136, 153)); // Set background color to LightSlateGray
            UIManager.put("TextField.background", new Color(40, 40, 40)); // Set background color of text fields
            UIManager.put("TextField.foreground", Color.WHITE); // Set text color of text fields
            UIManager.put("TextField.font", new Font("Arial", Font.PLAIN, 14)); // Set font size of text fields
        } catch (Exception e) {
            e.printStackTrace();
        }
        new ServerGUI1();
}
}
