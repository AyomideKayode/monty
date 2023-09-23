# Project: 0x19. C - Stacks, Queues - LIFO, FIFO

<img src="./bytecodes/make tea not love.png" alt="Lists vs Tuples" style="width: 100%;">

# Monty Project
## Resources

* [Google](https://www.google.com/webhp?q=stack%20and%20queue)
* [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
* [Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)
* [Stack operations](https://www.digitalocean.com/community/tutorials/stack-in-c)
* [Queue operations](https://www.edureka.co/blog/queue-in-c/)

### General

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## More Info
### Data structures
* Please use the following data structures for this project. Don’t forget to include them in your header file.
	```c
	/**
	* struct stack_s - doubly linked list representation of a stack (or queue)
	* @n: integer
	* @prev: points to the previous element of the stack (or queue)
	* @next: points to the next element of the stack (or queue)
	*
	* Description: doubly linked list node structure
	* for stack, queues, LIFO, FIFO
	*/
	typedef struct stack_s
	{
			int n;
			struct stack_s *prev;
			struct stack_s *next;
	} stack_t;
	```
	```c
	/**
	* struct instruction_s - opcode and its function
	* @opcode: the opcode
	* @f: function to handle the opcode
	*
	* Description: opcode and its function
	* for stack, queues, LIFO, FIFO
	*/
	typedef struct instruction_s
	{
			char *opcode;
			void (*f)(stack_t **stack, unsigned int line_number);
	} instruction_t;
	```
### Compilation & Output
* Your code will be compiled this way:
	```sh
	$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
	```
* Any output must be printed on `stdout`
* Any error message must be printed on `stderr`
* [Here is a link to a GitHub repository](https://github.com/ku1ik/stderred) that could help you making sure your errors are printed on `stderr`

<details>
<summary>The Monty Language</summary>
<br>
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).<br>
It relies on a unique stack, with specific instructions to manipulate it.<br>
The goal of this project is to create an interpreter for Monty ByteCodes files.<br>
Monty byte code files:<br>
Files containing Monty byte codes usually have the ".m" extension.<br>
Most of the industry uses this standard but it is not required by the specification of the language.<br>
There is not more than one instruction per line.<br>
There can be any number of spaces before or after the opcode and its argument.<br>
Monty byte code files can contain blank lines empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.<br>
</details>

### The monty program (IMPORTANT!!!)
* Usage: `monty file`
	- where `file` is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- where `<file>` is the name of the file
* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- where is the line number where the instruction appears.
	- Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
	- it executed properly every line of the file
	- it finds an error in the file
	- an error occured
* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
* You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

## Description of what each file shows(Tasks):

* **[bytecodes](./bytecodes/)**	-	folder holds test files that showcase examples of how to use the monty interpreter.
* **[monty.h](./monty.h)**	-	holds files' function prototypes.
* **[monty.c](./monty.c)**	-	entry point of the monty byte interpreter. Starting point of the program as explained above.

* **Files that start with:**

0. [push, pall](./get_stackFuncs.c) : Implement the push and pall opcodes.
* **<em>The push opcode.</em>**
- The opcode `push` pushes an element to the stack.
	- Usage: `push <int>`
		- where `<int>` is an integer
	- if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`.
		- where is the line number in the file
	- You won’t have to deal with overflows. Use the `atoi` function
* **<em>The pall opcode.</em>**
- The opcode `pall` prints all the values on the stack, starting from the top of the stack.
	- Usage `pall`
	- Format: see example
	- If the stack is empty, don’t print anything
	```sh
	julien@ubuntu:~/monty$ cat -e bytecodes/00.m
	push 1$
	push 2$
	push 3$
	pall$
	julien@ubuntu:~/monty$ ./monty bytecodes/00.m
	3
	2
	1
	julien@ubuntu:~/monty$
	```
1. [pint](./get_stackFuncs.c) : Implement the pint opcode.
* **<em>The pint opcode</em>**
- The opcode pint prints the value at the top of the stack, followed by a new line.
	- Usage: `pint`
	- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/06.m 
	push 1
	pint
	push 2
	pint
	push 3
	pint
	julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
	1
	2
	3
	julien@ubuntu:~/monty$ 
	```
2. [pop](./stackFuncs2.c) : Implement the pop opcode.
* **<em>The pop opcode</em>**
- The opcode `pop` removes the top element of the stack.
	- Usage: `pop`
	- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/07.m 
	push 1
	push 2
	push 3
	pall
	pop
	pall
	pop
	pall
	pop
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
	3
	2
	1
	2
	1
	1
	julien@ubuntu:~/monty$ 
	```
3. [swap](./stackFuncs2.c) : Implement the swap opcode.
* **<em>The swap opcode</em>**
- The opcode `swap` swaps the top two elements of the stack.
	- Usage: `swap`
	- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/09.m 
	push 1
	push 2
	push 3
	pall
	swap
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
	3
	2
	1
	2
	3
	1
	julien@ubuntu:~/monty$ 
	```
4. [add](./math_stackFuncs.c) : Implement the add opcode.
* **<em>The add opcode</em>**
- The opcode `add` adds the top two elements of the stack.
	- Usage: `add`
	- if the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		- The top element of the stack contains the result
		- The stack is one element shorter
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/12.m 
	push 1
	push 2
	push 3
	pall
	add
	pall

	julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
	3
	2
	1
	5
	1
	julien@ubuntu:~/monty$
	```
5. [nop](./stackFuncs2.c) :Implement the nop opcode.
* **<em>The nop opcode</em>**
- The opcode `nop` doesn’t do anything.
	- Usage: `nop`
6. [sub](./math_stackFuncs.c) : Implement the `sub` opcode.
* **<em>The sub opcode</em>**
- The opcode `sub` subtracts the top element of the stack from the second top element of the stack.
	- Usage: `sub`
	- If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		- The top element of the stack contains the result
		- The stack is one element shorter
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/19.m 
	push 1
	push 2
	push 10
	push 3
	sub
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/19.m 
	7
	2
	1
	julien@ubuntu:~/monty$
	```
7. [div](./math_stackFuncs.c) : Implement the `div` opcode.
* **<em>The div opcode</em>**
- The opcode `div` divides the second top element of the stack by the top element of the stack.
	- Usage: `div`
	- If the stack contains less than two elements, print the error message `L<line_number>: can't div`, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`
	- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		- The top element of the stack contains the result
		- The stack is one element shorter
	- If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`
8. [mul](./math_stackFuncs.c) : Implement the `mul` opcode.
* **<em>The mul opcode</em>**
- The opcode `mul` multiplies the second top element of the stack with the top element of the stack.
	- Usage: `mul`
	- If the stack contains less than two elements, print the error message `L<line_number>: can't mul`, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`
	- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		- The top element of the stack contains the result
		- The stack is one element shorter
9. [mod](./math_stackFuncs.c) : Implement the `mod` opcode.
* **<em>The mod opcode</em>**
- The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.
	- Usage: `mod`
	- If the stack contains less than two elements, print the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
		- The top element of the stack contains the result
		- The stack is one element shorter
	- If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`
10. [comments](./monty.c) : 
* Every good language comes with the capability of commenting.
* When the first non-space character of a line is `#`, treat this line as a comment (don’t do anything).
11. [pchar](./stackFuncs2.c) : Implement the `pchar` opcode.
* **<em>The pchar opcode</em>**
- The opcode `pchar` prints the char at the top of the stack, followed by a new line.
	- Usage: `pchar`
	- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
	- If the value is not in the ascii table (man ascii) print the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`
	- If the stack is empty, print the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/28.m 
	push 72
	pchar
	julien@ubuntu:~/monty$ ./monty bytecodes/28.m 
	H
	julien@ubuntu:~/monty$
	```
12. [pstr](./stackFuncs2.c) : Implement the `pstr` opcode.
* **<em>The pstr opcode</em>**
- The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.
	- Usage: `pstr`
	- The integer stored in each element of the stack is treated as the ascii value of the character to be printed
	- The string stops when either:
		- the stack is over
		- the value of the element is 0
		- the value of the element is not in the ascii table
	- If the stack is empty, print only a new line
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/31.m 
	push 1
	push 2
	push 3
	push 4
	push 0
	push 110
	push 0
	push 108
	push 111
	push 111
	push 104
	push 99
	push 83
	pstr
	julien@ubuntu:~/monty$ ./monty bytecodes/31.m 
	School
	julien@ubuntu:~/monty$ 
	```
13. [rotl](./rotl_and_rotr.c) : Implement the `rotl` opcode.
* **<em>The rotl opcode</em>**
- The opcode `rotl` rotates the stack to the top.
	- Usage: `rotl`
	- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
	- rotl never fails
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/35.m 
	push 1
	push 2
	push 3
	push 4
	push 5
	push 6
	push 7
	push 8
	push 9
	push 0
	pall
	rotl
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/35.m 
	0
	9
	8
	7
	6
	5
	4
	3
	2
	1
	9
	8
	7
	6
	5
	4
	3
	2
	1
	0
	julien@ubuntu:~/monty$ 
	```
14. [rotr](./rotl_and_rotr.c) : Implement the `rotr` opcode.
* **<em>The rotr opcode</em>**
- The opcode `rotr` rotates the stack to the bottom.
	- Usage: `rotr`
	- The last element of the stack becomes the top element of the stack
	- rotr never fails
15. [stack, queue](./switch_stackQueues.c) : Implement the `stack` and `queue` opcodes.
* **<em>The stack opcode</em>**
- The opcode `stack` sets the format of the data to a stack (LIFO). This is the default behavior of the program.
	- Usage: `stack`
* **<em>The queue opcode</em>**
- The opcode `queue` sets the format of the data to a queue (FIFO).
	- Usage: `queue`
- When switching mode:
	- The top of the stack becomes the front of the queue
	- The front of the queue becomes the top of the stack
	```sh
	julien@ubuntu:~/monty$ cat bytecodes/47.m
	queue
	push 1
	push 2
	push 3
	pall
	stack
	push 4
	push 5
	push 6
	pall
	add
	pall
	queue
	push 11111
	add
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/47.m
	1
	2
	3
	6
	5
	4
	1
	2
	3
	11
	4
	1
	2
	3
	15
	1
	2
	3
	11111
	julien@ubuntu:~/monty$ 
	```
16. [Brainf*ck](./bf/1000-school.bf) : Write a Brainf*ck script that prints `School`, followed by a new line.
	- All your Brainf*ck files should be stored inside the `bf` sub directory
	- You can install the `bf` interpreter to test your code: `sudo apt-get install bf`
	- Read: [Brainf*ck](https://en.wikipedia.org/wiki/Brainfuck)
	```sh
	julien@ubuntu:~/monty/bf$ bf 1000-school.bf 
	School
	julien@ubuntu:~/monty/bf$ 
	```
17. [Add two digits](./bf/1001-add.bf) : Add two digits given by the user.
	- Read the two digits from stdin, add them, and print the result
	- The total of the two digits with be one digit-long (<10)
	```sh
	julien@ubuntu:~/monty/bf$ bf ./1001-add.bf
	81
	9julien@ubuntu:~/monty/bf$
	```
18. [Multiplication](./bf/1002-mul.bf) : Multiply two digits given by the user.
	- Read the two digits from stdin, multiply them, and print the result
	- The result of the multiplication will be one digit-long (<10)
	```sh
	julien@ubuntu:~/monty/bf$ bf 1002-mul.bf
	24
	8julien@ubuntu:~/monty/bf$
	```
19. [Multiplication level up](./bf/1003-mul.bf) : Multiply two digits given by the user.
	- Read the two digits from stdin, multiply them, and print the result, followed by a new line
	```sh
	julien@ubuntu:~/monty/bf$ bf 1003-mul.bf 
	77
	49
	julien@ubuntu:~/monty/bf$ 
	```
---
### Environment
* Language: C
	* OS: Ubuntu 14.04 LTS
	* Compiler: gcc 4.8.4 (gcc -Wall -pedantic -Werror -Wextra -std=c89 *.c -o monty)
	* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

---
## Author

- <em>Website</em> - [Ayomide Kayode](https://github.com/AyomideKayode)
- <em>ALX Software Engineering Program</em> - [ALX_AFRICA](https://www.alxafrica.com/programmes/)
- <em>Twitter</em> - [@kazzy_wiz](https://www.twitter.com/kazzy_wiz)