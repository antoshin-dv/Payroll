/* 
 * File:   AddSalariedEmployee.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:43
 */

#ifndef ADDSALARIEDEMPLOYEE_H
#define	ADDSALARIEDEMPLOYEE_H

#include "AddEmployeeTransaction.h"

class AddSalariedEmployee : public AddEmployeeTransaction 
{
public:
    explicit AddSalariedEmployee( int id, const std::string &name, 
            const std::string &address, double salary );
    
protected:
    PaymentClassification *MakeClassification();
    PaymentSchedule *MakeSchedule();
	PaymentMethod *MakeMethod();

    
private:
    double m_salary;
};

#endif	/* ADDSALARIEDEMPLOYEE_H */

