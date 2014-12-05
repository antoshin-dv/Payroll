/* 
 * File:   BiweeklySchedule.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 21:51
 */

#ifndef BIWEEKLYSCHEDULE_H
#define	BIWEEKLYSCHEDULE_H

#include "PaymentSchedule.h"

class BiweeklySchedule : public PaymentSchedule
{
public:
	BiweeklySchedule() {};
    
    bool IsPayDate( const Date &date ) const override { return false; }
    
    Date GetPayPeriodStartDate(const Date& date) override { return date; }
};

#endif	/* BIWEEKLYSCHEDULE_H */

