/*
 * Daniel Langer
 * 114662901
 */

import java.io.File;
import java.util.Scanner;

public class JavaToHTML {
    public static void main(String[] args) {
        Scanner inputStream = new Scanner(System.in);
        System.out.println("What is the name of the input file?");
        String filepath = inputStream.next();
        inputStream.close();
        File inputFile = new File(filepath);
        File outputFile = new File("output.txt");
        try {
            java.io.PrintWriter output = new java.io.PrintWriter(outputFile);
            Scanner input = new Scanner(inputFile);

            while (input.hasNext()) {
                String sentence = input.nextLine();
                output.println("old: " + sentence);
                output.write("new: ");
                for (int i = 0; i < sentence.length(); i++) {
                    if (sentence.toLowerCase().charAt(i) == 'j' && sentence.toLowerCase().charAt(i + 1) == 'a'
                            && sentence.toLowerCase().charAt(i + 2) == 'v'
                            && sentence.toLowerCase().charAt(i + 3) == 'a') {
                        i += 3;
                        output.write("HTML");
                    } else {
                        output.write(sentence.charAt(i));
                    }
                }
                output.write("\n");
            }
            input.close();
            output.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}