/*
 * Daniel Langer
 * 114662901
 * Class to represent stocks
 */

class Stock {
    String symbol;
    String name;
    double previousClosingPrice;
    double currentPrice;

    // ** Construct a stock object */
    public Stock(String initSymbol, String initName) {
        symbol = initSymbol;
        name = initName;
    }

    // ** Return the symbol of stock object*/
    public String getSymbol() {
        return symbol;
    }

    // ** Return name of stock object */
    public String getName() {
        return name;
    }

    // ** Return previous closing price of stock object */
    public double getPreviousClosingPrice() {
        return previousClosingPrice;
    }

    // ** Return current price of stock object*/
    public double getCurrentPrice() {
        return currentPrice;
    }

    // ** Set previous closing price of stock object*/
    public void setPreviousClosingPrice(double newPreviousClosingPrice) {
        previousClosingPrice = newPreviousClosingPrice;
    }

    // ** Set current price of stock object*/
    public void setCurrentPrice(double newCurrentPrice) {
        currentPrice = newCurrentPrice;
    }

    // ** Return the percent change between previous closing price and current
    // price; */
    public String changePercent() {
        return String.format(
                name + " changed by "
                        + ((double) Math.round(((currentPrice / previousClosingPrice) - 1.0) * 10000.0) / 100)
                        + "%%");
    }

}

public class TestStock {
    public static void main(String[] args) {
        Stock google = new Stock("GOOG", "Google Inc.");
        google.setPreviousClosingPrice(100);
        google.setCurrentPrice(90);
        System.out.println(google.changePercent());

        Stock facebook = new Stock("META", "Meta Platforms Inc");
        facebook.setPreviousClosingPrice(161.25);
        facebook.setCurrentPrice(160.03);
        System.out.println(facebook.changePercent());

        Stock amazon = new Stock("AMZN", "Amazon.com, Inc.");
        amazon.setPreviousClosingPrice(106.21);
        amazon.setCurrentPrice(109.56);
        System.out.println(amazon.changePercent());

    }
}
