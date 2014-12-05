/* 
 * File:   SalesReceipt.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 0:55
 */

#ifndef SALESRECEIPT_H
#define	SALESRECEIPT_H

#include "Date.h"

class SalesReceipt {
public:
    SalesReceipt( const Date &date, double amount );
    
    double getAmount() const { return m_amount; }
    Date getDate() const { return m_date; }
    
private:
    Date m_date;
    double m_amount;
};

#endif	/* SALESRECEIPT_H */

