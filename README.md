# FormulaFinder

``FormulaFinder`` is a tool designed to help people confused with figuring out a physics problem. It is meant to interpret an input string (the given variables of the problem and the variable to solve for) and print to the console the correct formula to use to solve the problem.

Many people are perfectly capable of solving these types of problems, but simply get confused or are uncertain of themselves. ``Formula Finder`` can be used in those uncertain situations or as an excellent tool for checking one's work.

It should be noted that the program is not a calculator - it only shows what formula to use - it does not print the answer to the problem. Thus, the user must still understand how to manipulate the formulas/solve the equations in order to get their answer. This program is meant only to help with often the hardest part of a problem: determining where to begin.

## How to Use the Program

When the program is first run, the user will see the following prompt:
> Enter Initial Parameters:

The user should then proceed to type the letter of the variable they want to solve for (i.e. `a` for acceleration or `t` for time), followed by the given quantities/other variables given in the problem. Users should separate all values with spaces, and include units on the input quantities. Any given quantities for velocity should be placed at the end of the string.

For example, with *t=3s*, *v0=5m/s*, and *x=4m*, if we wanted to solve for acceleration *a*:
``Enter Initial Parameters: a 3s 4m 5m/s``
where only the positioning of the velocity and the variable to be solved for are definitive. Other variables can be ordered in between in any order.

If we were to enter the above example into the program, it would print the following formula result:
> x = x0 + v0 + (1/2)\*a\*(t^2)

which can then be used to solve for the acceleration using the given values in the problem.
