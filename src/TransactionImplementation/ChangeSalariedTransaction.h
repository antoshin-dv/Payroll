#ifndef CHANGE_SALARIED_TRANSACTION_H
#define	CHANGE_SALARIED_TRANSACTION_H

#include "ChangeClassificationTransaction.h"


class ChangeSalariedTransaction : public ChangeClassificationTransaction
{
public:
	ChangeSalariedTransaction(int id, double salary);
    
protected:
    PaymentClassification *getClassification();
    PaymentSchedule *getSchedule();
    
private:
    double m_salary;
};

#endif	/* CHANGE_SALARIED_TRANSACTION_H */

