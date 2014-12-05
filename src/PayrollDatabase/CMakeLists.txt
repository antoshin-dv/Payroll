file(GLOB Database_SRC *.cpp)
file(GLOB Database_HDR *.h)

include_directories(${PAYROLL_SOURCE_DIR}/PayrollDomain)
add_library(PayrollDatabase STATIC ${Database_SRC} ${Database_HDR})
target_link_libraries(PayrollDatabase PayrollDomain)