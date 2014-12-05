#ifndef CHANGE_COMMISSIONED_TRANSACTION_H
#define	CHANGE_COMMISSIONED_TRANSACTION_H

#include "ChangeClassificationTransaction.h"


class ChangeCommissionedTransaction : public ChangeClassificationTransaction
{
public:
	ChangeCommissionedTransaction(int id, double salary, double commissionRate);
    
protected:
    PaymentClassification *getClassification();
    PaymentSchedule *getSchedule();
    
private:
    const double m_salary;
	const double m_commissionRate;
};

#endif	/* CHANGE_COMMISSIONED_TRANSACTION_H */

