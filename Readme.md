The basic breakdown of responsibilities:

Justin : Parser, Calculator class , Constant 

Ian : Exponent (which was later made a member function of all the Number subclasses) and Tokenizer , Rational class constructors

Hanif : Rational Class , also getting Integer to work with Parser later.  

Kyle : Integer, main, Constant, Log bug fixes  

Tylor : Radical Class

Nick : Logarithm class, edits to other classes to work with log class


See the two branches of our project (and the commits) at the following links: 
https://github.com/UF-COP-3053-Group/COP-3503-Project  
https://github.com/UF-COP-3053-Group/COP-3503-Project/tree/working

"working" is the branch used for submission. 

Our code seems to compile but running the executable results in a segmentation fault. Individual core elements of our project definitely work, hopefully we can fit the pieces together for the final submission.  To see some examples of previous tests that do run, go the /bin directory and run either the calculator or old_calculator_test programs (these are really the same file) with either 'test' or 'rational' as the command-line arguement variable.

So, to run the 'test', type 

./calculator test

in a terminal. 

To run the 'rational' class tests, type 

./calculator rational 


Running the calculator with the arguement 'test' illustrates the create of various objects (Number subclasses) and basic operations those objects.  Running calculator with the rational arguement variable allows you to create rational numbers (fractions where the numerator and denominator are integers), simplify them, see their gcd, and perform basic operations (+ - * /).  To see the logic behind the implementation of this, see src/Rational.cpp. 

Our /docs directory contains the submission files for part 1 of the project. 

/src contains the source files, as expected. 

/temp contains two files for dealing with prime numbers that are not part of the actual program (yet) but could prove to be useful for submission 2, particularly for the logarithm class where logarithms are expressed as the sum of primes in simplest form.  
