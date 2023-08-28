#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/Function_Headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern BASIC head;
u32 global_u32ListLength =0;

u128 generate_BankID() 
{
    u128 random_number = 0;
    srand(time(NULL));
    for (int i = 0; i < 9; i++) 
    {
        random_number = random_number * 10 + rand() % 10;
    }
    if (random_number<999999999)
    random_number *=10; 
    return random_number;
}

u16 generate_password() 
{
    u16 random_number = 0;
    for (int i = 0; i < 4; i++) 
    {
        random_number = random_number * 10 + rand() % 10;
    }
    //random_number = random_number * 10 + rand() % 10; 
    if (random_number < 999)
    random_number *=10;

    return random_number;
}



void print_all(BASIC x)
{
    system("cls");
    printf("\nName: %s", x.name);
    printf("Address: %s", x.address);
    printf("Age: %d \n" , x.age);
    printf("National ID: %lld \n" , x.National_id);
    printf("Guardian ID: %lld \n" , x.guardian_national_id);
    printf("Bank ID: %lld   \033[1;33mSAVE THIS NUMBER\033[0m\n" , x.bank_account_id);
    printf("Balance: %.2f \n" , x.Balance);
    printf("Password is:%d  \033[1;33mSAVE THIS NUMBER\033[0m\n", x.password);
    if(x.Status==1)
    {printf("Status:\033[1;32mActive\033[0m\n\n");}
    else 
    {printf("Status:\033[1;31mNot Active\033[0m\n\n");}
}

void print_ptr(BASIC* x)
{
    system("cls");
    printf("\nName: %s", x->name);
    printf("Address: %s", x->address);
    printf("Age: %d \n" , x->age);
    printf("National ID: %lld \n" , x->National_id);
    printf("Guardian ID: %lld \n" , x->guardian_national_id);
    printf("Bank ID: %lld   \033[1;33mSAVE THIS NUMBER\033[0m\n" , x->bank_account_id);
    printf("Balance: %.2f \n" , x->Balance);
    printf("Password is:%d  \033[1;33mSAVE THIS NUMBER\033[0m\n", x->password);
    if(x->Status==1)
    {printf("Status:\033[1;32mActive\033[0m\n\n");}
    else
    {printf("Status:\033[1;31mNot Active\033[0m\n\n");}
}

void L_AddAccount(void)
{   
    if(global_u32ListLength==0)
    {
    printf("Please Enter your Name:");
    fflush(stdin);
    fgets(head.name, sizeof(head.name), stdin);
    fflush(stdin);
    printf("Please Enter your Address:");
    fgets(head.address, sizeof(head.address), stdin);

    printf("Please Enter your Age:");
    scanf("%d" , &head.age);   
    while(head.age>100 || head.age <0)
    {
        printf("Invalid Age Please Enter your Age:");
        scanf("%d" , &head.age);    
    }
    if (head.age <21)
    {
        printf("Please Enter your Guardian National ID:");
        scanf("%lld",&head.guardian_national_id);
        while(head.guardian_national_id>=99999999999999|| head.guardian_national_id<=9999999999999)
        {
         printf("Invalid Guardian ID Please Enter your Guardian National ID:");
         scanf("%lld",&head.guardian_national_id);   
        }
    head.National_id=0;
    }
    else
    {
        printf("Enter your National ID: ");
        scanf("%lld" , &head.National_id);        
        while(head.National_id>=99999999999999|| head.National_id<=9999999999999)
        {
            printf("Invalid National ID ,Enter your National ID:");
            scanf("%lld" , &head.National_id);
        }
        head.guardian_national_id=0;
    }
    head.bank_account_id=generate_BankID();
    head.password=generate_password();
    head.Balance=0.00;
    head.Status=1;
    system("cls");
    printf("\n\n\n\n\t\t\t\t Account Created Successfully \n\n");
    print_all(head);
    }
    else
    {
        BASIC *last;
        BASIC temp;
        BASIC *new = (BASIC *) malloc (sizeof(BASIC));
        printf("Please Enter your Name:");
        fflush(stdin);
        fgets(new->name, sizeof(new->name), stdin);

        fflush(stdin);
        printf("Please Enter your Address:");
        fgets(new->address, sizeof(new->address), stdin);

    printf("Please Enter your Age:");
    scanf("%d" , &new->age);   
    while(new->age>100 || new->age <0)
    {
        printf("Invalid Age Please Enter your Age:");
        scanf("%d" , &new->age);    
    }
        if (new->age <21)
        {
            printf("Please Enter your Guardian National ID:");
            scanf("%lld",&new->guardian_national_id);
            while(new->guardian_national_id>=99999999999999|| new->guardian_national_id<=9999999999999)
            {
                printf("Invalid ID Please Enter your Guardian National ID:");
                scanf("%lld",&new->guardian_national_id);
            }
        new->National_id=0;
        }
        else
        {
            printf("Enter your National ID:");
            scanf("%lld" , &new->National_id);
            while(new->National_id>=99999999999999|| new->National_id <=9999999999999)
            {
                printf("Invalid ID Please Enter your National ID:");
                scanf("%lld" , &new->National_id);
            }
            new->guardian_national_id=0;
        }
        new->bank_account_id=generate_BankID();
        new->password=generate_password();
        new->Balance=0.00;
        new->Status=1;
        new->next=NULL;

        last = &head;
        while ((last->next) != NULL)
        {
            last = last ->next;
        }
        last ->next =new;
    system("cls");
    printf("\n\n\n\n\t\t\t\t Account Created Successfully \n\n");
        print_ptr(new);
    }

global_u32ListLength++; 
  
}

