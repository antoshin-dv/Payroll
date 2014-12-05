file(GLOB PayrollImpl_SRC *.cpp)

file(GLOB PayrollImpl_HDR *.h)

include_directories(${PAYROLL_SOURCE_DIR}/PayrollDomain)

add_library(PayrollImplementation ${PayrollImpl_SRC} ${PayrollImpl_HDR})
target_link_libraries(PayrollImplementation PayrollDomain)
