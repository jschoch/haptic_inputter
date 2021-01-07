#pragma once

#ifdef UNIT_TEST

#include <iostream>

class FakeSerial {
public:
  void begin(unsigned long);
  void end();
  size_t write(char*, size_t);
  void print(char[]);
};

extern FakeSerial Serial;
#endif