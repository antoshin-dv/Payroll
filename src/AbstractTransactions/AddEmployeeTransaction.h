/* 
 * File:   AddEmployeeTransaction.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:04
 */

#ifndef ADDEMPLOYEETRANSACTION_H
#define	ADDEMPLOYEETRANSACTION_H

#include <string>
#include "Transaction.h"

class PaymentClassification;
class PaymentSchedule;
class PaymentMethod;

class AddEmployeeTransaction : public Transaction
{
public:
    explicit AddEmployeeTransaction( int empid, const std::string &name, 
            const std::string &address );
    
    void Execute();
    
protected:
    virtual PaymentClassification* MakeClassification() = 0;
    virtual PaymentSchedule* MakeSchedule() = 0;
	virtual PaymentMethod* MakeMethod() = 0;
    
private:
    int m_empid;
    std::string m_name;
    std::string m_address;
};

#endif	/* ADDEMPLOYEETRANSACTION_H */
