/* 
 * File:   PaymentSchedule.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:36
 */

#ifndef PAYMENTSCHEDULE_H
#define	PAYMENTSCHEDULE_H

#include "Date.h"

class PaymentSchedule {
public:
    virtual ~PaymentSchedule() {};
    
    virtual bool IsPayDate( const Date &date ) const = 0;
    virtual Date GetPayPeriodStartDate( const Date &date ) = 0;
private:

};

#endif	/* PAYMENTSCHEDULE_H */

