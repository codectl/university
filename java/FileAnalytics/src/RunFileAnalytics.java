import java.io.File;
import java.io.IOException;
import java.util.Map;
import java.util.Scanner;

/**
 * The run class for FileAnalytics
 */
public class RunFileAnalytics {

  /**
   * Start the interactive program
   */
  public static void main(String[] args) throws IOException {

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
}
