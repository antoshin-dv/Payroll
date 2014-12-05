/* 
 * File:   Transaction.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 0:28
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

class Transaction {
public:
    virtual ~Transaction();
    
    virtual void Execute() = 0;
};

#endif	/* TRANSACTION_H */

