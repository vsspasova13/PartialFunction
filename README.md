Consider an abstract base class Partial Function, which transforms 32-bit integers into 32-bit integers and necessarily has an operation to check whether the function is defined for a given point and an operation to calculate the result of the function for a given x.
Implement the following specific descendants of the abstract base class Partial Function:

1. Partial function by criterion – The constructor is given a function (this can be a function or an object that behaves like one), which, given an argument number, returns an ordered pair - whether the function is defined there and if so, what the result is.
2. Maximum of partial functions – The constructor is given several Partial Functions, and the newly created object (the maximum of the given Partial Functions) is defined at a point only if all the given functions are defined there. The result for a given x will be the maximum of the results of the given functions for the same x.
3. Minimum of partial functions – The constructor is given several Partial Functions, and the newly created object (the minimum of the given Partial Functions) is defined at a point only if all the given functions are defined there. The result for a given x will be the minimum of the results of the given functions for the same x.

Implement a program that reads from a binary file func.dat information about a partial function and constructs a new partial function according to the rules specified in the binary file.

At the beginning of the binary file, there are two non-negative 16-bit integers N and T, for which the following is true:
- The value of N does not exceed 32
- The value of T determines the content of the binary file thereafter and how the corresponding function is constructed. The possible values for T and the construction rules for the new partial function behind them are as follows:

0 – follows 2N 32-bit integers, which define the function (<arg1>... <argN> <res1> ... <resN>). The function is defined only at the given arguments.
1 – follows N 32-bit integers, defining a partial function that is not defined at any of the given numbers. For any other given x, the function should return x.
2 – follows N 32-bit integers, defining a partial function that returns 1 if one of these numbers is given as an argument, and 0 for any other. The function is defined for every number.
3 – follows N strings, each terminated with 0 and describing the path to a binary file. The given binary files also define partial functions, with their maximum representing the current partial function.
4 – follows N strings, each terminated with 0 and describing the path to a binary file. The given binary files also define partial functions, with their minimum representing the current partial function.

The program should operate in two modes:
1. Accept two integers a and b from standard input and output the results of the function for all numbers in the interval [a; b].
2. Allow sequential generation of the result for each defined point, with each subsequent element generated on request from the user.
