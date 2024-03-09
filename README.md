# Mealy Machine

This code implements a finite automaton (FA) simulation, specifically a Mealy machine, for a given FA defined by a set of states, transitions, and final states. The program follows a series of steps to determine whether a given input string is accepted by the FA.

## Description

The Mealy machine simulation involves the following steps:

1. The program reads the number of states, transitions, and information about each transition, including the initial state, destination state, transition character, and output character.

2. After reading the transition details, the program reads the initial state, the number of final states, and the final states of the FA.

3. The program reads a set of strings and tests whether each string is accepted by the FA.

4. For each string, the program simulates the FA by starting from the initial state and traversing the transition edges corresponding to each character in the string. It accumulates the output characters corresponding to each transition during this process.

5. If the final state reached is one of the final states of the FA, the program outputs "DA" ("YES") followed by the output characters and the path taken in the FA. Otherwise, it outputs "NU" ("NO").

## Usage

1. Define the FA by specifying the number of states, transitions, transition details, initial state, number of final states, and final states.
   
2. Run the program and provide input strings to test the acceptance by the FA.

3. Review the program output to determine whether each input string is accepted or not.

## Notes

- Ensure that the input transition details and FA configuration are accurately defined to simulate the correct behavior of the FA.
- Customize the program as needed to support additional functionalities or modify the FA structure.
