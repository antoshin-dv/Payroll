#ifndef CHANGE_HOURLY_TRANSACTION_H
#define	CHANGE_HOURLY_TRANSACTION_H

#include "ChangeClassificationTransaction.h"


class ChangeHourlyTransaction : public ChangeClassificationTransaction
{
public:
    ChangeHourlyTransaction(int id, double hourlyRate);
    
protected:
    PaymentClassification *getClassification();
    PaymentSchedule *getSchedule();
    
private:
    const double m_hourlyRate;
};

#endif	/* CHANGE_HOURLY_TRANSACTION_H */

