#include <cstring>
#include <iostream>
#include <iomanip>

#include "fake_serial.h"

#ifdef UNIT_TEST
void FakeSerial::begin(unsigned long speed) {
  return;
}

void FakeSerial::end() {
  return;
}

size_t FakeSerial::write( char buf[], size_t size ) {
  using namespace std;

  cout << "Serial::write: ";
  cout << buf << "\n";

  return size;
}

void FakeSerial::print(char buf[]){
    std::cout << "Serial::print: " << buf << "\n";
}

FakeSerial Serial;
#endif