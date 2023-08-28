#include "BIT_MATH.h"
#include "STD_Types.h"

#define ID (1234)
#define Password (1234)


typedef struct basic_account BASIC;

struct basic_account
{
	u8 name [50];
	u8 address[30];
	u128 National_id;
	u128 guardian_national_id;
	u16 age;
	u128 bank_account_id;
	u8 Status ;
    u16 password;
    f32 Balance;
	BASIC *next;
};

u128 generate_BankID();
u16 generate_password();
void print_all(BASIC x);
void print_ptr(BASIC* Ptr);
void MakeTransaction(u128 Receiver_ID , BASIC* Sender);
void Change_Account_Status(BASIC* ptr);
void Deposit(BASIC* ptr);
void Get_Cash(BASIC *ptr);
void L_AddAccount(void);
void print_ptr_client(BASIC* x);