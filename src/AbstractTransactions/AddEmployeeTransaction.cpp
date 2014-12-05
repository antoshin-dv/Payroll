/* 
 * File:   AddEmployeeTransaction.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 19:04
 */

#include "AddEmployeeTransaction.h"
#include "Employee.h"
#include "PayrollDatabase.h"

AddEmployeeTransaction::AddEmployeeTransaction( int empid, const std::string &name, 
            const std::string &address) : m_empid( empid ), m_name( name ), m_address( address )
{
}

void AddEmployeeTransaction::Execute()
{
    PaymentClassification *pc = MakeClassification();
    PaymentSchedule *ps = MakeSchedule();
	PaymentMethod *pm = MakeMethod();
    
    Employee* e = new Employee(m_empid, m_name, m_address);
    e->setClassification(pc);
    e->setSchedule(ps);
    e->setMethod(pm);
    PayrollDatabase::instance().AddEmployee(m_empid, e);
}
