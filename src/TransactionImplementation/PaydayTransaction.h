#ifndef PAYDAY_TRANSACTION_H
#define	PAYDAY_TRANSACTION_H

#include "Transaction.h"
#include "Date.h"
#include <map>
#include <memory>

class Paycheck;

class PaydayTransaction : public Transaction
{
public:
    PaydayTransaction(const Date &date);
    
    void Execute() override;
    
    std::shared_ptr<Paycheck> GetPaycheck(int empId);
    
private:
    const Date m_payDate;
    std::map<int, std::shared_ptr<Paycheck> > m_paychecks;
};

#endif	/* PAYDAY_TRANSACTION_H */

