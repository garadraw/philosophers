Tutorials:

1. Threads: https://www.youtube.com/watch?v=d9s_d28yJq0&ab_channel=CodeVault

2. Race Conditions: https://www.youtube.com/watch?v=FY9livorrJI&ab_channel=CodeVault

3. Mutex: https://www.youtube.com/watch?v=oq29KUy29iQ&ab_channel=CodeVault

4. Create Threads in a Loop: https://www.youtube.com/watch?v=xoXzp4B8aQk&ab_channel=CodeVault

5. Return Value from Thread: https://www.youtube.com/watch?v=ln3el6PR__Q&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=7



Steps Necessary in Building the Program: 
1. Argument Checkers
2. Initialize Arguments into Structs
3. Create the Threads
4. Set the Ground Rules for the "Game"
5. Grab and Handle Time
6. Create the Mutexes for Forks, Eating and Printing
7. Destroy Mutexes, Free Allocated Memmory


Random:
1. Add "-pthread" to tasks.json File to be able to Create and Join Threads, otherwise must use the -pthread Flag when Compiling (gcc -g -pthread file.c)
2. gcc -S filename.c  Compiles C Code into Assembly Code(.s file)
3.  