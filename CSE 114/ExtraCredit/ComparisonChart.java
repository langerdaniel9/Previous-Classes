/*
 * Daniel Langer
 * 114662901
 */

import java.io.IOException;
import java.net.URL;
import java.util.Scanner;

public class ComparisonChart {
    public static void main(String[] args) throws IOException {
        // Get website name, load it, and read all information from it
        URL site = new URL("https://learn.eartheasy.com/guides/led-light-bulbs-comparison-charts/");
        Scanner webScanner = new Scanner(site.openStream());
        StringBuffer sb = new StringBuffer();
        while (webScanner.hasNext()) {
            sb.append(webScanner.next());
        }
        String result = sb.toString();
        // Isolate the table that we will be searching through
        result = result.substring(result.indexOf("tbody"), result.indexOf("/tbody"));

        // Remove <br/> that are a nuisance
        while (result.indexOf("<br/>") != -1) {
            String firstSub = result.substring(0, result.indexOf("<br/>"));
            String secondSub = result.substring(result.indexOf("<br/>") + 5);
            result = firstSub + secondSub;
        }
        // 2D array of strings that is essentially a copy of the table
        String[][] array = new String[10][4];
        int rowNum = 0;
        // Each row has the tag <tr> so i use that to see how many rows there are
        while (result.indexOf("<trclass=") != -1) {
            // This row that doesnt have 4 columns, so I just skip over it by deleting it
            // from 'result'
            if (rowNum == 8) {
                result = result.substring(132);
            }
            String row = result.substring(result.indexOf("<trclass=") + 14, result.indexOf("</tr>") - 5);
            int columnNum = 0;
            // Each column has a classname starting with column so i use that to see how
            // many rows there are
            while (row.indexOf("column") != -1) {
                String column = "";
                // The last row doesnt have a closing tag (I deleted it already), so has
                // different behavior
                if (columnNum == 3) {
                    column = row.substring(row.indexOf("column-") + 10);
                    array[rowNum][columnNum] = column;
                    row = row.substring(row.indexOf("</td>") + 5);
                    columnNum++;
                    break;
                } else {
                    column = row.substring(row.indexOf("column-") + 10, row.indexOf("</td>"));
                }
                array[rowNum][columnNum] = column;
                row = row.substring(row.indexOf("</td>") + 5);
                columnNum++;
            }
            result = result.substring(result.indexOf("</tr>") + 5);
            rowNum++;
        }

        // Find what string to look for
        Scanner input = new Scanner(System.in);
        System.out.println("What is a string to look for?");
        String search = input.nextLine();

        // Remove the spaces (the way i got the text from the website i deleted all the
        // spaces, so remove spaces from search term)
        for (int i = 0; i < search.length(); i++) {
            if (search.charAt(i) == ' ') {
                String firstSub = search.substring(0, i);
                String secondSub = search.substring(i + 1);
                search = firstSub + secondSub;
            }
        }
        input.close();

        // Find the place in the array where the search term is found
        int a = -1;
        int b = -1;
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[0].length; j++) {
                if (array[i][j].equalsIgnoreCase(search)) {
                    a = i;
                    b = j;
                }
            }
        }

        // If term exists in array, pick a random element from the same column to print
        if (a != -1 && b != -1) {
            int[] possible = new int[4];
            int posIndex = 0;
            for (int i = 0; i < 4; i++) {
                if (i == a) {
                    continue;
                } else {
                    possible[posIndex] = i;
                    posIndex++;
                }
            }
            int indexToPrint = (int) Math.floor(Math.random() * (3));
            System.out.println(array[a][indexToPrint]);
            // If search term not found relay that to user
        } else {
            System.out.println("Searched term cant be found");
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }
}
