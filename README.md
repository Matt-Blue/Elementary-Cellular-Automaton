Overview
- This program is a uniform programmable circular elementary cellular automaton
- State change is based on influence dynamics (values change, they don't move)
- It can be used to generate unique values for use in PRNGs and stream ciphers

Compile and Run
- g++ CA.cpp -o run.exe
- run [seed] [key] [repetitions] [output]
    - example: run 75 30 20 1

Flag values
- Seed: value between 0 and 255
    - Used as base binary array for encryption
    - Suggested value: 75
- Key: value between 0 and 255
    - Based on wolfram's classification
    - Suggested value: 30 (class III)
        - Other options: 86, 135, 149 (all class III)
- Repetitions: number of times to perform computation
    - Suggested value: 20 for speed 100 for randomness
- Output: 1 for output of each round, 0 otherwise

Output
- Each round is outputted if 1 is inputed for the output value
- Returns result in the form of an int as a decimal representation of the binary values found
- Example output
    Output for iteration 1
    10100111 = 167

    Output for iteration 2
    11010100 = 212

    ...
    