#include "ChangeEmployeeTransaction.h"
#include "PayrollDatabase.h"

ChangeEmployeeTransaction::ChangeEmployeeTransaction(int id) : m_empId(id)
{
}

void ChangeEmployeeTransaction::Execute()
{
	TEmployee e = PayrollDatabase::instance().GetEmployee(m_empId);
    if ( e == nullptr )
        throw std::logic_error( "Работник не найден" );
    
    Change(e);
}
