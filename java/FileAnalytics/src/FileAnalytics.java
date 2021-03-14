import java.io.*;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class FileAnalytics {

  // the file content
  private final String content;

  public static void main(String[] args) throws IOException {

    // Start off the program
    start();
  }

  /**
   * Start the interactive program
   */
  private static void start() throws IOException {

    // user input
    Scanner in = new Scanner(System.in);

    // start the user interaction with initial instructions
    System.out.println(
        "\n*** Welcome to the FileAnalytics ***\n" +
            "A tool that given a file, provides you with a\n" +
            "serious of statistics of your choice.\n\n" +
            "Start off by providing the file path you wish to process.\n" +
            "If none is specified, a sample text is provided for you.\n"
    );

    // location for the sample file
    File sample = new File(System.getProperty("user.dir"), "resources/sample.txt");
    File file;

    // get input file
    System.out.println("Input your file to process.");
    System.out.printf("File [%s]: ", sample.getName());

    // reading file name
    String filename = in.nextLine();
    file = filename.isEmpty() ? sample : new File(filename);

    // the processor object
    FileAnalytics processor = new FileAnalytics(file);

    int option;
    do {
      System.out.println();
      System.out.println(
          "Choose your option:\n" +
              "\t1) show file content\n" +
              "\t2) count word occurrences\n" +
              "\t3) count character occurrences per word\n" +
              "\t4) additional information\n" +
              "\t5) exit"
      );
      System.out.print("Your option [1-5]: ");
      option = in.nextInt();

      // validate user selection
      switch (option) {
        case 1:
          // show content
          System.out.println();
          System.out.print(processor.content);
          break;
        case 2:
          // read string input
          System.out.print("Word to search by: ");
          String word = in.next();

          System.out.printf("\nThere are %d occurrences of word '%s'.\n",
              processor.wordOccurrences(word), word);
          break;
        case 3:
          // read char input
          System.out.print("Character to search by: ");
          char ch = in.next().charAt(0);

          // count char occurrences
          Map<Integer, Long> occurs = processor.charOccurrencesPerWord(ch);
          if (occurs.isEmpty())
            System.out.printf("\nThere are no occurrences of '%c'.\n\n", ch);
          else {
            System.out.println();
            occurs.forEach((key, value) -> System.out.printf(
                "There are %d number of occurrences of '%c' in %d words.\n",
                key, ch, value
            ));
          }
          break;
        case 4:
          System.out.println();
          System.out.printf("There are %d words.\n", processor.wordCount());
          System.out.printf("There are %d vowels.\n", processor.vowelsCount());
          System.out.printf("There are %d consonants.\n", processor.consonantsCount());
          System.out.printf("There are %d kinds of punctuation marks: %s\n",
              processor.getPunctuationMarks().size(), processor.getPunctuationMarks().toString());
          System.out.printf("There are %d repetitive words: %s\n",
              processor.getRepetitiveWords().size(), processor.getRepetitiveWords().toString());
          break;
        case 5:
          System.out.println();
          System.out.println("Bye.");
          break;
        default:
          System.out.println("Provide a valid option.");
      }
    } while (option != 5);
  }

  /**
   * Constructor
   *
   * @param file the file to read
   */
  public FileAnalytics(File file) throws IOException {
    Scanner reader = new Scanner(new FileReader(file));
    StringBuilder content = new StringBuilder();

    while (reader.hasNext()) {
      content.append(reader.nextLine());
      content.append('\n');
    }
    reader.close();

    // save file content
    this.content = content.toString();
  }

  /**
   * Counting the number of words
   *
   * @return the count result
   */
  private long wordCount() {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .count();
  }

  /**
   * Counting the number of occurrences of a word
   *
   * @param word the string to search by
   * @return the count result
   */
  private long wordOccurrences(String word) {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .filter(str -> str.equals(word))
        .count();
  }

  /**
   * Counting the number of vowels
   *
   * @return the count result
   */
  private long vowelsCount() {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .flatMap(str -> str.chars().mapToObj(
            ch -> (char) ch
        )).filter(ch -> "aeiou".indexOf(ch) >= 0)
        .count();
  }

  /**
   * Counting the number of consonants
   *
   * @return the count result
   */
  private long consonantsCount() {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .flatMap(str -> str.chars().mapToObj(
            ch -> (char) ch
        )).filter(ch -> "aeiou".indexOf(ch) < 0)
        .count();
  }

  /**
   * Get the existing punctuation marks
   *
   * @return the set of punctuation marks
   */
  private Set<Character> getPunctuationMarks() {
    return Arrays
        .stream(content.split("\\s+"))
        .flatMap(str -> str.chars().mapToObj(
            ch -> (char) ch
        )).filter(ch -> !Character.isLetterOrDigit(ch))
        .collect(Collectors.toSet());
  }

  /**
   * Get the set of repetitive words
   *
   * @return the set of repetitive words
   */
  private Set<String> getRepetitiveWords() {
    List<String> words = Arrays.asList(content.split("\\s+"));
    return words
        .stream()
        .filter(word -> Collections.frequency(words, word) > 1)
        .collect(Collectors.toSet());
  }

  /**
   * Counting the number of occurrences of a char per word
   *
   * @param c the char to search by
   * @return the list of results
   */
  private Map<Integer, Long> charOccurrencesPerWord(char c) {
    String content = removePunctuation(this.content);
    return Arrays
        .stream(content.split("\\s+"))
        .map(str -> str.chars().mapToObj(
            ch -> (char) ch
        ).filter(ch -> ch == c))
        .map(stream -> stream.toArray().length)
        .filter(size -> size > 0)
        .collect(
            Collectors.groupingBy(
                Function.identity(),
                Collectors.counting()
            )
        );
  }

  /**
   * Remove all punctuation from a text.
   *
   * @param text the text to read from
   * @return the converted text
   */
  private static String removePunctuation(String text) {
    if (text == null) {
      return null;
    }

    return text.replaceAll("[^a-zA-Z \n]", "");
  }
}
