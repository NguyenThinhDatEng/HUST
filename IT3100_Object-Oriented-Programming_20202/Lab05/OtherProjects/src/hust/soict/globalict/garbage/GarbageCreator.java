package hust.soict.globalict.garbage;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.Scanner;
import java.util.logging.Logger;

public class GarbageCreator {
    public static void main(String[] args) throws IOException {
        String str = "";
        FileInputStream file = new FileInputStream("D:\\00.txt");
        Scanner scanner = new Scanner(file);
        try {
            while (scanner.hasNextLine()) {
                str += scanner.nextLine() + "\n";
            }
        } finally {
            try {
                scanner.close();
                file.close();
            } catch (IOException ex) {
                //ex.printStackTrace();
            	Logger.getLogger(GarbageCreator.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println(str);
        FileOutputStream file01 = new FileOutputStream("D:\\0.2.txt");
        file01.write(str.getBytes());
        file01.close();
    }
}
