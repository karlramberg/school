package q2;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 * FileEncoderDriver test the FileEncoder class
 * @author Karl Ramberg
 */
public class FileEncodeDriver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // test file encoding
        System.out.println("Enter a file path to encode: ");
        String path = scanner.nextLine();
        FileEncoder fileEncoder = new FileEncoder(new File(path));
        try {
            fileEncoder.encodeFile();
        } catch (IOException e) {
            System.out.println(path + " could not be encoded!");
            e.printStackTrace();
        }

        // test file decoding
        System.out.println("Enter a file path to decode: ");
        path = scanner.nextLine();
        fileEncoder.setFile(new File(path));
        try {
            fileEncoder.decodeFile();
        } catch (IOException e) {
            System.out.println(path + " could not be decoded!");
            e.printStackTrace();
        }
    }
}
