
#ifndef SERVER
#define SERVER
#include "../terminal/terminal.h"
#include "../card/card.h"

typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
} EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence);
EN_serverError_t saveTransaction(ST_transaction_t* transData);

void listSavedTransactions(void);
extern ST_accountsDB_t* accountsDB_pt;
extern ST_transaction_t* transcationsDB_pt;

#endif        

// first account balance is 2000 le  and running account and pan is 16 number and will be pass luhn check   [Transaction approved user story]
// second  account balance is 35K le  and running account and pan is 18 number and it will pass luhn check [Exceed the maximum amount user story]
 // thrid account balance is 0 le  and running account and pan is 16 number and will be pass luhn check   [Insufficient fund user story]
//fourth account balance is 450K le  and blocked account and pan is 16 number and will pass luhn check    [Expired card user story]
// fifth account balance is 6900 le  and blocked account and pan is 19 number and  will be pass luhn check [Stolen card user story]
// sixth account balance is 70000 le and it is 19 number but  it is  blocked due to   it is fraud card and will fail luhn check  [Fraud user story]       
