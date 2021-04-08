# FileAnalytics

An interactive program to provide insights over a
desired text document.

The program allows you to perform certain actions
on any given file:

	1) show file content
	2) count word occurrences
	3) count character occurrences per word
	4) additional information

For instance, given the option ```4```, for the
```sample.txt``` file provided as an example, the
result is:

    There are 69 words.
    There are 165 vowels.
    There are 204 consonants.
    There are 2 kinds of punctuation marks: [,, .]
    There are 4 repetitive words: [dolor, dolore, in, ut]

Run the program and try all the available actions.

## Instructions

In the menu options, input option 5 for instructions, like so:

    Choose your option:
	1) show file content
	2) count word occurrences
	3) count character occurrences per word
	4) additional information
	5) display instructions
	6) exit

    Your option [1-6]: 5
    
    FileAnalytics is a program that provides insights over a given file.
    
    A valid path file is required so using absolute path is recommended.
    A possible value could be ~/documents/my_file.txt.
    If none is specified, a sample text is provided for you.
    
    Afterwards an options menu is displayed.
    Input the right option for the desired action.
    For instance, to display these instruction, input option 5.
    To exit program, input option 6.

## Requirements

The program requires ```Java 8``` version or latter.

## Execution example:

    *** Welcome to the FileAnalytics ***

    Input your file to process.
    File [sample.txt]:

    Choose your option:
	1) show file content
	2) count word occurrences
	3) count character occurrences per word
	4) additional information
	5) display instructions
	6) exit

    Your option [1-6]: 2
    Word to search by: in
    
    There are 3 occurrences of word 'in'.

    Choose your option:
	1) show file content
	2) count word occurrences
	3) count character occurrences per word
	4) additional information
	5) display instructions
	6) exit
    Your option [1-6]: 3
    Character to search by: a
    
    There are 1 number of occurrences of 'a' in 19 words.
    There are 2 number of occurrences of 'a' in 5 words.
    
    Choose your option:
	1) show file content
	2) count word occurrences
	3) count character occurrences per word
	4) additional information
	5) display instructions
	6) exit
    Your option [1-5]: 6

    Bye.
