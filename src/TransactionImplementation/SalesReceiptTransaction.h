/* 
 * File:   SalesReceiptTransaction.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 1:10
 */

#ifndef SALESRECEIPTTRANSACTION_H
#define	SALESRECEIPTTRANSACTION_H

#include "Transaction.h"
#include "Date.h"

class SalesReceiptTransaction : public Transaction
{
public:
    SalesReceiptTransaction( const Date &date, double amount, int empId );
    
    void Execute();
    
private:
    Date m_date;
    double m_amount;
    int m_empid;
};

#endif	/* SALESRECEIPTTRANSACTION_H */

