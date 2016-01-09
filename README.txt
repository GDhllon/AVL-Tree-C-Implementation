/*Name: Gary Dhillon 
 * Date: Monday, November 24, 2014 
 * Assignment 4*/

*************
Introduction
*************
This program reads the contents in from a file and organizes thousands of entries into an AVL tree keeping track of the frequency of entries per
ID.

As this is an AVL tree it will constantly keep track of the 'balance' of each node and re organize itself in order to maintain its searching/entry efficiency.


*************
Compiltation
*************

-Open a terminal window, navigate to the Assignment_4 directory and type "make" (no quotes) then press enter.
-Type './avltree' (no quotes) to begin running the avltree program.

*************
Running
*************

avltree

-Upon starting the program the user will see a menu with seven options as outlined in the A4 guideline.

-To choose any of the menu options enter the corresponding number associated with the option.

-Entering 1 will prompt the user to enter a filename with which the program will initialize the binary tree, the file A4_data_file.dat has been included with the submission.

-Entering 2 will prompt the user to enter a key, if the key is found the frequency and key will be printed, otherwise the program will print 'no_such_key'

-Entering 3 will prompt the user to enter a key to insert, if the key is already in the tree its frequency will be incremented, else it will added to the tree.

-Entering 4 will prompt the user to enter a key to remove, if the key has a frequency greater than 1 it will be decremented, else it will be removed. If the key is not found the program will
print 'no_such_key'

-Entering 5 will print the height and size of the tree on another line.

-Entering 6 will prompt the user to enter a frequency, all keys with frequencys greater than the entered value will be printed. (inorder)

-Entering 7 will exit the program.
