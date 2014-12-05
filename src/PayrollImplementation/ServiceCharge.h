/* 
 * File:   ServiceCharge.h
 * Author: denis
 *
 * Created on 26 октября 2014 г., 23:47
 */

#ifndef SERVICECHARGE_H
#define	SERVICECHARGE_H

#include "Date.h"

class ServiceCharge 
{
public:
    ServiceCharge( const Date &date, double amount )
        : m_date( date ), m_amount( amount ) {};
        
    double getAmount() const { return m_amount; }
    Date getDate() { return m_date; }
    
private:
    Date m_date;
    double m_amount;
};

#endif	/* SERVICECHARGE_H */

