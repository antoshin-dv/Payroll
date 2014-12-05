cmake_minimum_required(VERSION 2.8)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${PAYROLL_SOURCE_DIR}/PayrollDomain)
include_directories(${PAYROLL_SOURCE_DIR}/PayrollDatabase)
include_directories(${PAYROLL_SOURCE_DIR}/PayrollImplementation)
include_directories(${PAYROLL_SOURCE_DIR}/AbstractTransactions)
include_directories(${PAYROLL_SOURCE_DIR}/TransactionApplication)
include_directories(${PAYROLL_SOURCE_DIR}/TransactionImplementation)
include_directories(${Boost_INCLUDE_DIRS})

file(GLOB TESTS_SRC *.cpp)
add_executable(tests ${TESTS_SRC})
target_link_libraries(tests ${Boost_LIBRARIES} 
	PayrollDomain 
	PayrollDatabase
	PayrollImplementation
	AbstractTransactions
	TransactionApplication
	TransactionImplementation
)

add_test(Test1 tests)