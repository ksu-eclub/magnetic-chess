#if AXIS == 1

#define SLAVE_ADDRESS 0x03

#elif AXIS == 2

#define SLAVE_ADDRESS 0x04

#else
#error Please create a new tab "config.h", and in it define AXIS to be either 1 or 2!
#endif
