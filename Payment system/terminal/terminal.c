#include <stdio.h>
#include<string.h>
#include "terminal.h"
#include <stdlib.h>
#include<conio.h>
#include<time.h>
ST_terminalData_t terminal;
ST_terminalData_t* terminal_pt = &terminal;

getTransactionDate(ST_terminalData_t* termData) {
	EN_terminalError_t stat_trans_date;       // type def enum TransactionDate error [TERMINAL_OK] or [WRONG_DATE]                                    
	time_t rawtime;                           //  here we get the time from the Pc                  
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	int month = 1 + timeinfo.tm_mon;      // we add 1 as Jan starts from defult zero
	int day = timeinfo.tm_mday;
	int year = 1900 + timeinfo.tm_year;    // we add 1900 as year start from 123
	char month_string[3];
	char day_string[3];
	char year_string[5];
	sprintf_s(day_string, 3, "%d", day);  // convert day to string
	sprintf_s(year_string, 5, "%d", year); // convert year to string              
	if (month == 1 || month == 2 || month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9) { // convert month to string
		sprintf_s(month_string, 3, "0%d", month);
	}
	else {
		sprintf_s(month_string, 3, "%d", month);
	}
	if (month == 1 || month == 2 || month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9) {
		char trans_date_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getTransactionDate\n");
		printf("Test Case : date of transaction is right \n");
		printf("Input Data :  %d/",day);
		printf("0%d/", month);
		printf("%d \n", year);
		printf("Expected Result:TERMINAL_OK \n");
		printf("Actual Result: % s \n", trans_date_error);
		stat_trans_date = TERMINAL_OK;
		termData->transactionDate[0] = day_string[0];
		termData->transactionDate[1] = day_string[1];
		termData->transactionDate[2] = '/';
		termData->transactionDate[3] = month_string[0];
		termData->transactionDate[4] = month_string[1];
		termData->transactionDate[5] = '/';
		termData->transactionDate[6] = year_string[0];
		termData->transactionDate[7] = year_string[1];
		termData->transactionDate[8] = year_string[2];
		termData->transactionDate[9] = year_string[3];
		termData->transactionDate[10] = year_string[4];
		//termData->transactionDate[11] = year_string[5];
		return stat_trans_date;
	}
	else {
		char trans_date_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getTransactionDate\n");
		printf("Test Case : date of transaction is right \n");
		printf("Input Data :  %d/", day);
		printf("%d/", month);
		printf("%d \n", year);
		printf("Expected Result:TERMINAL_OK \n");
		printf("Actual Result: % s \n", trans_date_error);
		stat_trans_date = TERMINAL_OK;
		termData->transactionDate[0] = day_string[0];
		termData->transactionDate[1] = day_string[1];
		termData->transactionDate[2] = '/';
		termData->transactionDate[3] = month_string[0];
		termData->transactionDate[4] = month_string[1];
		termData->transactionDate[5] = '/';
		termData->transactionDate[6] = year_string[0];
		termData->transactionDate[7] = year_string[1];
		termData->transactionDate[8] = year_string[2];
		termData->transactionDate[9] = year_string[3];
		termData->transactionDate[10] = year_string[4];
		//termData->transactionDate[11] = year_string[5];
		return stat_trans_date;
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	uint8_t input_trans_amount[100];                                                      // string array that will hold the TransactionAmount which is INPUT BY USER
	float input_trans_amount_f;
	EN_terminalError_t stat_get_transaction_amount;                                   // type def enum TransactionDate error [INVALID_AMOUNT] or [TERMINAL_OK]
	printf(" Enter the Transaction Amount ");
	gets_s(input_trans_amount, 100);
	input_trans_amount_f = atof(input_trans_amount);              // covert string to float
	if (input_trans_amount_f < 0) {
		stat_get_transaction_amount = INVALID_AMOUNT;
		/*char trans_amount_error[20] = "INVALID_AMOUNT";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getTransactionAmount\n");
		printf("Test Case 1 : Transaction amount is below zero \n");
		printf("Input Data :  %f\n", input_trans_amount_f);
		printf("Expected Result:INVALID_AMOUNT \n");
		printf("Actual Result: % s \n", trans_amount_error);*/
		return stat_get_transaction_amount;
	}
	else if (input_trans_amount_f == 0) {
		stat_get_transaction_amount = INVALID_AMOUNT;
		/*char trans_amount_error[20] = "INVALID_AMOUNT";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getTransactionAmount\n");
		printf("Test Case 2 : Transaction amount is  zero \n");
		printf("Input Data :  %f\n", input_trans_amount_f);
		printf("Expected Result:INVALID_AMOUNT \n");
		printf("Actual Result: % s \n", trans_amount_error);*/
		return stat_get_transaction_amount;
	}
	else if (input_trans_amount_f > 0) {
		stat_get_transaction_amount = TERMINAL_OK;
		/*char trans_amount_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getTransactionAmount\n");
		printf("Test Case 3 : Transaction amount is correct \n");
		printf("Input Data :  %f\n", input_trans_amount_f);
		printf("Expected Result:TERMINAL_OK \n");
		printf("Actual Result: % s \n", trans_amount_error);*/
		termData->transAmount = input_trans_amount_f;
		return stat_get_transaction_amount;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
	EN_terminalError_t stat_set_max_amount;                           // type def enum MaxAmount error [INVALID_MAX_AMOUNT] or [TERMINAL_OK]
	if (maxAmount > 0.0) {
		stat_set_max_amount = TERMINAL_OK;
		/*char set_max_amount_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:setMaxAmount\n");
		printf("Test Case 1 : max amount is correct and it is setted \n");
		printf("Input Data :  %f\n", maxAmount);
		printf("Expected Result:TERMINAL_OK \n");
		printf("Actual Result: % s \n", set_max_amount_error);*/
		termData->maxTransAmount = maxAmount;
		return stat_set_max_amount;
	}
	else if (maxAmount < 0.0) {
		stat_set_max_amount = INVALID_MAX_AMOUNT;
		/*char set_max_amount_error[20] = "INVALID_MAX_AMOUNT";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:setMaxAmount\n");
		printf("Test Case 2 : max amount is below zero \n");
		printf("Input Data :  %f\n", maxAmount);
		printf("Expected Result:INVALID_MAX_AMOUNT\n");
		printf("Actual Result: % s \n", set_max_amount_error);*/
		return stat_set_max_amount;
	}
	else if (maxAmount == 0.0) {
		stat_set_max_amount = INVALID_MAX_AMOUNT;
		/*char set_max_amount_error[20] = "INVALID_MAX_AMOUNT";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:setMaxAmount\n");
		printf("Test Case 3 : max amount is  zero \n");
		printf("Input Data :  %f\n", maxAmount);
		printf("Expected Result:INVALID_MAX_AMOUNT\n");
		printf("Actual Result: % s \n", set_max_amount_error);*/
		return stat_set_max_amount;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	EN_terminalError_t stat_is_below_max_amount;                           // type def enum MaxAmount error [EXCEED_MAX_AMOUNT] or [TERMINAL_OK]
	if (termData->transAmount > termData->maxTransAmount) {
		stat_is_below_max_amount = EXCEED_MAX_AMOUNT;
		/*char is_below_max_amount_error[20] = "EXCEED_MAX_AMOUNT";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:isBelowMaxAmount\n");
		printf("Test Case 1 : transcation amount is bigger than max account limit \n");
		printf("Input Data :transcation amount is  %f  and max amount is %f \n", termData->transAmount, termData->maxTransAmount);
		printf("Expected Result:EXCEED_MAX_AMOUNT\n");
		printf("Actual Result: % s \n", is_below_max_amount_error);*/
		return stat_is_below_max_amount;
	}
	else if (termData->transAmount <= termData->maxTransAmount) {
		stat_is_below_max_amount = TERMINAL_OK;
		/*char is_below_max_amount_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:isBelowMaxAmount\n");
		printf("Test Case 2 : transcation amount is smaller than max account limit \n");
		printf("Input Data :transcation amount is  %f  and max amount is %f \n", termData->transAmount, termData->maxTransAmount);
		printf("Expected Result:TERMINAL_OK\n");
		printf("Actual Result: % s \n", is_below_max_amount_error); */
		return stat_is_below_max_amount;
	}


}
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
	EN_terminalError_t stat_is_card_expired;
	if (cardData->cardExpirationDate[3] < termData->transactionDate[8]) {
		stat_is_card_expired = EXPIRED_CARD;
		/*char is_card_expired_error[20] = "EXPIRED_CARD";
		 printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		 printf("Function Name:isCardExpired\n");
		 printf("Test Case 1 : Card is expired \n");
		 printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
		 printf("Expected Result:EXPIRED_CARD\n");
		 printf("Actual Result: % s \n", is_card_expired_error);*/
		return stat_is_card_expired;
	}
	if ((cardData->cardExpirationDate[3] == termData->transactionDate[8]) && (cardData->cardExpirationDate[4] < termData->transactionDate[9])) {
		stat_is_card_expired = EXPIRED_CARD;
		/*char is_card_expired_error[20] = "EXPIRED_CARD";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:isCardExpired\n");
		printf("Test Case 1 : Card is expired \n");
		printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
		printf("Expected Result:EXPIRED_CARD\n");
		printf("Actual Result: % s \n", is_card_expired_error);*/
		return stat_is_card_expired;
	}
	if ((cardData->cardExpirationDate[3] == termData->transactionDate[8]) && (cardData->cardExpirationDate[4] > termData->transactionDate[9])) {
		stat_is_card_expired = TERMINAL_OK;
		/*char is_card_expired_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:isCardExpired\n");
		printf("Test Case 2 : Card is valid \n");
		printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
		printf("Expected Result:TERMINAL_OK\n");
		printf("Actual Result: % s \n", is_card_expired_error);*/
		return stat_is_card_expired;

	}
	if (cardData->cardExpirationDate[3] > termData->transactionDate[8]) {
		stat_is_card_expired = TERMINAL_OK;
		/*char is_card_expired_error[20] = "TERMINAL_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:isCardExpired\n");
		printf("Test Case 2 : Card is valid \n");
		printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
		printf("Expected Result:TERMINAL_OK\n");
		printf("Actual Result: % s \n", is_card_expired_error);*/
		return stat_is_card_expired;
	}
	if ((cardData->cardExpirationDate[3] == termData->transactionDate[8]) && (cardData->cardExpirationDate[4] == termData->transactionDate[9])) {
		if (cardData->cardExpirationDate[0] > termData->transactionDate[3]) {
			stat_is_card_expired = TERMINAL_OK;
			/*char is_card_expired_error[20] = "TERMINAL_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isCardExpired\n");
			printf("Test Case 2 : Card is valid \n");
			printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
			printf("Expected Result:TERMINAL_OK\n");
			printf("Actual Result: % s \n", is_card_expired_error);*/
			return stat_is_card_expired;
		}
		if ((cardData->cardExpirationDate[0] == termData->transactionDate[3]) && (cardData->cardExpirationDate[1] == termData->transactionDate[4])) {
			stat_is_card_expired = TERMINAL_OK;
			/*char is_card_expired_error[20] = "TERMINAL_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isCardExpired\n");
			printf("Test Case 2 : Card is valid \n");
			printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
			printf("Expected Result:TERMINAL_OK\n");
			printf("Actual Result: % s \n", is_card_expired_error);*/
			return stat_is_card_expired;
		}
		if ((cardData->cardExpirationDate[0] == termData->transactionDate[3]) && (cardData->cardExpirationDate[1] > termData->transactionDate[4])) {
			stat_is_card_expired = TERMINAL_OK;
			/*char is_card_expired_error[20] = "TERMINAL_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isCardExpired\n");
			printf("Test Case 2 : Card is valid \n");
			printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
			printf("Expected Result:TERMINAL_OK\n");
			printf("Actual Result: % s \n", is_card_expired_error);*/
			return stat_is_card_expired;
		}
		if ((cardData->cardExpirationDate[0] == termData->transactionDate[3]) && (cardData->cardExpirationDate[1] < termData->transactionDate[4])) {
			stat_is_card_expired = EXPIRED_CARD;
			/*char is_card_expired_error[20] = "EXPIRED_CARD";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isCardExpired\n");
			printf("Test Case 1 : Card is expired \n");
			printf("Input Data :expiry date is %s and today date is %s \n", cardData->cardExpirationDate, termData->transactionDate);
			printf("Expected Result:EXPIRED_CARD\n");
			printf("Actual Result: % s \n", is_card_expired_error);*/
			return stat_is_card_expired;
		}
	}
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) {
	int i1;
	int count1 = 0;
	int count2 = 0;
	int luhn;
	EN_terminalError_t stat_is_valid_card_pan;
	for (i1 = 0; i1 < strlen(cardData->primaryAccountNumber); i1++) {
		if (i1 % 2 == 0) {
			int a = (cardData->primaryAccountNumber[i1] - '0') * 2;
			if ((a % 10) != 0) {
				count1 = count1 + (a / 10) + (a - ((a / 10) * 10));
			}
			else if ((a % 10) == 0) {
				count1 = count1 + (a / 10);
			}
		}
		else if (i1 % 2 != 0) {
			count2 = count2 + (cardData->primaryAccountNumber[i1] - '0');
		}
	}
	if (i1 == strlen(cardData->primaryAccountNumber)) {
		luhn = count2 + count1;
		//printf("count1 is %d\n", count1);
		//printf("count2 is %d\n", count2);
		if (luhn % 10 == 0) {
			stat_is_valid_card_pan = TERMINAL_OK;
			char is_valid_card_pan_error[20] = "TERMINAL_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isValidCardPAN\n");
			printf("Test Case 1 : Card is valid and passed Luhn Check \n");
			printf("Input Data :Pan is %s \n", cardData->primaryAccountNumber);
			printf("Expected Result:TERMINAL_OK\n");
			printf("Actual Result: % s \n", is_valid_card_pan_error);
			return stat_is_valid_card_pan;
		}
		else {
			stat_is_valid_card_pan = INVALID_CARD;
			char is_valid_card_pan_error[20] = "INVALID_CARD";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:isValidCardPAN\n");
			printf("Test Case 2 : Card is invalid and failed Luhn Check \n");
			printf("Input Data : Pan is %s \n", cardData->primaryAccountNumber);
			printf("Expected Result:INVALID_CARD\n");
			printf("Actual Result: % s \n", is_valid_card_pan_error);
			return stat_is_valid_card_pan;
		}
	}


}

void getTransactionDateTest(void);
void isCardExpriedTest(void);
void getTransactionAmountTest(void);
void isBelowMaxAmountTest(void);
void setMaxAmountTest(void);
//void isValidCardPANTest(void);

//int main() {
	//getTransactionDateTest();
	//isCardExpriedTest();
	//getTransactionAmountTest();
	//isBelowMaxAmountTest();
	//setMaxAmountTest();
	//isValidCardPANTest();
//}

void getTransactionDateTest(void) {
	getTransactionDate(terminal_pt);
}

void isCardExpriedTest(void) {
	//getCardExpiryDate(card_pt2);
	//printf("/////////\\\\\\\\ \n");
	//getTransactionDate(terminal_pt);
	//printf("/////////\\\\\\\\ \n");
	//printf("%d",isCardExpired(card_pt2, terminal_pt));
}

void getTransactionAmountTest(void) {
	getTransactionAmount(terminal_pt);
}
void isBelowMaxAmountTest(void) {
	getTransactionAmount(terminal_pt);
	printf("/////////\\\\\\\\ \n");
	setMaxAmount(terminal_pt, 20000);
	printf("/////////\\\\\\\\ \n");
	isBelowMaxAmount(terminal_pt);
	printf("%d \n", isBelowMaxAmount(terminal_pt));
}
void setMaxAmountTest(void) {
	setMaxAmount(terminal_pt, 1000);
}
//void isValidCardPANTest(void) {
//	getCardPAN(card_pt2);
 // printf("/////////\\\\\\\\ \n");
 // printf("here we are %d", atoi(card2.primaryAccountNumber[0]));
 // isValidCardPAN(card_pt2);
//}