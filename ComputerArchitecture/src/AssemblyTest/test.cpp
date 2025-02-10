#include <iostream>

// void store( ) {
// 	int result;

// 	asm(
// 			"movl $5, %0;" // Assembly code to move value 5 into the variable result
// 			: "=r"(result) // Output operand: store result in 'result'
// 			:							 // No input operands
// 			:							 // No clobbered registers
// 	);

// 	std::cout << "The result is: " << result << std::endl;
// }

void add( ) {
	int a = 10, b = 20, result;

	__asm__ __volatile__(
			"mov %1, %%eax;"
			"add %2, %%eax;"
			: "=r"(result)
			: "r"(a), "r"(b)
			: "%eax" //
	);

	printf("result: %d\n", result);
}

void helloWorld( ) {
	// asm(


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
	// 		"msglength :.word 12 " //
	// );
}

int main( ) {
	// std::cout << "Hellow World!" << std::endl;

	// store( );
	add( );

	// helloWorld( );
}
