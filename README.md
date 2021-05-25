# FormulaFinder

`FormulaFinder` is a tool designed to help people confused with figuring out a physics problem. It is meant to interpret an input string (the given variables of the problem and the variable to solve for) and print to the console the correct formula to use to solve the problem.

Many people are perfectly capable of solving these types of problems, but simply get confused or are uncertain of themselves. `Formula Finder` can be used in those uncertain situations or as an excellent tool for checking one's work.

It should be noted that the program is not a calculator - it only shows what formula to use - it does not print the answer to the problem. Thus, the user must still understand how to manipulate the formulas/solve the equations in order to get their answer. This program is meant only to help with often the hardest part of a problem: determining where to begin.

## How to Use the Program

When the program is first run, the user will see the following prompt:
> Enter Initial Parameters:

The user should then proceed to type the letter of the variable they want to solve for (i.e. `a` for acceleration or `t` for time), followed by the given quantities/other variables given in the problem. Users should separate all values with spaces, and include units on the input quantities. Any given quantities for velocity should be placed at the end of the string.

For example, with *t=3s*, *v0=5m/s*, and *x=4m*, if we wanted to solve for acceleration *a*:
`Enter Initial Parameters: a 3s 4m 5m/s`
where only the positioning of the velocity and the variable to be solved for are definitive. Other variables can be ordered in between in any order.

If we were to enter the above example into the program, it would print the following formula result:
> x = x0 + v0 + (1/2)\*a\*(t^2)

which can then be used to solve for the acceleration using the given values in the problem.

## How it Works
To start, the program requests input from the user. This input is then taken in (formatted as above), and the program stores that raw string. That string is then passed into the method `rec.parse()`, which takes in a string (the input). `rec` is an object of type `VarRec` (which is where all of the input processing is handled). From there, *parse()* calls upon several other methods: *split()*, *convert()*, and *find()*.

### split()
The split function is used to divide up the input string passed to *parse()*, and takes two arguments: said input string and a single character delimiter. The method then searches through each character of the string *s*, and if it **doesn't** match the delimiter, it is added to a string called "buff" (short for buffer). When a character matching the delimiter (i.e. a space) is reached, this buffer is added to a vector and reset to an empty string. This process is then repeated until the end, after which everything still remaining in the buffer is added to the vector. This vector is then returned by the function.

### convert()
Based on the fact that most problems simply indicate "find the acceleration" or "find the force on the object", etc, the variable to be solved for in the problem cannot be processed via the *find()* command. However, since the program has the *convert()* method which analyzes the first value in the split-up string (vector). Due to formatting of the string when it is first entered, the first element of the vector can be passed through this function. Based on the letter (variable), it determines which variable is being looked at. Thus, it can update the *key* of the hashmap accordingly.

### find()
The *find()* function processes the subsequent data in the vector. Instead of reading a string as a variable, it looks at these strings as units. Thus the units indicate what the variable is; i.e. `m/s^2` is recognized as an acceleration, while `deg` is recognized as an angle theta. Velocities and forces (when added as input) are processed last. This is because of the logic setup of the current version: if a time has already been noted in the input it is marked as `v0`. Otherwise it marks off both velocities. This is due to the current prototype having equations for kinematics and forces, and with how they line up this logic works. If there's a time, it is a certain equation and if not, it's one of several other equations which include both velocities.

## Storing and Finding the Formulas
All of the formulas are stored in a `const static unordered_map<string, string>` (using namespace std). The map is constant and static to avoid issues when it is included and used in the program to ensure it isn't unintentionally altered. It is also unordered because with the way the keys are designed, it doesn't matter what order the entries fall in, so it was unnecessary to order the map.

The keys for this map are strings 12 characters long (one for each of the variables present in the prototype). Each of these characters is either `0` or `1`, to indicate whether or not each of those variables is present in the equation. In the `VarRec` object, there is also a string of the same form, but is initialized to `"000000000000"`. Subsequently, when a variable is recognized during input processing, the corresponding character in that string is switched to a `1`. Once all elements of the vector have been analyzed, the program then uses this string as the key used to search the map for a formula, and prints it.

For "corresponding characters", each variable is assigned an index of the key, like making a table. The way the variables have been arranged in this prototype, along with their key indices, are as follows:
> x | v0 | v | a | t | F | m | Fn | Fp | Ff | mu | theta
>
>  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11

These are the position, initial velocity, final velocity, acceleration, time, force, mass, normal force (force into a slope), force parallel (force down a slope), force of friction, coefficient of friction, and angle (of a slope), respectively.

### Printing the Results
Once the key has been determined, it is time to print the proper formula. Firstly, if there was an issue determining the key, the key will return `"NULL"` and print the error message `"An error has occurred. It is likely the unit(s) wasn't recognized. Please try again."` If it prints the normal force or parallel force formulas (the exceptions to the key-building method), the formulas are printed while searching for variables (since they are last by convention of the input). The key then becomes "DONE", at which point the program will stop, not printing or attempting to print something again.

Otherwise, it prints the proper formula based on the key that has been built within the program, and the program is complete.
