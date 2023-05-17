
#include <stdio.h>
#include<string.h>

#include "server.h"
#include <stdlib.h>



ST_accountsDB_t accountsDB[255] = { {5000.0,RUNNING,"5181975718047403"},{25000.0,RUNNING,"670676038979126821"},{20000.0,RUNNING,"4916895977496056"},{450000.0,BLOCKED,"5477754834149242"} ,{ 6900.0, BLOCKED, "6304219447607087665" },{ 70000.0, BLOCKED, "5235820631826041831" } };

ST_accountsDB_t* accountsDB_pt = &accountsDB;


int account_index;   // needed for that postion of account in database
int missing;     // flag needed for that account is data base                                 missing = 1(not in database)        not missing  =0(it is in database)
int blocked;    // flag needed for account to check if it is blocked or no                    blocked = 1(blocked in data base)    not blocked =0(not blocked in database)
int ava;      // flag needed for account  to check if it has enough money in account           ava = 1  avabile money              ava = 0   no avabile money
int trans_seq = 1;
int i1;
ST_transaction_t transcationsDB[255] = { 0 };
ST_transaction_t* transcationsDB_pt = &transcationsDB;


EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) {
	EN_serverError_t stat_is_valid_account;

	for (i1 = 0; i1 < 255; i1++) {

		if (strcmp(cardData->primaryAccountNumber, accountRefrence[i1].primaryAccountNumber) == 0) {
			//printf("pan is %s\n", accountRefrence[i1].primaryAccountNumber);
			stat_is_valid_account = SERVER_OK;
			char is_valid_account_error[20] = "SERVER_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isValidAccount\n");
			printf("Test Case 1 : account is found  \n");
			printf("Input Data : the Pan that was inserted %s and reference of account is %p \n", cardData->primaryAccountNumber, &accountRefrence[i1].primaryAccountNumber);
			printf("Expected Result:SERVER_OK \n");
			printf("Actual Result: % s \n", is_valid_account_error);
			account_index = i1;
			missing = 0;
			return stat_is_valid_account;
		}
	}
	if (i1 == 255) {
		missing = 1;
		//printf("pan is %s\n", accountRefrence[i1].primaryAccountNumber);
		stat_is_valid_account = ACCOUNT_NOT_FOUND;
		char is_valid_account_error[20] = "ACCOUNT_NOT_FOUND";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:isValidAccount\n");
		printf("Test Case 2 : account not found in  database \n");
		printf("Input Data : the Pan that was inserted %s and reference of account is %s \n", cardData->primaryAccountNumber, "NULL");
		printf("Expected Result: ACCOUNT_NOT_FOUND \n");
		printf("Actual Result: % s \n", is_valid_account_error);
		return stat_is_valid_account;

	}
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {
	EN_serverError_t stat_is_blocked_account;
	if (missing == 1) {
		return 0;
	}
	if (missing == 0) {
		if (accountRefrence[account_index].state == RUNNING) {
			blocked = 0;
			stat_is_blocked_account = SERVER_OK;
			char is_blocked_account_error[20] = "SERVER_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isBlockedAccount\n");
			printf("Test Case 1 : account is Running  \n");
			printf("Expected Result:SERVER_OK \n");
			printf("Actual Result: % s \n", is_blocked_account_error);
			return stat_is_blocked_account;
		}
		else {
			blocked = 1;
			stat_is_blocked_account = BLOCKED_ACCOUNT;
			char is_blocked_account_error[20] = "BLOCKED_ACCOUNT";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isBlockedAccount\n");
			printf("Test Case 2 : account is blocked  \n");
			printf("Expected Result:BLOCKED_ACCOUNT \n");
			printf("Actual Result: % s \n", is_blocked_account_error);
			return stat_is_blocked_account;
		}
	}
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {
	EN_serverError_t stat_is_amount_available;
	if (missing == 1) {
		return 0;
	}
	if (blocked == 0) {
		if (accountRefrence[account_index].balance > termData->transAmount) {
			ava = 1;
			stat_is_amount_available = SERVER_OK;
			char is_amount_available_error[20] = "SERVER_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isAmountAvailable\n");
			printf("Test Case 1 : Account can Cover the transcation amount  \n");
			printf("Input Data: Account has money %f and the transcation amount is %f \n", accountRefrence[account_index].balance, termData->transAmount);
			printf("Expected Result:SERVER_OK \n");
			printf("Actual Result: % s \n", is_amount_available_error);
			return stat_is_amount_available;
		}
		else if (accountRefrence[account_index].balance < termData->transAmount) {
			ava = 0;
			stat_is_amount_available = LOW_BALANCE;
			char is_amount_available_error[20] = "LOW_BALANCE";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isAmountAvailable\n");
			printf("Test Case 2 : Account cant Cover the transcation amount  \n");
			printf("Input Data: Account has money %f and the transcation amount is %f \n", accountRefrence[account_index].balance, termData->transAmount);
			printf("Expected Result:LOW_BALANCE \n");
			printf("Actual Result: % s \n", is_amount_available_error);
			return stat_is_amount_available;
		}
	}
}

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {

	EN_serverError_t stat_recieve_transaction_data;
	if (missing == 1) {
		stat_recieve_transaction_data = FRAUD_CARD;
		char recieve_transaction_data_error[20] = "FRAUD_CARD";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:recieveTransactionData\n");
		printf("Test Case 1 : Card is Fraud\n");
		printf("Expected Result:FRAUD_CARD \n");
		printf("Actual Result: % s \n", recieve_transaction_data_error);
		printf("\n");
		transcationsDB[2].transState = stat_recieve_transaction_data;
		printf("num is fraud card %d", transcationsDB[2].transState);
		saveTransaction(&transData);

		//
		//trans_seq++;
		return stat_recieve_transaction_data;
	}
	else if (missing == 0 && ava == 0 && blocked == 0) {
		stat_recieve_transaction_data = DECLINED_INSUFFECIENT_FUND;
		char recieve_transaction_data_error[30] = "DECLINED_INSUFFECIENT_FUND";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:recieveTransactionData\n");
		printf("Test Case 2 : transaction failed no enough money\n");
		printf("Expected Result:DECLINED_INSUFFECIENT_FUND \n");
		printf("Actual Result: % s \n", recieve_transaction_data_error);
		printf("\n");
		transcationsDB[2].transState = stat_recieve_transaction_data;
		printf("num is decline insuff  card expecting 1 : %d", transcationsDB[2].transState);
		saveTransaction(&transData);


		return stat_recieve_transaction_data;
	}
	else if (missing == 0 && blocked == 1) {
		stat_recieve_transaction_data = DECLINED_STOLEN_CARD;
		char recieve_transaction_data_error[30] = "DECLINED_STOLEN_CARD";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:recieveTransactionData\n");
		printf("Test Case 3 : transaction failed as account is blocked \n");
		printf("Expected Result:DECLINED_STOLEN_CARD \n");
		printf("Actual Result: % s \n", recieve_transaction_data_error);
		printf("\n");
		transcationsDB[2].transState = stat_recieve_transaction_data;
		printf("num is decline stolen  card expecting 2 : %d", transcationsDB[2].transState);
		saveTransaction(&transData);


		return stat_recieve_transaction_data;
	}
	else if (ava == 1) {
		stat_recieve_transaction_data = APPROVED;
		char recieve_transaction_data_error[30] = "APPROVED";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:recieveTransactionData\n");
		printf("Test Case 4 : Transaction is Recieved  \n");
		printf("Expected Result:APPROVED \n");
		printf("Actual Result: % s \n", recieve_transaction_data_error);
		printf("balance of transaction is  %f\n", terminal_pt->transAmount);
		printf("balance before minus %f\n", accountsDB_pt[i1].balance);
		accountsDB_pt[i1].balance = accountsDB_pt[i1].balance - terminal_pt->transAmount;
		printf("balance after minus %f\n", accountsDB_pt[i1].balance);
		printf("\n");

		transcationsDB[2].transState = stat_recieve_transaction_data;
		printf("num is aprroved card expecting 0 : %d", transcationsDB[2].transState);
		saveTransaction(&transData);


		return stat_recieve_transaction_data;
	}
	//saveTransaction(terminal_pt2);
	//trans_seq++;

}

EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	EN_serverError_t stat_save_transaction = SERVER_OK;
	char save_transaction_error[30] = "SERVER_OK";

	strcpy_s(transcationsDB[0].cardHolderData.cardHolderName, 25, card_pt->cardHolderName);
	strcpy_s(transcationsDB[0].cardHolderData.cardExpirationDate, 6, card_pt->cardExpirationDate);
	strcpy_s(transcationsDB[0].cardHolderData.primaryAccountNumber, 20, card_pt->primaryAccountNumber);
	strcpy_s(transcationsDB[0].terminalData.transactionDate, 11, terminal_pt->transactionDate);

	transcationsDB[1].terminalData.transAmount = terminal_pt->transAmount;
	transcationsDB[1].terminalData.maxTransAmount = terminal_pt->maxTransAmount;



	//printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
	//printf("Function Name:saveTransaction\n");
	//printf("Test Case  : Transaction is saved  \n");
	//printf("Expected Result:SERVER_OK \n");
	//printf("Actual Result: % s \n", save_transaction_error);
	return stat_save_transaction;
}
void listSavedTransactions(void) {
	if (trans_seq <= 255) {
		printf("#########################\n");
		printf("Transaction Sequence Number:%d \n", trans_seq);
		printf("Transaction Date:%s\n", transcationsDB[0].terminalData.transactionDate);
		printf("Transaction Amount:%f\n", transcationsDB[1].terminalData.transAmount);
		if (transcationsDB[2].transState == APPROVED) {
			printf("Transaction State:APPROVED\n");
		}
		else if (transcationsDB[2].transState == DECLINED_INSUFFECIENT_FUND) {
			printf("Transaction State:DECLINED_INSUFFECIENT_FUND\n");
		}
		else if (transcationsDB[2].transState == DECLINED_STOLEN_CARD) {
			printf("Transaction State:DECLINED_STOLEN_CARD\n");
		}
		else if (transcationsDB[2].transState == FRAUD_CARD) {
			printf("Transaction State:FRAUD_CARD\n");
		}
		else if (transcationsDB[2].transState == INTERNAL_SERVER_ERROR) {
			printf("Transaction State:INTERNAL_SERVER_ERROR\n");
		}

		printf("Terminal Max Amount:%f\n", transcationsDB[1].terminalData.maxTransAmount);
		printf("Cardholder Name:%s\n", transcationsDB[0].cardHolderData.cardHolderName);
		printf("PAN:%s\n", transcationsDB[0].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date:%s\n", transcationsDB[0].cardHolderData.cardExpirationDate);
		printf("#########################\n");
		trans_seq++;
	}
	

	if (trans_seq > 255) {
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:listSavedTransactions\n");
		printf("Test Case  : transcations number are above 255 \n");
		
		
	}

}
void update_balance(ST_transaction_t* transData, int index, ST_accountsDB_t* accountRefrence) {

}

void update_balance(ST_transaction_t* transData, int index, ST_accountsDB_t* accountRefrence);// helper fucntion that update balance
void isValidAccountTest(void);
void isBlockedAccountTest(void);
void isAmountAvailableTest(void);
void recieveTransactionDataTest(void);


/*int main() {
	while (1) {
		recieveTransactionDataTest();
		saveTransaction(transcationsDB_pt);
		listSavedTransactions();
		
	}
		
}*/
void isValidAccountTest(void) {
	isValidAccount(card_pt, accountsDB_pt);
}

void isBlockedAccountTest(void) {
	isBlockedAccount(accountsDB_pt);
}
void isAmountAvailableTest(void) {
	isAmountAvailable(terminal_pt, accountsDB_pt);
}
void recieveTransactionDataTest(void) {
	//recieveTransactionData(transaction_pt);
}