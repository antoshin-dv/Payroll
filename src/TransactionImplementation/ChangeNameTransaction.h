#ifndef CHANGE_NAME_TRANSACTION_H
#define	CHANGE_NAME_TRANSACTION_H

#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeNameTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeNameTransaction( int id, const std::string &name );
    
protected:
    void Change(TEmployee e);
    
private:
    const std::string m_newName;
};

#endif	/* CHANGE_NAME_TRANSACTION_H */

