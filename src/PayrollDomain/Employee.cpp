/* 
 * File:   Employee.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 19:18
 */

#include "Employee.h"
#include "NoAffiliation.h"
#include <iostream>

// Employee::Employee() : m_empid(-1), m_name(""), m_address(""),
// m_classification(nullptr), m_schedule(nullptr), m_method(nullptr), m_affiliation(nullptr)
// {
// 	std::cout << "Empty construct" << std::endl;
// }

Employee::Employee( int empid, const std::string &name, const std::string &address)
    : m_empid( empid ), m_name( name ), m_address( address ),
		m_classification(nullptr), m_schedule(nullptr), m_method(nullptr)
{
    m_affiliation = new NoAffiliation();
}

// Employee::Employee(const Employee& e)
// {
// 	std::cout << "Copy construct" << std::endl;
// }
// 
// Employee& Employee::operator=(const Employee& other)
// {
// 	std::cout << "Operator =" << std::endl;
// 	if (this != &other)
// 	{
// 		m_empid = other.m_empid;
// 		m_name = other.m_name;
// 		m_address = other.m_address;
// 	}
// 	return *this;
// }

Employee::~Employee() 
{
    delete m_classification;
    delete m_schedule;
    delete m_method;
    delete m_affiliation;
}

void Employee::setClassification( PaymentClassification *classification )
{
    delete m_classification;
    m_classification = classification;
}

void Employee::setSchedule( PaymentSchedule *schedule )
{
    delete m_schedule;
    m_schedule = schedule;
}

void Employee::setMethod( PaymentMethod *method )
{
    delete m_method;
    m_method = method;
}

void Employee::setAffiliation( Affiliation *affiliation )
{
    delete m_affiliation;
    m_affiliation = affiliation;
}

void Employee::Payday( Paycheck *paycheck )
{
    double grossPay = m_classification->CalculatePay( paycheck );
    double deducation = m_affiliation->CalculateDeductions( paycheck );
    double netPay = grossPay - deducation;
    
    paycheck->setGrossPay( grossPay );
    paycheck->setDeductions( deducation );
    paycheck->setNetPay( netPay );
    
    m_method->Pay( paycheck );
}
