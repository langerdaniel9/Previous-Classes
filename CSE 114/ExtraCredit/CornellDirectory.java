/*
 * Daniel Langer
 * 114662901
 */

import java.io.IOException;
import java.net.URL;
import java.util.Scanner;

public class CornellDirectory {
    public static void main(String[] args) throws IOException {
        // Get the name to search for
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a name (can be first, last, or both)");
        String name = input.nextLine();
        input.close();

        // Replace spaces with '+' to not cause errors
        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) == ' ') {
                String firstSub = name.substring(0, i);
                String secondSub = name.substring(i + 1);
                name = firstSub + "+" + secondSub;
            }
        }

        // Get website name, load it, and read all information from it
        URL site = new URL("https://www.cornell.edu/search/people.cfm?q=" + name + "&tab=people");
        Scanner webScanner = new Scanner(site.openStream());
        StringBuffer sb = new StringBuffer();
        while (webScanner.hasNext()) {
            sb.append(webScanner.next());
        }
        String result = sb.toString();

        // Remove html tags
        result = result.replaceAll("<[^>]*>", "");

        // Find the important part (results)
        String results = result.substring(result.indexOf("Jumpto:") + 7,
                result.indexOf(".", result.indexOf("Jumpto:")) + 5);

        // Format it to look nice (aka add spaces since they were previously deleted)
        for (int i = 0; i < results.length(); i++) {
            if (results.charAt(i) == ',') {
                String firstSub = results.substring(0, i);
                String secondSub = results.substring(i + 1);
                results = firstSub + ", " + secondSub;
            }
        }

        System.out.println(
                "\t--For some reason the last term doesnt load, and if there is only one result it skips the results page, which causes errors--\n");
        System.out.println("Number of results for the search:\n" + results);
    }
}
