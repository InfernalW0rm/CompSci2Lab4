There are 3 separate problems that are implemented in the main file. Each have 
their own seperate header and cpp files.


Picture Problem:

Color .h and .cpp - basically initializes and creates colors and how they are 
recognized to the program for the continuing implementations of the picture problem.
Picture .h and .cpp - creates the boundaries (width and height) of the picture or
"pixels."
Exceptions.h - creates different exceptions to be thrown in other places in the 
problem.
FileReader .h and .cpp - does pretty much what the name implies. Takes in the file
name from the main function and reads the file into its needed variables.



Stat Tools Problem:

|| DISCLAIMER || - I had several extreme problems with the implementation of cpp files
or basically anything to do with this problem likely due to the template functions
and how they work in the processing of the cpp files. I looked it up and most people
talked about using something called .tpp files, but I found the easiest thing to be
to use the header file. If it mysteriously breaks I promise it works XD.

StatTools .h - this header file identifies and implements the template functions that are
basically just more complicated versions of what we did with the stat tools the other week.



Pemdas Quizzer Problem:
PemdasQuizzer .h and .cpp - These files really just create a quiz that uses recursion
to let you actually play it and answer the questions for it.