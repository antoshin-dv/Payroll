set(Payroll_SRC main.cpp)

add_subdirectory(PayrollDomain)
add_subdirectory(PayrollDatabase)
add_subdirectory(PayrollImplementation)
add_subdirectory(TransactionApplication)
add_subdirectory(AbstractTransactions)
add_subdirectory(TransactionImplementation)


include_directories(PayrollDomain)
include_directories(PayrollDatabase)
include_directories(PayrollImplementation)
include_directories(TransactionImplementation)
include_directories(AbstractTransactions)
include_directories(TransactionApplication)

add_executable(Payroll ${Payroll_SRC})
target_link_libraries(Payroll PayrollDomain PayrollDatabase PayrollImplementation TransactionImplementation AbstractTransactions TransactionApplication)