/* 
 * File:   AddHourlyEmployee.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 21:30
 */

#ifndef ADDHOURLYEMPLOYEE_H
#define	ADDHOURLYEMPLOYEE_H

#include "AddEmployeeTransaction.h"


class AddHourlyEmployee : public AddEmployeeTransaction
{
public:
    AddHourlyEmployee( int id, const std::string &name, const std::string &address, double hourly );
    
    PaymentClassification *MakeClassification();

    PaymentSchedule *MakeSchedule();

	PaymentMethod *MakeMethod();
    
private:
    double m_hourly;
};

#endif	/* ADDHOURLYEMPLOYEE_H */

