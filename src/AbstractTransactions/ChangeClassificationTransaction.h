#ifndef CHANGE_CLASSIFICATION_TRANSACTION_H
#define	CHANGE_CLASSIFICATION_TRANSACTION_H

#include "ChangeEmployeeTransaction.h"

class PaymentClassification;
class PaymentSchedule;

class ChangeClassificationTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeClassificationTransaction(int id);
    
protected:
    void Change(TEmployee e) override;
    
    virtual PaymentClassification *getClassification() = 0;
    virtual PaymentSchedule *getSchedule() = 0;

};

#endif	/* CHANGE_CLASSIFICATION_TRANSACTION_H */

