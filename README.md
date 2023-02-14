<h1> Mealy Machine</h1>

This code performs a finite automaton (FA) simulation for a given FA defined by a set of states, transitions, and final states. It reads the number of states, the number of transitions, and information about each transition, including the initial state, the destination state, the transition character, and the character that should be output. The program then reads the initial state, the number of final states, and the final states of the FA.

After reading the input, the program reads a set of strings and tests whether each string is accepted or not by the FA. The acceptance of a string is determined by whether the string can be used to reach a final state in the FA.

For each string, the program simulates the FA by starting from the initial state and traversing the transition edges corresponding to each character in the string until the final character is reached. The output characters corresponding to each transition are also accumulated during this process. If the final state is a final state of the FA, the program outputs "DA" followed by the output characters and the path taken in the FA. Otherwise, the program outputs "NU".
