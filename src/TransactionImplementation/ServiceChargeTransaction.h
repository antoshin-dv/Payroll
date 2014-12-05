/* 
 * File:   ServiceChargeTransaction.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 10:50
 */

#ifndef SERVICECHARGETRANSACTION_H
#define	SERVICECHARGETRANSACTION_H

#include "Transaction.h"
#include "Date.h"

class ServiceChargeTransaction : public Transaction
{
public:
    ServiceChargeTransaction( int id, const Date &date, double charge );
    
    void Execute();

private:
    int m_memberId;
    Date m_date;
    double m_charge;
};

#endif	/* SERVICECHARGETRANSACTION_H */

