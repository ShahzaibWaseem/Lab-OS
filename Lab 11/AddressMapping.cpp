#include <iostream>

using namespace std;

void AddressMapping(int32_t address);
int main(int argc, char const *argv[]){
	AddressMapping(19986);
	AddressMapping(21314);
	AddressMapping(314535);
	AddressMapping(135335353453);		// Exceding 32-bits
	AddressMapping(123);				// Page 0
	return 0;
}

void AddressMapping(int32_t address){
	cout << "Physical Address (dec) \t\t: \t" << dec << address << endl;
	cout << "Physical Address (hex) \t\t: \t" << hex << address << endl;
	// Bit Representation of Page (P) and Offset (O) = PPOOO

	int32_t page_number = address & 0xFF000;	// Page = Getting the first 2 Hex Numbers
	cout << "Page Number is \t\t\t=\t" << hex << (page_number >> 12) << endl;
	cout << "Starting Address \t\t=\t0x" << page_number << endl;

	int32_t offset = address & 0x00FFF;			// Offset = Getting the last 3 Hex Numbers
	cout << "Offset \t\t\t\t=\t" << dec << offset << " (" << hex << offset << ")" << endl << endl;
}