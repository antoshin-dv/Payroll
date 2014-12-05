#ifndef CHANGE_ADDRESS_TRANSACTION_H
#define	CHANGE_ADDRESS_TRANSACTION_H

#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeAddressTransaction : public ChangeEmployeeTransaction
{
public: 
    ChangeAddressTransaction(int id, const std::string &address);
    
protected:
    void Change( TEmployee e ) override;
    
private:
    const std::string m_newAddress;
};

#endif	/* CHANGE_ADDRESS_TRANSACTION_H */

