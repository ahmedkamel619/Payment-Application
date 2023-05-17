#include <stdio.h>
#include<string.h>
#include "card.h" 

ST_cardData_t card;
ST_cardData_t* card_pt = &card;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

	uint8_t input_name[50];                               // array that store the insertd name  that is GIVEN BY USER                              
	EN_cardError_t stat_get_card_holder_name=CARD_OK;            // type def enum that return [WRONG_NAME] or [CARD_OK] 
	printf("Hello Please Enter your Name: ");
	gets_s(input_name, 50);
	int i1;
	if (strlen(input_name) >= 20 && strlen(input_name) <= 24) {           // check if the name is inserted correctly
		/*	char get_card_holder_name_error[20] = "CARD_OK";
		printf("Function Name:getCardHolderName\n");
		printf("Test Case 1:name is correct and lies bet 20 and 24 characters\n");
		printf("Input Data : %s\n", input_name);
		printf("Expected Result: CARD_OK \n");
		printf("Actual Result:%s \n", get_card_holder_name_error);       */
		
		for (i1 = 0; i1 <= 24; i1++) {                                // get inserted name in cardHolderName of struct
			cardData->cardHolderName[i1] = input_name[i1];
			//printf("iteration at %d \n", i1);
			//printf("char is %c \n", cardData->cardHolderName[i1]);
		}
		EN_cardError_t stat_get_card_holder_name = CARD_OK;
		return stat_get_card_holder_name;
	}
	else {
		if (strlen(input_name) < 20 && strlen(input_name) != 0) {   // check if the name is less than 20 characters
			/* char get_card_holder_name_error[20] = "WRONG_NAME";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardHolderName\n");
			printf("Test Case 2:name is lower than 20 characters\n");
			printf("Input Data : %s \n", input_name);
			printf("Expected Result: WRONG_NAME \n");
			printf("Actual Result:%s \n", get_card_holder_name_error);    */
			EN_cardError_t stat_get_card_holder_name = WRONG_NAME;
			//return stat_get_card_holder_name;
		}
		else if (strlen(input_name) > 24) {                // check if the name is more than 24 characters
			/* char get_card_holder_name_error[11] = "WRONG_NAME";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardHolderName\n");
			printf("Test Case 3:name is bigger than 24 characters \n");
			printf("Input Data : %s \n", input_name);
			printf("Expected Result: WRONG_NAME \n");
			printf("Actual Result:%s \n", get_card_holder_name_error); */
			EN_cardError_t stat_get_card_holder_name = WRONG_NAME;
			//return stat_get_card_holder_name;
		}
		else  if (strlen(input_name) == 0) {                // check if the name is null
			/*char get_card_holder_name_error[11] = "WRONG_NAME";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardHolderName\n");
			printf("Test Case 4: Null \n");
			printf("Input Data : %s \n", input_name);
			printf("Expected Result: WRONG_NAME \n");
			printf("Actual Result:%s \n", get_card_holder_name_error); */
			EN_cardError_t stat_get_card_holder_name = WRONG_NAME;
			//return stat_get_card_holder_name;
		}
		return stat_get_card_holder_name;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	uint8_t input_expiry_date[50]; ;                                               // array the will have expiry date of card that is GIVEN BY USER  
	EN_cardError_t stat_get_card_expiry_date=CARD_OK;                                          // type def enum card error [WRONG_DATE] or [CARD_OK]
	printf("please enter the expiry date of Card in format MM/YY : ");
	gets_s(input_expiry_date, 50);                                                  // take expiry date from user
	if (strlen(input_expiry_date) == 5 && (input_expiry_date[0] == '0' || input_expiry_date[0] == '1') && input_expiry_date[2] == '/' && (input_expiry_date[3] == '1' || input_expiry_date[3] == '2' || input_expiry_date[3] == '3' ||
		input_expiry_date[3] == '4' || input_expiry_date[3] == '5' || input_expiry_date[3] == '6' || input_expiry_date[3] == '7' || input_expiry_date[3] == '8' || input_expiry_date[3] == '9') &&
		(input_expiry_date[4] == '1' || input_expiry_date[4] == '2' || input_expiry_date[4] == '3' || input_expiry_date[4] == '4' || input_expiry_date[4] == '5' || input_expiry_date[4] == '6' ||
			input_expiry_date[4] == '7' || input_expiry_date[4] == '8' || input_expiry_date[4] == '9' || input_expiry_date[4] == '0')) {
		if (input_expiry_date[0] == '0' && (input_expiry_date[1] == '1' || input_expiry_date[1] == '2' || input_expiry_date[1] == '3' || input_expiry_date[1] == '4' || input_expiry_date[1] == '5' ||
			input_expiry_date[1] == '6' || input_expiry_date[1] == '7' || input_expiry_date[1] == '8' || input_expiry_date[1] == '9')) {
			char get_card_expiry_date_error[20] = "CARD_OK";
			/*printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardExpiryDate\n");
			printf("Test Case 1: date is written in correct form \n");
			printf("Input Data :  %s  \n", input_expiry_date);
			printf("Expected Result: CARD_OK \n");
			printf("Actual Result:%s \n", get_card_expiry_date_error); */
			EN_cardError_t stat_get_card_expiry_date = CARD_OK;
			int i2;
			for (i2 = 0; i2 <= 5; i2++) {                                // get inserted card expiry date in card expiry date of struct
				cardData->cardExpirationDate[i2] = input_expiry_date[i2];
				//printf("iteration at %d \n", i2);
				//printf("char is %c \n", cardData->cardExpirationDate[i2]);
			}
			//return stat_get_card_expiry_date;

		}
		else if (input_expiry_date[0] == '1' && (input_expiry_date[1] == '0' || input_expiry_date[1] == '1' || input_expiry_date[1] == '2') && input_expiry_date[2] == '/' &&
			(input_expiry_date[3] == '1' || input_expiry_date[3] == '2' || input_expiry_date[3] == '3' || input_expiry_date[3] == '4' || input_expiry_date[3] == '5' || input_expiry_date[3] == '6' ||
				input_expiry_date[3] == '7' || input_expiry_date[3] == '8' || input_expiry_date[3] == '9') && (input_expiry_date[4] == '1' || input_expiry_date[4] == '2' || input_expiry_date[4] == '3' || input_expiry_date[4] == '4'
					|| input_expiry_date[4] == '5' || input_expiry_date[1] == '6' || input_expiry_date[1] == '7' || input_expiry_date[1] == '8' || input_expiry_date[1] == '9')) {
			/*char get_card_expiry_date_error[20] = "CARD_OK";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardExpiryDate\n");
			printf("Test Case 1: date is written in correct form \n");
			printf("Input Data :  %s  \n", input_expiry_date);
			printf("Expected Result: CARD_OK \n");
			printf("Actual Result:%s \n", get_card_expiry_date_error); */
			EN_cardError_t stat_get_card_expiry_date = CARD_OK;
			int i2;
			for (i2 = 0; i2 <= 5; i2++) {                                // get inserted card expiry date in card expiry date of struct
				cardData->cardExpirationDate[i2] = input_expiry_date[i2];
				//printf("iteration at %d \n", i2);
				//printf("char is %c \n", cardData->cardExpirationDate[i2]);
			}
			//return stat_get_card_expiry_date;
		}
		return stat_get_card_expiry_date;
	}
	else {
		if (strlen(input_expiry_date) > 5) {
			/*char get_card_expiry_date_error[20] = "WRONG_EXP_DATE";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardExpiryDate\n");
			printf("Test Case 2: date is more than 5 characters \n");
			printf("Input Data :  %s  \n", input_expiry_date);
			printf("Expected Result: WRONG_EXP_DATE \n");
			printf("Actual Result:%s \n", get_card_expiry_date_error); */
			EN_cardError_t stat_get_card_expiry_date = WRONG_EXP_DATE;
			//return stat_get_card_expiry_date;
		}
		if (strlen(input_expiry_date) < 5 && strlen(input_expiry_date) != 0) {
			/*char get_card_expiry_date_error[20] = "WRONG_EXP_DATE";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardExpiryDate\n");
			printf("Test Case 3: date is less than 5 characters \n");
			printf("Input Data :  %s  \n", input_expiry_date);
			printf("Expected Result:WRONG_EXP_DATE \n" );
			printf("Actual Result:%s \n", get_card_expiry_date_error); */
			EN_cardError_t stat_get_card_expiry_date = WRONG_EXP_DATE;
			//return stat_get_card_expiry_date;
		}
		if (strlen(input_expiry_date) == 0) {
			/*char get_card_expiry_date_error[20] = "WRONG_EXP_DATE";
			printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
			printf("Function Name:getCardExpiryDate\n");
			printf("Test Case 4: date is null \n");
			printf("Input Data :  %s  \n", input_expiry_date);
			printf("Expected Result: WRONG_EXP_DATE \n");
			printf("Actual Result:%s \n", get_card_expiry_date_error); */
			EN_cardError_t stat_get_card_expiry_date = WRONG_EXP_DATE;
			
		}
		return stat_get_card_expiry_date;
	}
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	uint8_t input_card_pan[50];                                               // array the will have card pan
	EN_cardError_t stat_card_pan=CARD_OK;                                          // type def enum card error [WRONG_PAN] or [CARD_OK]
	printf("enter tha PAN : ");
	gets_s(input_card_pan, 50);                                            // take Card Pan from user
	if (strlen(input_card_pan) >= 16 && strlen(input_card_pan) <= 19) {
		/*char get_card_pan_error[20] = "CARD_OK";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getCardPAN\n");
		printf("Test Case 1: PAN is Correct in number of charcters allowed range \n");
		printf("Input Data :  %s  \n", input_card_pan);
		printf("Expected Result: CARD_OK \n");
		printf("Actual Result:%s \n", get_card_pan_error); */
		EN_cardError_t stat_card_pan = CARD_OK;
		int i3;
		for (i3 = 0; i3 <= strlen(input_card_pan); i3++) {                                // get inserted pan  in pancard of struct 
			cardData->primaryAccountNumber[i3] = input_card_pan[i3];
			//printf("iteration at %d \n", i3);
			//printf("char is %c \n", cardData->primaryAccountNumber[i3]);
		}
		return stat_card_pan;
	}
	else if (strlen(input_card_pan) > 19) {
		/*char get_card_pan_error[20] = "WRONG_PAN";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getCardPAN\n");
		printf("Test Case 2: PAN is more than 19 characters \n");
		printf("Input Data :  %s  \n", input_card_pan);
		printf("Expected Result: WRONG_PAN \n");
		printf("Actual Result: % s \n", get_card_pan_error); */
		EN_cardError_t stat_card_pan = WRONG_PAN;
		//return stat_card_pan;
	}
	else if (strlen(input_card_pan) < 16 && strlen(input_card_pan) > 0) {
		/*char get_card_pan_error[20] = "WRONG_PAN";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getCardPAN\n");
		printf("Test Case 3: PAN is less than 16 characters \n");
		printf("Input Data :  %s  \n", input_card_pan);
		printf("Expected Result: WRONG_PAN \n");
		printf("Actual Result: % s \n", get_card_pan_error); */
		EN_cardError_t stat_card_pan = WRONG_PAN;
		//return stat_card_pan;
	}
	else if (strlen(input_card_pan) == 0) {
		/*char get_card_pan_error[20] = "WRONG_PAN";
		printf("Tester Name: Ahmed Kamel Zaky Mostafa \n");
		printf("Function Name:getCardPAN\n");
		printf("Test Case 4: PAN is not inserted \n");
		printf("Input Data :  %s  \n", input_card_pan);
		printf("Expected Result: Null \n");
		printf("Actual Result: % s \n", get_card_pan_error); */
		EN_cardError_t stat_card_pan = WRONG_PAN;
		//return stat_card_pan;
	}
	return stat_card_pan;
}


void getCardHolderNameTest(void);
void getCardExpiryDateTest(void);
void getCardPANTest(void);

/*int main() {
   getCardHolderNameTest();
   getCardExpiryDateTest();
   getCardPANTest();

 }


void getCardHolderNameTest(void) {
	getCardHolderName(card_pt);
	printf("%d \n", getCardHolderName(card_pt));
	printf("name holder is : %s", card.cardHolderName);
}
void getCardExpiryDateTest(void) {
	getCardExpiryDate(card_pt);
	printf("%d \n", getCardExpiryDate(card_pt));
	printf("card expiry date is : %s", card.cardExpirationDate);
}
void getCardPANTest(void) {
	 getCardPAN(card_pt);
	printf("%d \n",getCardPAN(card_pt));
	printf("pan is : %s", card.primaryAccountNumber);
}   */