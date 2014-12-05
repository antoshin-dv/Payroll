file(GLOB TransactionImpl_SRC *.cpp)
file(GLOB TransactionImpl_HDR *.h)

include_directories(${PAYROLL_SOURCE_DIR}/PayrollDomain)
include_directories(${PAYROLL_SOURCE_DIR}/PayrollDatabase)
include_directories(${PAYROLL_SOURCE_DIR}/PayrollImplementation)
include_directories(${PAYROLL_SOURCE_DIR}/TransactionApplication)
include_directories(${PAYROLL_SOURCE_DIR}/AbstractTransactions)

add_library(TransactionImplementation ${TransactionImpl_SRC} ${TransactionImpl_HDR})
target_link_libraries(TransactionImplementation PayrollDomain PayrollDatabase PayrollImplementation AbstractTransactions)