file(GLOB AbstractTransactions_SRC *.cpp)
file(GLOB AbstractTransactions_HDR *.h)

include_directories(${PAYROLL_SOURCE_DIR}/TransactionApplication)
include_directories(${PAYROLL_SOURCE_DIR}/PayrollDatabase)
include_directories(${PAYROLL_SOURCE_DIR}/PayrollDomain)
add_library(AbstractTransactions STATIC ${AbstractTransactions_SRC} ${AbstractTransactions_HDR})
target_link_libraries(AbstractTransactions TransactionApplication PayrollDomain PayrollDatabase)