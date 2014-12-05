/* 
 * File:   DeleteEmployeeTransaction.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 22:14
 */

#ifndef DELETEEMPLOYEETRANSACTION_H
#define	DELETEEMPLOYEETRANSACTION_H

#include "Transaction.h"


class DeleteEmployeeTransaction : public Transaction
{
public:
    DeleteEmployeeTransaction( int id );
    
    void Execute();


private:
    int m_id;
};

#endif	/* DELETEEMPLOYEETRANSACTION_H */

