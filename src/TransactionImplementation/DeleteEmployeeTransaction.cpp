/* 
 * File:   DeleteEmployeeTransaction.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 22:14
 */

#include "DeleteEmployeeTransaction.h"
#include "PayrollDatabase.h"

DeleteEmployeeTransaction::DeleteEmployeeTransaction( int id ) : m_id( id ) 
{
}

void DeleteEmployeeTransaction::Execute()
{
    PayrollDatabase::instance().DeleteEmployee( m_id );
}
