# Lab 11: Memory Management

# Task
Given a 32-bit physical address, write a program to find its corresponding physical page number, the starting address of the physical page (in hex) and offset. Your program should print the above mentioned information from the physical address. Writing this program will require using the appropriate data type to store 32 bit numbers. Make sure to verify your program with multiple test cases that span the entire range of possible 32-bit addresses.

Briefly describe how your algorithm works. Also mention if you notice some characteristic common between all of the starting addresses.
This Lab was basically about bit manipulation. To get the page number i have ANDed the physical address with 0xFF000 (32-bit) and then converted the basic number to hex and to get the offset i have ANDed the physical address with 0x00FFF. If the Number exceeds the 32-bit mark the compiler mis-reads the number’s sign and assumes it to be negative. This is a extreme case.