file(GLOB TransactionApplication_SRC *.cpp)
file(GLOB TransactionApplication_HDR *.h)

add_library(TransactionApplication ${TransactionApplication_SRC} ${TransactionApplication_HDR})