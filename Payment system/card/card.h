#ifndef CARD
#define CARD


typedef unsigned char uint8_t;          // typedef's needed for the ST_cardData_t
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;



typedef struct ST_cardData_t        // typedef of structure that have 3 parameters which are properties of Card
{
    uint8_t cardHolderName[25];          // array of card name
    uint8_t primaryAccountNumber[20];    // array of PAN
    uint8_t cardExpirationDate[6];       // array of Expiry date
} ST_cardData_t;


typedef enum EN_cardError_t                           //typedef for enum that have 4 options which corrpeosnds to error type
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);   // fuction will get holder name
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);   // fuction will get expiry date
EN_cardError_t getCardPAN(ST_cardData_t* cardData);          // fuction will get expiry date

extern ST_cardData_t* card_pt;        // global pointer so it can be seen across the whole C files

#endif