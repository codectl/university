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
    System.out.println("\n*** Welcome to the FileAnalytics ***\n");

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
              "\t1) show instructions\n" +
              "\t2) show file content\n" +
              "\t3) count word occurrences\n" +
              "\t4) count character occurrences per word\n" +
              "\t5) additional information\n" +
              "\t6) exit"
      );
      System.out.print("Your option [1-6]: ");
      option = in.nextInt();

      // validate user selection
      switch (option) {
        case 1:
          System.out.println(
              "\nFileAnalytics is a program that provides insights over a given file.\n" +
                  "\n" +
                  "A valid path file is required so using absolute path is recommended.\n" +
                  "A possible value could be ~/documents/my_file.txt.\n" +
                  "If none is specified, a sample text is provided for you.\n" +
                  "\n" +
                  "Afterwards an options menu is displayed.\n" +
                  "Input the right option for the desired action.\n" +
                  "For instance, to display these instruction, input option 1.\n" +
                  "To exit program, input option 6.");
          break;
        case 2:
          // show content
          System.out.println();
          System.out.print(processor.content);
          break;
        case 3:
          // read string input
          System.out.print("Word to search by: ");
          String word = in.next();

          System.out.printf("\nThere are %d occurrences of word '%s'.\n",
              processor.wordOccurrences(word), word);
          break;
        case 4:
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
        case 5:
          System.out.println();
          System.out.printf("There are %d words.\n", processor.wordCount());
          System.out.printf("There are %d vowels.\n", processor.vowelsCount());
          System.out.printf("There are %d consonants.\n", processor.consonantsCount());
          System.out.printf("There are %d kinds of punctuation marks: %s\n",
              processor.getPunctuationMarks().size(), processor.getPunctuationMarks().toString());
          System.out.printf("There are %d repetitive words: %s\n",
              processor.getRepetitiveWords().size(), processor.getRepetitiveWords().toString());
          break;
        case 6:
          System.out.println();
          System.out.println("Bye.");
          break;
        default:
          System.out.println("Provide a valid option.");
      }
    } while (option != 6);
  }
}
