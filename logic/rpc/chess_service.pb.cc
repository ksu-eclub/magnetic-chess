#ifdef TEST_FOR_MISSING_FILE
#warning Compiling without ProtoBuf C++ bindings!
#else
#define TEST_FOR_MISSING_FILE
#include <rpc/chess_service.pb.cc>
#endif
