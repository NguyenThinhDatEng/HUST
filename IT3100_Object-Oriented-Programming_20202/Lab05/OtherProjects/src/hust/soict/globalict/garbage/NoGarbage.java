package hust.soict.globalict.garbage;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class NoGarbage {
	public static void main(String[] args) throws IOException {
        StringBuffer stringBuffer = new StringBuffer();
        FileInputStream url = new FileInputStream("D:\\01.txt");
        Scanner scanner = new Scanner(url);
        try {
            while (scanner.hasNextLine()) {
                stringBuffer.append(scanner.nextLine() + "\n");
            }
        } finally {
            try {
                scanner.close();
                url.close();
            } catch (IOException ex) {
                //ex.printStackTrace();
            	Logger.getLogger(GarbageCreator.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println(stringBuffer.toString());
		
		 FileOutputStream file00 = new FileOutputStream("D:\\0.3.txt");
		 file00.write(stringBuffer.toString().getBytes()); 
		 file00.close();
    }
}
