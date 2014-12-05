/* 
 * File:   AddCommissionedEmployee.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 21:56
 */

#include "AddCommissionedEmployee.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"
#include "HoldMethod.h"


AddCommissionedEmployee::AddCommissionedEmployee( 
    int id, const std::string &name, const std::string &address, double salary, double commissionRate) 
    : AddEmployeeTransaction( id, name, address ), m_salary( salary ), m_commissionRate( commissionRate )
{
}

PaymentClassification *AddCommissionedEmployee::MakeClassification()
{
    return new CommissionedClassification(m_salary, m_commissionRate);
}

PaymentSchedule *AddCommissionedEmployee::MakeSchedule()
{
	return new BiweeklySchedule;
}

PaymentMethod *AddCommissionedEmployee::MakeMethod()
{
	return new HoldMethod;
}
