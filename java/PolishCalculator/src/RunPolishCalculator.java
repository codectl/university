import java.util.Arrays;
import java.util.Scanner;


/**
 * The run class for PolishCalculator
 */
public class RunPolishCalculator {

  /**
   * Start the interactive program
   */
  public static void main(String[] args) {

    // user input
    Scanner in = new Scanner(System.in);

    // start the user interaction with initial instructions
    System.out.println(
        "\n*** Welcome to the PolishCalculator ***\n" +
            "A calculator that uses polish notation for algebraic expressions."
    );
    System.out.println();

    PolishCalculator calculator;
    String expression = null;
    int option;

    do {
      do {
        if (expression != null) {
          System.out.println("Invalid expression. Try again ...");
          System.out.println();
        }
        System.out.println("Valid operators are: + - * / %.");
        System.out.println("Parenthesis are also supported.");
        System.out.print("Expression: ");
        expression = in.nextLine().trim();

      } while (!PolishCalculator.validateInfixExpression(expression));

      // Create new expression
      calculator = new PolishCalculator(expression);
      expression = null;

      do {
        System.out.println();
        System.out.println(
            "Choose your option:\n" +
                "\t1) convert to suffix\n" +
                "\t2) convert to prefix\n" +
                "\t3) show result\n" +
                "\t4) new expression\n" +
                "\t5) exit"
        );
        System.out.print("Your option [1-5]: ");
        option = in.nextInt();
        in.nextLine();  // Consume newline left over
        System.out.println();

        // validate user selection
        switch (option) {
          case 1:
            // convert to suffix notation
            System.out.println("Suffix: " + calculator.infixToSuffix());
            break;
          case 2:
            // convert to prefix notation
            System.out.println("Prefix: " + calculator.infixToPrefix());
            break;
          case 3:
            // solve expression
            System.out.println("Result: " + calculator.solve());
            break;
          case 4:
            break;
          case 5:
            System.out.println("Bye.");
            break;
          default:
            System.out.println("Provide a valid option.");
            break;
        }
      } while (!Arrays.asList(4, 5).contains(option));
    } while (option != 5);
  }
}
