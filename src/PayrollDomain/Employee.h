/* 
 * File:   Employee.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:18
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include "PaymentMethod.h"
#include <string>

#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include "Affiliation.h"
#include "Date.h"
#include "Paycheck.h"

class Employee {
public:
/*	Employee();*/
    Employee( int empid, const std::string &name, const std::string &address );
// 	Employee(const Employee& e);
// 	Employee& operator=(const Employee& other);
    ~Employee();

    void setName( const std::string &name ) { m_name = name; }
    const std::string &getName() const { return m_name; }
    
    void setAddress( const std::string &address ) { m_address = address; }
    const std::string &getAddress() const { return m_address; }
    
    void setClassification( PaymentClassification *classification );
    PaymentClassification *getClassification() const { return m_classification; }
    
    void setSchedule( PaymentSchedule *schedule );
    PaymentSchedule *getSchedule() const { return m_schedule; }
    
    void setMethod( PaymentMethod *method );
    PaymentMethod *getMethod() const { return m_method; }
    
    void setAffiliation( Affiliation *affiliation );
    Affiliation *getAffiliation() const { return m_affiliation; }
    
    bool IsPayDate( const Date &date ) const { return m_schedule->IsPayDate( date ); }
    
    Date GetPayPeriodStartDate( const Date &date ) const { return m_schedule->GetPayPeriodStartDate( date ); }
    
    void Payday( Paycheck *paycheck );
    
private:
	Employee(const Employee&);
	Employee& operator=(const Employee&);

    int m_empid;
    std::string m_name;
    std::string m_address;
    
    PaymentClassification *m_classification;
    PaymentSchedule *m_schedule;
    PaymentMethod *m_method;
    Affiliation *m_affiliation;
};

#endif	/* EMPLOYEE_H */

