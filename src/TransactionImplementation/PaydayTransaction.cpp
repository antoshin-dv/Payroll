#include "PaydayTransaction.h"
#include "PayrollDatabase.h"
#include "Paycheck.h"

PaydayTransaction::PaydayTransaction(const Date &date) : m_payDate(date)
{} 

void PaydayTransaction::Execute()
{
    std::vector<int> empIds;
    PayrollDatabase::instance().GetAllEmployeeIds(empIds);
    
    for( int empId : empIds )
    {
        std::shared_ptr<Employee> employee = PayrollDatabase::instance().GetEmployee(empId);
        if (employee == nullptr)
            throw std::logic_error( "Employee = NULL" );
        
        if (employee->IsPayDate( m_payDate ))
        {
            Date startDate = employee->GetPayPeriodStartDate( m_payDate );
            Paycheck *pc = new Paycheck(startDate, m_payDate);
            m_paychecks[empId] = std::shared_ptr<Paycheck>(pc);
            employee->Payday(pc);
        }
    }
}

std::shared_ptr<Paycheck> PaydayTransaction::GetPaycheck(int empId) 
{
    return m_paychecks[empId];
}


