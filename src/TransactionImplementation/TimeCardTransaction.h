#ifndef TIME_CARD_TRANSACTION_H
#define	TIME_CARD_TRANSACTION_H

#include "Transaction.h"
#include "Date.h"

class TimeCardTransaction : public Transaction
{
public:
    TimeCardTransaction(const Date &date, double hours, int empId);
    
    void Execute() override;

private:
    const Date m_date;
    const double m_hours;
    const int m_empid;
};

#endif	/* TIME_CARD_TRANSACTION_H */

