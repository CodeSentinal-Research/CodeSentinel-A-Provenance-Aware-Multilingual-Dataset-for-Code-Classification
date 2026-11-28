import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Doctors {
    public static Scanner input = new Scanner(System.in);
    public static void displayDoctorInfo() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("DoctorList.txt"));
            String line;
            while ((line = reader.readLine()) != null) {
                String[] a = line.split("\\s+");
                System.out.println(" Name: " + a[2] + " ID: " + a[3]);

            }
            reader.close();

        } catch (java.io.IOException ioe) {
            System.out.println("Exception Occurred while reading DoctorList.txt ");
        }
    }
    public static String doctorLogin(){
        String line;
        String[] parameters;
        String user;
        String password;
        
        System.out.print("Username: "); user = input.nextLine();
        System.out.print("Password: ");password = input.nextLine();
        try {
            BufferedReader reader = new BufferedReader(new FileReader("DoctorList.txt"));
            while((line = reader.readLine()) != null){
                parameters = line.split("\\s+");
                if(parameters[0].equals(user) && parameters[1].equals(password)){
                    System.out.println("Login Successful");
                    reader.close();
                    return parameters[4];
                }
            }
            reader.close(); 
            
        } catch (java.io.IOException ioe) {
            System.out.println("Exception Occurred");
        }
        return "Doctor Not Found";
    }
    public static void deleteDoctor(String fileName) {
        String fullPath = "doctors\\" + fileName;

        File patientFile = new File(fullPath);
        boolean deleted = patientFile.delete();

        if (!deleted) {
            System.out.println("Could Not Delete File: " + fullPath);
            return;
        }
        System.out.println("Doctor File Deleted Successfully");

        try {
            File inputFile = new File("DoctorList.txt");
            File tempFile = new File("DoctorList_temp.txt");

            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("\\s+");

                if (parts.length >= 5 && parts[4].equals(fileName)) {
                    writer.write("[Deleted Record]");
                } else {
                    writer.write(line);
                }
                writer.newLine();
            }
            reader.close();
            writer.close();
            inputFile.delete();
            tempFile.renameTo(inputFile);
            System.out.println("Doctor List Updated With Deleted Record");
        } catch (Exception e) {
            System.out.println("Error Updating 'DoctorList.txt' During Delete");
        }
    }
    public static void updateDoctorList(String oldFileName, String[] updatedLines) {
    try {
        File inputFile = new File("DoctorList.txt");
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));

        File tempFile = new File("DoctorList_temp.txt");
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split("\\s+");
            if (parts[4].equals(oldFileName)) {
                
                parts[0] = updatedLines[0];
                parts[1] = updatedLines[1];
                parts[2] = updatedLines[2];
                parts[3] = updatedLines[3];
                parts[4] = "Doctor-" + updatedLines[3] + ".txt";
            }

            writer.write(String.join(" ", parts));
            writer.newLine();
        }
        reader.close();
        writer.close();
        inputFile.delete();
        tempFile.renameTo(inputFile);
    } catch (Exception e) {
        System.out.println("Error Updating 'DoctorList.txt'");
    }
}
    public static void editDoctorDataMenu(String FileName) {

    String fullPath = "doctors\\" + FileName;
    String[] lines = new String[9];
    int j;

    String name = FileName.substring(0, 12);

    while (true) {
        System.out.println("===============================================");
        System.out.println("||         Edit " + name + " Data            ||");
        System.out.println("===============================================");
        System.out.println("|| 1: Edit Doctor Username                   ||");
        System.out.println("|| 2: Edit Doctor Password                   ||");
        System.out.println("|| 3: Edit Doctor Name                       ||");
        System.out.println("|| 4: Edit Date Of Birth                     ||");
        System.out.println("|| 5: Edit Gender                            ||");
        System.out.println("|| 6: Edit Pay                               ||");
        System.out.println("|| 7: Edit Office Number                     ||");
        System.out.println("|| 8: Edit Specialization                    ||");
        System.out.println("===============================================");
        System.out.print("Choice: ");
        int choice = input.nextInt();
        input.nextLine();

        switch (choice) {
            case 1: j = 0; break;
            case 2: j = 1; break;
            case 3: j = 2; break;
            case 4: j = 4; break;
            case 5: j = 6; break;
            case 6: j = 7; break;
            case 7: j = 8; break;
            case 8: j = 5; break;
            default: System.out.println("Enter Valid Choice"); continue;
        }
        break;
    }

    try {
        BufferedReader reader = new BufferedReader(new FileReader(fullPath));
        for (int i = 0; i < lines.length; i++) {
            lines[i] = reader.readLine();
        }
        reader.close();
    } catch (IOException e) {
        System.out.println("Error Reading " + FileName);
        return;
    }

    System.out.print("Enter Edited Data: ");
    lines[j] = input.nextLine();

    try {
        BufferedWriter writer = new BufferedWriter(new FileWriter(fullPath));
        for (int i = 0; i < lines.length; i++) {
            writer.write(lines[i]);
            writer.newLine();
        }

        writer.close();
    } catch (IOException e) {
        System.out.println("Error Writing " + FileName);
    }
    updateDoctorList(FileName, lines);
    System.out.println("===============================================");
    System.out.println("        Edited Doctor Data Successfully        ");
    System.out.println("===============================================");
}
    public static void displayDoctorData(String FileName){
        String line;
        String name = FileName.substring(0,11);
        System.out.println("===============================================");
        System.out.println("||         " + name + " Data                  ||" );
        System.out.println("===============================================");
        try{
            BufferedReader reader = new BufferedReader(new FileReader("doctors\\" + FileName));
            for(int i = 1; (line = reader.readLine()) != null; i++){
                switch (i) {
                    case 1:
                        System.out.println("|| Username          : " + line);
                        break;
                    case 2:
                        System.out.println("|| Password          : " + line);
                        break;
                    case 3:
                        System.out.println("|| Name              : " + line);
                        break;
                    case 4:
                        System.out.println("|| Doctor  ID        : " + line);
                        break;
                    case 5:
                        System.out.println("|| Date Of Birth     : " + line);
                        break;
                    case 6:
                        System.out.println("|| Specialization    : " + line);
                        break;
                    case 7:
                        System.out.println("|| Gender            : " + line);
                        break;
                    case 8:
                        System.out.println("|| Pay               : " + line);
                        break;
                    case 9:
                        System.out.println("|| Office Number     : " + line);
                        break;
                    default:
                        break;
                }
            }
            System.out.println("===============================================");
            reader.close();
        }catch(java.io.IOException ioe){
            System.out.println("Exception Occured During Reading File: " + FileName);
        }
    }
    public static void doctorEntryMenu(){
        int exit;
        while(true){
            System.out.println("=============================================");
            System.out.println("||           Doctor Entry Menu             ||");
            System.out.println("=============================================");
            addDoctorList();
            while(true){
                try{
                    System.out.print(" Enter 0 To Exit Entry Menu: "); exit = input.nextInt();
                    break;
                }
                catch(Exception e){
                    System.out.println(" Enter Valid Integer");
                    input.next();
                    continue;
                }
            }
            input.nextLine();
            if(exit == 0){
                break;
            }else{
                continue;
            }
        }
    }
    public static String searchDoctorMenu(){
        String line;
        String[] parameters;
        int i;
        String search;

        while (true){
            System.out.println(" Search By:");
            System.out.print(" (1: Username | 2: Name | 3: Doctor ID): "); int choice = input.nextInt();
            input.nextLine();
            switch (choice) {
                case 1:
                    i = 0;
                    break;
                case 2:
                    i = 2;
                    break;
                case 3:
                    i = 3;
                    break;
                default:
                    continue;
            }
            break;
        }
        System.out.print("  Search: ");search = input.nextLine();
        try {
            BufferedReader reader = new BufferedReader(new FileReader("DoctorList.txt"));
            while((line = reader.readLine()) != null){
                parameters = line.split("\\s+");
                if(parameters[0].equals("[Deleted")){continue;}
                if(parameters[i].equals(search)){
                    System.out.println("Doctor Found");
                    reader.close();
                    return parameters[4];
                }
            }
            reader.close();
        } catch (java.io.IOException ioe) {
            System.out.println("Exception Occurred");
        }
        return "Doctor Not Found";
    }
    public static int checkDigits(int num){
        int count = 0;
        while(num != 0){
            count++;
            num =  num/10;
        }
        return count;
    }
    public static void createDoctorFile(String user, String pass, String name, String id){
        String FileName = "Doctor-" + id + ".txt";
        try {
            File patient = new File("doctors\\" + FileName);
            if(!patient.exists()){
                patient.createNewFile();
            }
            BufferedWriter writer = new BufferedWriter(new FileWriter("doctors\\" + FileName)); 
            System.out.print(" Enter Doctor DOB: "); String dob = input.nextLine();
            System.out.print(" Enter Specialization: "); String special = input.nextLine();
            System.out.print(" Enter Gender: "); String gender = input.nextLine();
            System.out.print(" Enter Pay: "); String pay = input.nextLine();
            System.out.print(" Enter Office Number: "); String offNum = input.nextLine();
            writer.write(user + "\n");
            writer.write(pass + "\n");
            writer.write(name + "\n");
            writer.write(id + "\n");
            writer.write(dob + "\n");
            writer.write(special + "\n");
            writer.write(gender + "\n");
            writer.write(pay + "\n");
            writer.write(offNum + "\n");
            writer.close();
        } catch (Exception e) {
            System.out.println("Exception Occurred During File Handling | File Name: " + FileName);
            return;
        }
    }
    public static void createDoctorListFile (){
        File patients = new File("DoctorList.txt");
        int exit;
        while(true){
            try{
                if(!patients.exists()){
                    patients.createNewFile();
                }else{
                    break;
                }
            }
            catch(java.io.IOException ioe){
                System.out.println("Exception Occured During 'DoctorList.txt' Creation");
                System.out.print("Do You Wish To Retry (1: Yes, 0: No): ");exit = input.nextInt();
                input.nextLine();
                if (exit == 1){
                    continue;
                }
                else if (exit == 0){
                    break;
                } else{
                    System.out.println("Invalid Input, Retrying Now");
                    continue;
                }
            }
        }
    }
    public static void addDoctorList(){
        try{
            BufferedReader reader = new BufferedReader(new FileReader("DoctorList.txt"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("DoctorList.txt", true));
            String line;
            String id;
            for(int i = 1; true; i++ ){
                if( (line = reader.readLine()) == null){
                    System.out.print(" Doctor Username: "); String user = input.nextLine();
                    System.out.print(" Doctor Password: "); String pass = input.nextLine();
                    System.out.print(" Doctor Name (Insert '_' Between Name): "); String name = input.nextLine();
                    id = Integer.toString(i);
                    for(int j = 4-checkDigits(i); j > 0; j--){
                        id = "0" + id; 
                    }
                    createDoctorFile(user, pass, name, id);
                    writer.write(user + " " + pass + " " + name + " " + id +" Doctor-" + id + ".txt"+ "\n");
                    break;
                }
            }
            
            System.out.println(" Doctor Data Entered Successfully");
            writer.close();
            reader.close();

        }
        catch(java.io.IOException ioe){
            System.out.println(" Exception Occured During Writing 'DoctorList.txt' ");
        }
    }
}