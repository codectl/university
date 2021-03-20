import java.util.*;
import java.util.stream.Collectors;


/**
 * Representation of a polish notation calculator
 */
public class PNCalculator {

  private final Stack<Object> stack;

  // Supported operators
  private final static Set<Character> operators =
      new HashSet<>(Arrays.asList('+', '-', '*', '/', '%'));

  public PNCalculator() {
    this.stack = new Stack<>();
  }

  /*
   *
   */
  public static boolean verificaParenteses(String infixa) {
    Scanner leitor = new Scanner(infixa);
    boolean equilibrada = true;
    Stack<String> pilha = new Stack<String>();
    String token = "";
    while (equilibrada && leitor.hasNext()) {
      token = leitor.next();
      if (token.equals("("))
        pilha.push(token);
      else if (token.equals(")")) {
        if (!pilha.isEmpty() && pilha.peek().equals("("))
          pilha.pop();
        else
          equilibrada = false;
      }
    }
    return (equilibrada && pilha.empty());
  }

  /*
   *
   */
  public String paraSufixa(String infix) {
    Scanner reader = new Scanner(infix);

    Stack<String> pilha = new Stack<String>();
    StringBuilder sufixa = new StringBuilder();
    String token = "";

//    // Read token by token
//    while (reader.hasNext()) {
//      token = reader.next();
//      if ()
//    }

    return null;
//    while (reader.hasNext()) {
//      token = reader.next();
//      if (!eOperador(token))
//        sufixa.append(token + " ");
//
//      else if (eOperador(token)) {
//        while (temPreferencia(pilha.peek(), token) && !pilha.isEmpty()) {
//          sufixa.append(pilha.pop() + " ");
//        }
//        pilha.push(token);
//      } else if (token.equals("("))
//        pilha.push(token);
//
//      else if (token.equals(")")) {
//        while (pilha.peek() != "(") {
//          sufixa.append(pilha.pop() + " ");
//        }
//        pilha.pop();
//      }
//    }
//    while (!pilha.isEmpty()) {
//      sufixa.append(pilha.pop() + " ");
//    }
//    return sufixa.toString();
  }

  /*
   *
   */
//  public void processToken(char token) {
//
//    if (isOperator(token))
//      stack.push();
//
//    if (!eOperador(token))
//      stack.push(Double.parseDouble(token));
//    else {
//      double a = stack.peek();
//      stack.pop();
//      double b = stack.peek();
//      stack.pop();
//      if (token.equals("+"))
//        stack.push(a + b);
//      else if (token.equals("-"))
//        stack.push(a - b);
//      else if (token.equals("*"))
//        stack.push(a * b);
//      else if (token.equals("/"))
//        stack.push(a / b);
//    }
//  }

  /**
   * Check whether the given character is an arithmetic operator
   *
   * @param c the character to check
   * @return true if is an operator, false otherwise
   */
  public static boolean isOperator(char c) {
    return operators.contains(c);
  }

  /**
   * Check whether one operator has precedence over the other
   *
   * @param o1 the left operator
   * @param o2 the right operator
   * @return true if o1 has precedence over o2
   */
  public static boolean hasPrecedence(char o1, char o2) {
    if (!isOperator(o1) || !isOperator(o2))
      throw new IllegalArgumentException("Wrong operator provided.");

    return "*/%".indexOf(o1) >= 0 && "+-".indexOf(o2) >= 0;
  }

  /**
   * Validate an arithmetic expression.
   * Algorithm: split expression by operators and check if each
   * element is a number.
   *
   * @param expression the expression to validate.
   * @return true if expression is correct, false otherwise.
   */
  public static boolean validateExpression(String expression) {
    return Arrays
        .stream(
            expression
                .replace(" ", "")
                .split("[" + operators.toString() + "]")
        )
        .map(token -> {
          try {
            Double.parseDouble(token);
            return true;
          } catch (NumberFormatException e) {
            return false;
          }
        })
        .reduce(true, (res, element) -> element & res);
  }
}
