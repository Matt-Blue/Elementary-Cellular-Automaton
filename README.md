Overview
- This program is a uniform programmable circular elementary cellular automaton
- State change is based on influence dynamics (values change, they don't move)
- It can be used to generate unique values for use in PRNGs and stream ciphers
- The implementation now increments the seed value and puts it through encryption each time to ensure no loops
- The powerpoint attached includes all the relevant information

Compile and Run
- g++ CA.cpp -o run.exe
- run [seed] [key] [repetitions] [output]
    - example: run 75 30 20 1
    - if this does not work replace "run" with "./run.exe"

Flag values
- Seed: value between 0 and 255
    - Used as base binary array for encryption
    - Suggested value: 75
- Key: value between 0 and 255
    - Based on wolfram's classification
    - Suggested value: 30 (class III)
        - Other options: 86, 135, 149 (all class III)
- Repetitions: number of times to perform computation
    - Suggested value: 5
    -May eventually produce a loop, each repetition not used as output
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
- This result can be used as one round of pseudorandom number generation

Final Note
- For best results use varying seeds with a constant number of repetitions and same key for generation
- In class it was pointed out that the values can loop
    - This is because on round i there is a i / 256 chance that a collision will happen with a previously computed value
    - When this happens, it will cause a loop
    - The amount of repetitions still adds a layer of complexity and programmability and is useful from other projects
- To get a stream of pseudorandom numbers, the function must be called multiple times with either constant or changing input arguments (based on implementation) and an every changing seed value that is not the value returned from the function