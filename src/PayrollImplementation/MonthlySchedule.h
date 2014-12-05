/* 
 * File:   MonthlySchedule.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:57
 */

#ifndef MONTHLYSCHEDULE_H
#define	MONTHLYSCHEDULE_H

#include "PaymentSchedule.h"

class MonthlySchedule : public PaymentSchedule
{
public:
    MonthlySchedule();
    
    bool IsPayDate( const Date &date ) const override;
    
    Date GetPayPeriodStartDate(const Date& date) override;
};

#endif	/* MONTHLYSCHEDULE_H */

