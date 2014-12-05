/* 
 * File:   AddSalariedEmployee.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 19:43
 */

#include "AddSalariedEmployee.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"
#include "HoldMethod.h"

AddSalariedEmployee::AddSalariedEmployee(
    int id, const std::string &name, const std::string &address, double salary)
    : AddEmployeeTransaction( id, name, address ), m_salary( salary )
{
}

PaymentClassification *AddSalariedEmployee::MakeClassification()
{
	return new SalariedClassification(m_salary);
}

PaymentSchedule *AddSalariedEmployee::MakeSchedule()
{
	return new MonthlySchedule;
}

PaymentMethod * AddSalariedEmployee::MakeMethod()
{
	return new HoldMethod;
}
