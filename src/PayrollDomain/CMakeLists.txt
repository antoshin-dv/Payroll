file(GLOB Domain_SRC *.cpp)
file(GLOB Domain_HDR *.h)

add_library(PayrollDomain ${Domain_SRC} ${Domain_HDR})