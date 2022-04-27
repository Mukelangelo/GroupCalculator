EX01: Group Calculator

Student's info:
name: Michael Basov	ID: 315223156

Task description:
In this task we built a calculator that can calculate different operations on groups

there are three basic operations that start with the claculator:
(A U B) - union of two groups
(A ^ B) - intersaction of two groups
(A - B) - differential between two groups

after that you can add more operations using the three above with the commands below:
uni - creates union between two operations - e.g: (A U B) U (C - D)
inter - creates intersaction between two operations - e.g: (A U B) ^ (C ^ D)
diff - creates differential between two operations - e.g: (A U B) - (C - D)
prod - creates product between two operations - e.g: (A U B) * (C - D)
comp - creates composition between two operations - e.g: (A U B) -> (C - D)

each new operation can be used with any operation, you can create even bigger operations,
e.g : ((A U B) U (C - D)) ^ ((E U F) - (G ^ H))

more commands:
del - deletes an operaion
help - prints a help menu with all the commands availible
exit - finished the program


List of files:
Action.cpp - A base class for each operation that can be added to the calculator
Calculator.cpp - runs the calculator and the actions, prints the results and the menu
Comp.cpp - prints and calculates the composition action
Diff.cpp - prints and calculates the differential action
Inter.cpp - prints and calculates the intersaction action
Prod.cpp - prints and calculates the product action
Uni.cpp - prints and calculates the union action
Group.cpp - stores sorts the group given
// every .cpp file has a .h file with the same name //

Main databases:
A vector of shared pointers that stores the actions that the calculator can preform

Special Algorithems:

Known bugs:

Other:
