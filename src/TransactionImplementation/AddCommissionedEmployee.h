/* 
 * File:   AddCommissionedEmployee.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 21:56
 */

#ifndef ADDCOMMISSIONEDEMPLOYEE_H
#define	ADDCOMMISSIONEDEMPLOYEE_H

#include "AddEmployeeTransaction.h"


class AddCommissionedEmployee : public AddEmployeeTransaction
{
public:
    AddCommissionedEmployee( int id, const std::string &name, const std::string &address, 
            double salary, double commissionRate );
    
protected:
    PaymentClassification *MakeClassification();
    PaymentSchedule *MakeSchedule();
	PaymentMethod *MakeMethod();

private:
    double m_salary;
    double m_commissionRate;
};

#endif	/* ADDCOMMISSIONEDEMPLOYEE_H */

