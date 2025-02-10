#include <iostream>

void store( ) {
	int result;

	asm(
			"movl $5, %0;" // Assembly code to move value 5 into the variable result
			: "=r"(result) // Output operand: store result in 'result'
			:							 // No input operands
			:							 // No clobbered registers
	);

	std::cout << "The result is: " << result << std::endl;
}

void add( ) {
	int a = 10, b = 20, result;

	asm volatile(
			"mov %1, %%eax;"
			"add %2, %%eax;"
			: "=r"(result)
			: "r"(a), "r"(b)
			: "%eax" //
	);

	printf("result: %d\n", result);
}

void helloWorld( ) {
	const char message[] = "Hello, World!\n";
	const size_t msglength = 12;

	// asm volatile(


	// 		".section .text"
	// 		".global main"

	// 		"main:"
	// 		"mov $4, %eax"
	// 		"mov $1, %ebx"
	// 		"mov $message, %ecx"
	// 		"mov msglength, %edx"
	// 		"int $0x80"
	// 		"mov $1, %eax"
	// 		"mov $0, %ebx"
	// 		"int $0x80" //

	// 		".section .data"
	// 		"message: .ascii \"Hello world!\""
	// 		"msglength: .word 12 " //
	// );

	// asm volatile(
	// 		"movl $4, %%eax;" // syscall: write
	// 		"movl $1, %%ebx;" // file descriptor: stdout
	// 		"movl %0, %%ecx;" // pointer to message
	// 		"movl %1, %%edx;" // message length
	// 		"int $0x80;"			// make the syscall
	// 		:
	// 		: "r"(message), "r"(msglength)	 // input operands
	// 		: "%eax", "%ebx", "%ecx", "%edx" // clobbered registers
	// );

	// asm volatile(
	// 		"movl $1, %%eax;" // syscall: exit
	// 		"movl $0, %%ebx;" // exit code 0
	// 		"int $0x80;"			// make the syscall
	// );

	asm volatile(
			"movq $1, %%rax;" // syscall: write
			"movq $1, %%rdi;" // file descriptor: stdout
			"lea %0, %%rsi;"	// pointer to message
			"movq %1, %%rdx;" // message length
			"syscall;"				// make the syscall
			:
			: "r"(message), "r"(msglength)	 // input operands
			: "%rax", "%rdi", "%rsi", "%rdx" // clobbered registers
	);

	asm volatile(
			"movq $60, %%rax;"	// syscall: exit
			"xor %%rdi, %%rdi;" // exit code 0
			"syscall;"					// make the syscall
	);
}


int main( ) {
	// std::cout << "Hellow World!" << std::endl;

	// store( );
	// add( );

	helloWorld( );
}