void MakeTransaction(u128 Receiver_ID, BASIC *Sender) 
{
    BASIC *search__ = &head;
    u32 flag = 0;
    f32 Money_Requested_toSent;

    if (Receiver_ID == Sender->bank_account_id) 
    {
        system("cls");
        printf("You can't Send Money to Yourself\n\n");
        return;
    }

    while ((search__->next != NULL) && (search__->bank_account_id != Receiver_ID)&&(Receiver_ID!=0)) 
    {
        printf("%lld\n", search__->bank_account_id);
        search__ = search__->next;
    }

    if (((search__->Status) == 1) && (search__->bank_account_id)==Receiver_ID) 
    {
        while (1) 
        {
            printf("Please Enter the Amount you want to Send:");
            scanf("%f", &Money_Requested_toSent);

            if (Money_Requested_toSent == 0) 
            {
                system("cls");
                break;
            }

            if ((Sender->Balance) > Money_Requested_toSent && Money_Requested_toSent >0) 
            {
                Sender->Balance -= Money_Requested_toSent;
                search__->Balance += Money_Requested_toSent;
                system("cls");
                printf("\n\n\t\t\t\tMoney Transferred Successfully Balance Transfered:%.2f" ,Money_Requested_toSent);
                printf("\n\t\t\t\t\tCurrent Balance:%.2f\n\n" , Sender->Balance);
                break;
            }
            else 
            {   
                system("cls");
                printf("\n\n \t\t\t\tInsufficient Amount..\n\n\n");
                flag++;
            }
        }
    }
    else if (search__->Status ==0 && (search__->bank_account_id)==Receiver_ID)
    {
        system("cls");
        printf("Receiver Account is not Active\n\n");
    }

    else
    {
    system("cls");
    printf("Invalid Bank ID\n\n");
    }

}
    
      
void Change_Account_Status(BASIC* ptr)
{
    u32 number;
    printf("\n1.to Activate Account\n2.to Deactivate Account..\n\n");
    scanf("%d" , &number);
    switch (number)
    {
        case 1:
        ptr->Status =1;
        system("cls");
        printf("\t\t\t\tAccount Activated Successfully\n\n");
        break;
        case 2:
        ptr->Status =0;
        system("cls");
        printf("\t\t\t\tAccount Deactivated Successfully\n\n");
        break;
        default:
        system("cls");
        printf("\t\t\t\tEnter a Valid Number");
        break;
    }
}

void Deposit(BASIC* ptr)
{
    f32 Money_Deposit;
    if(ptr->Status==1)
    {
        printf("Please Enter the Amount you want to Deposit:");
        scanf("%f" , &Money_Deposit);
        while(Money_Deposit<0)
        {
            printf("Invalid Amount Please Try again..\n\n");
            printf("Please Enter the Amount you want to Deposit:");
            scanf("%f" , &Money_Deposit);
            if(Money_Deposit ==0)
            {
                system("cls");
                return;
            }
        }
        ptr->Balance+=Money_Deposit;
        system("cls");
        printf("\n\t\t\t\tMoney Depositted Successfully!");
        printf("\n\t\t\t\tCurrent Balance Equals:%.2f\n\n" ,ptr->Balance);
    }
    else
    {
        system("cls");
        printf("\n\n\t\t\t\tAccount is not Active..\n===== \n\n"); return;
    }
}

void Get_Cash(BASIC *ptr)
{
    f32 Money_toGet;
    if(ptr->Status==1)
    {
        printf("Please Enter the Amount you want to Get in Cash:");
        scanf("%f" , &Money_toGet);
        while((ptr->Balance)<Money_toGet || Money_toGet<0)
        {
            printf("Invalid Amount Please Try again..\n\n");
            printf("Please Enter the Amount you want to Get in Cash:");
            scanf("%f" , &Money_toGet);
            if(Money_toGet ==0)
            {
                system("cls");
                return;
            }
        }
        ptr->Balance-=Money_toGet;
        system("cls");
        printf("\n\t\t\t\tMoney in Cash Successfully");
        printf("\n\t\t\t\tCurrent Balance Equals:%.2f\n\n" ,ptr->Balance);
    }
    else
    {
        system("cls");
        printf("\n\n\t\t\t\tAccount is not Active..\n===== \n\n"); return;
    }

}


void ChangePassword(BASIC *search_) 
{
    u16 new_password;
    printf("Enter your new Password: ");
    fflush(stdin);
    scanf("%d", &new_password);
    search_->password=new_password;
    printf("%d\n" , new_password);
    printf("\n\nPassword Changed Successfully\n\n");
}

void print_ptr_client(BASIC* x)
{
    system("cls");
    printf("\nName: %s", x->name);
    printf("Address: %s", x->address);
    printf("Bank ID: %lld   \033[1;33mSAVE THIS NUMBER\033[0m\n" , x->bank_account_id);
    printf("Password is:%d  \033[1;33mSAVE THIS NUMBER\033[0m\n\n\n", x->password);
    printf("Balance: %.2f \n\n\n" , x->Balance);
}