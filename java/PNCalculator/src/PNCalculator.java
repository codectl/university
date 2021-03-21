import java.util.*;
import java.util.stream.Collectors;


/**
 * Representation of a polish notation calculator
 */
public class PNCalculator {

  // Supported operators
  private final static Set<Character> operators =
      new HashSet<>(Arrays.asList('+', '-', '*', '/', '%'));

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
  private static boolean isOperator(char c) {
    return operators.contains(c);
  }

  /**
   * Convert an infix expression into a suffix.
   * @param expression the expression to convert
   * @return the suffix expression
   */
  public static String infixToSuffix(String expression) {
    if (!validateInfixExpression(expression))
      throw new IllegalArgumentException("Invalid expression");

    StringBuilder postfix = new StringBuilder();
    Stack<Character> operators = new Stack<>();

    for (char token : expression.toCharArray()) {
      // Stack the open bracket
      if (token == '(') {
        operators.push(token);
      }
      // Unstack operators until closing bracket is found
      else if (token == ')') {
        Character top;
        do {
          top = operators.pop();
          postfix.append(top);
        } while (top != '(');
      }
      // Unstack all operators that have prevalence over
      // operator under evaluation and stack it at last
      else if (isOperator(token)) {
        while (!operators.isEmpty()
            && isOperator(operators.peek())
            && hasPrecedence(operators.peek(), token)
        )
          postfix.append(operators.pop());
        operators.push(token);
      }
      // Append operand to result
      else {
        postfix.append(token);
      }
    }

    // Push remaining stack to the end result
    while (!operators.isEmpty())
      postfix.append(operators.pop());

    // Adding blank spaces in between characters for better visuals
    return postfix.toString().chars()
        .mapToObj(c -> (char) c + " ")
        .collect(Collectors.joining())
        .trim();
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
   * operand is valid and follows infix notation.
   *
   * @param expression the expression to validate.
   * @return true if expression is correct, false otherwise.
   */
  public static boolean validateInfixExpression(String expression) {
    List<String> expressions;
    try {
      expressions = getBracketExpressions(expression);
    } catch (IllegalArgumentException e) {
      return false;
    }

    // Process single expression
    if (expressions.isEmpty()) {
      String regex = operators.stream()
          .map(op -> '\\' + op.toString())
          .collect(Collectors.joining());
      String[] operands = expression
          .split("[" + regex + "]");

      // In between an operator must always be an operand
      return operands.length > 1 && Arrays
          .stream(operands)
          .map(token -> {
            try {
              Double.parseDouble(token);
              return true;
            } catch (NumberFormatException e) {
              return false;
            }
          })
          .reduce(true, (elem1, elem2) -> elem1 & elem2);
    } else {
      // Bracket expressions must obey to single expression rules
      // and so it should its content
      return
          validateInfixExpression(
              expressions
                  .stream()
                  .reduce(expression, (elem1, elem2) -> expression
                      .replace('(' + elem1 + ')', "0")
                      .replace('(' + elem2 + ')', "0"))
          )
              &&
              expressions
                  .stream()
                  .map(PNCalculator::validateInfixExpression)
                  .reduce(true, (elem1, elem2) -> elem1 & elem2);
    }
  }

  /**
   * Get round bracket expressions within an expression.
   *
   * @param expression the expression to check
   * @return list of bracket expressions
   */
  private static List<String> getBracketExpressions(String expression) {
    List<String> results = new ArrayList<>();

    int control = 0;
    StringBuilder partial = new StringBuilder();
    for (char c : expression.toCharArray()) {
      switch (c) {
        case '(':
          if (control++ == 0) partial.setLength(0);
          else partial.append(c);
          break;
        case ')':
          if (--control == 0) results.add(partial.toString());
          else partial.append(c);
          break;
        default:
          if (control > 0) partial.append(c);
          break;
      }
    }

    // Check if parenthesis are unbalanced
    if (control != 0)
      throw new IllegalArgumentException("Unbalanced expression");

    return results;
  }
}
