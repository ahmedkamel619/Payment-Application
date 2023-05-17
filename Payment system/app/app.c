#include "app.h"


// we created these variables so we check on them in IF's or While 

EN_cardError_t card_name_error;              // enum that will hold getCardHolderName  returned enum  
EN_cardError_t card_expirydate_error;       // enum that will hold getCardExpiryDate  returned enum 
EN_cardError_t card_pan_error;             // enum that will hold getCardPAN  returned enum 




EN_terminalError_t  iscard_expired_error;                    // enum that will hold isCardExpired  returned enum
EN_terminalError_t  setMaxAmount_error;                     // enum that will hold setMaxAmount  returned enum
EN_terminalError_t  getTransactionAmount_error;            // enum that will hold getTransactionAmount  returned enum 
EN_terminalError_t  isbelow_error;                        // enum that will hold isBelowMaxAmount  returned enum

//ST_transaction_t transaction;
//ST_transaction_t* transaction_pt = &transaction;





int main()
{
	while (1) {
		appStart();
	}
}

void appStart(void) {
	printf("------------------User Information Display--------------\n");
	card_name_error = getCardHolderName(card_pt);   // get name from user
	printf("\n");
	while (card_name_error == WRONG_NAME) {         // this while will be on if user inserted the name wrong 
		printf("The Inserted Name is Wrong\n");
		printf("please enter the name again.\n");
		printf("\n");
		card_name_error = getCardHolderName(card_pt);
		printf("\n");
	}

	card_expirydate_error = getCardExpiryDate(card_pt);     // get Expiry date from user
	printf("\n");
	getTransactionDate(terminal_pt);
	printf("\n");
	while (card_expirydate_error == WRONG_EXP_DATE) {     // this while will be on if user inserted the date wrong  
		printf("Wrong date Format pls write the date in form of MM/YY \n");

	}
	iscard_expired_error = isCardExpired(card_pt, terminal_pt);
	printf("\n");

	if (iscard_expired_error == EXPIRED_CARD) {
		printf("you card is Expired Transaction failed \n");
		return;
	}

	card_pan_error = getCardPAN(card_pt);               // get PAN from user
	while (card_pan_error == WRONG_PAN) {               // this while will be on if user inserted the pan wrong
		printf("WRONG_PAN  Please enter the Pan again. it is number in range of 16 to 19 digits \n");
		printf("\n");
		card_pan_error = getCardPAN(card_pt);
		printf("\n");

	}
	printf("----------------------------------------------------------\n");

	printf("------------------Transaction Information Display--------------\n");

	setMaxAmount_error = setMaxAmount(terminal_pt, 30000.0);
	while (setMaxAmount_error == INVALID_MAX_AMOUNT)
	{
		printf("sorry Please enter a valid max amount of transaction again \n");
		setMaxAmount_error = setMaxAmount(terminal_pt, 30000.0);
		printf("\n");
	}

	printf("please enter the transaction amount \n");
	getTransactionAmount_error = getTransactionAmount(terminal_pt);
	printf("\n");

	while (getTransactionAmount_error == INVALID_AMOUNT)
	{
		printf("sorry Please enter a valid  transaction amount  again \n");
		printf("\n");
		getTransactionAmount_error = getTransactionAmount(terminal_pt);
		printf("\n");


	}
	isbelow_error = isBelowMaxAmount(terminal_pt);
	if (isbelow_error == EXCEED_MAX_AMOUNT) {
		printf("Sorry your transaction exceed the max transaction amount  Transaction failed \n");

		return;
	}

	printf("------------------------------------------\n");
	isValidAccount(card_pt, accountsDB_pt);
	printf("\n");
	isBlockedAccount(accountsDB_pt);
	printf("\n");
	isAmountAvailable(terminal_pt, accountsDB_pt);
	printf("\n");
	recieveTransactionData(transcationsDB_pt);
	printf("\n");
	listSavedTransactions();
}