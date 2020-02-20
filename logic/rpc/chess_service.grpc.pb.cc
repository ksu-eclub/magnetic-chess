#ifdef TEST_FOR_MISSING_FILE
#warning Compiling without GRPC C++ bindings!
#else
#define TEST_FOR_MISSING_FILE
#include <rpc/chess_service.grpc.pb.cc>
#endif
