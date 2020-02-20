#ifdef TEST_FOR_MISSING_FILE
#warning Compiling without GRPC C++ headers!
#else
#define TEST_FOR_MISSING_FILE
#include <rpc/chess_service.grpc.pb.h>
#endif
