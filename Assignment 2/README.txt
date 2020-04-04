Grade Earned: 38/40 
Reason: Error handling returns 1, Should have seperate class for x/y coordinates

Description: 
The programming assignment will provide an exercise in using recursion.  There are two problems which need to be solved.  
The first asks for a recursive function to calculate a Catalan number.  
This problem will also require the student to utilize command line arguments for theirprogram.  
The second is to solve a path-finding problem in two dimensional space.  
The second problem will require the usage of recurrence as well as good class design. 

1- The Catalan number form a sequence of natural numbers that occur in many counting problems. 
Write a program called Catalan which takes one argument and calls a recursive function which computes the nth Catalan number.  
The program then prints out the result to std::out.

A robot is positioned on an integral point in a two-dimensional coordinate grid (xr, yr).  T
here is a treasure that has been placed at a point in the same grid at (xt, yt).  All x’s and y’s are integers.
The robot can move up (North), down (South), left (West), or right (East).  
Commands can be given to the robot to move one position in one of the four direction.  
That is, “E” moves a robotone slot East (to the right) so if the robot was on position (3, 4), it would now be on (4, 4).  
The command N would move the robot one position north so a robot at position (4, 4) would be at (4, 5).

Because the robot cannot move diagonally, the shortest distance between a robot at (xr, yr) anda treasure at (xt, yt) is 
| xr –xt | + | yr  - yt | = ShortestPossibleDistance  

Write a recursive program which determines all the unique shortest possible paths from the robot to the treasure with the 
  following stipulation: 
The robot may never move in the same direction more than MaxDistance times in a row.  

The input to the program will be the starting position of the robot (xr, yr), followed by the position of the treasure (xt, yt),
followed by the MaxDistance parameter.  Assume that all five are integers and due not worry about error conditions in inputs.  
Take these parameters as arguments to the program. 

The output of the program should be the listing of all the unique shortest possible paths followed by the number of unique paths.  
The paths must follow the stipulation whereby the robot cannot move in the same direction more than MaxDistance times in a row. 
A path shouldbe output as a string of characters with each character corresponding to a direction the Robot should move. 

For the input 1 2 3 5 2 which corresponds to (1,2) -> (3,5) the output should be:
NNENE
NNEEN
NENNE
NENEN
NEENN
ENNEN
ENENN
Number of paths:  7
