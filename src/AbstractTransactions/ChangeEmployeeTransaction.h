#ifndef CHANGE_EMPLOYEE_TRANSACTION_H
#define	CHANGE_EMPLOYEE_TRANSACTION_H

#include "Transaction.h"
#include <memory>

class Employee;

class ChangeEmployeeTransaction : public Transaction
{
public:
    ChangeEmployeeTransaction( int id );
    
    void Execute() override;
    
protected:
	typedef std::shared_ptr<Employee> TEmployee;
	virtual void Change(TEmployee e) = 0;
    
private:
    const int m_empId;
};

#endif	/* CHANGE_EMPLOYEE_TRANSACTION_H */

