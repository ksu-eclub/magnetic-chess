#ifdef TEST_FOR_MISSING_FILE
#warning Compiling without GRPC C++ headers!
#ifndef NO_GRPC
#define NO_GRPC
#endif
#else
#define TEST_FOR_MISSING_FILE
#include <rpc/chess_service.grpc.pb.h>
#endif
