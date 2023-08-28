#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/Function_Headers.h"

BASIC head;
BASIC *search_;

void main (void)
{
    u16 new_password;
    system("cls");
    u32 chosen_number_1;
    u128 Scanned_ID=0;
    u32 Scanned_Password=0;

    while (1)
    {
        while (1)
        {
            printf("\033[1;31mMADE BY AHMEDMMTALAAT \033[0m\n");
            printf("\n\nAdmin ID:%lld\n" , ID);
            printf("Admin Password:%d\n\n\n\n" , Password);
            printf("\t\t\t\t\033[1;35mWelcome to IMT Bank System!\033[0m\n\n");
            printf("Please Choose from the Following List:\n 1.Admin Window. \n 2.Client Window.\n\n");

            scanf("%d" , &chosen_number_1);
            switch (chosen_number_1)
            {
                case 1:
                    /* Admin */
                    printf("Please Enter Correct Admin ID and Correct Password. \n");
                    while ((Scanned_ID != ID) || (Scanned_Password != Password))
                    {
                        printf("Admin ID:");
                        scanf("%llu" , &Scanned_ID);
                        printf("Please Enter Admin Password:");
                        scanf("%d" , &Scanned_Password);
                        if ((Scanned_ID != ID) || (Scanned_Password != Password) || (Scanned_ID==0) || (Scanned_Password==0))
                        {
                            printf("Sorry you Entered a Wrong ID or Password Try Again..\n \n");
                        }   
                    }
                    system("cls");
                    printf("\033[1;31mMADE BY AHMEDMMTALAAT \033[0m\n\n");
                    printf("\t\t\t\tWelcome Admin!\n\n\n");
                    printf("Choose a Process \n 1.Create New Account \n 2.Open Existing Account \n\nAny Key to Return to Main Menu..\n\n");
                    Scanned_ID=0;
                    Scanned_Password=0;
                    
                    scanf("%d" ,&chosen_number_1);
                    switch (chosen_number_1)
                    {
                        case 1:
                            /* Create New Account */
                            L_AddAccount();
                            break;
                        case 2:
                            /*Open Existing Account*/
                                printf("Please Enter the User's Bank ID:");
                                scanf("%lld" , &Scanned_ID);
                                printf("Scanned Bank ID:%llu\n" , Scanned_ID);
                                search_ = &head;
                                while((search_->next !=NULL))
                                    {
                                        if((search_ -> bank_account_id) == Scanned_ID )
                                        {
                                            break;
                                        }
                                        else
                                        search_=search_->next;
                                    }
                                if ((search_ -> bank_account_id) == Scanned_ID)
                                {
                                    u32 flag=1;
                                    while(flag==1)

                                    {   
                                        
									    printf("\033[1;31mMADE BY AHMEDMMTALAAT \033[0m\n"); 
                                        printf("\n\n\n\t\t\t\tAdmin Preview Choose a Process...\n 1.Make Transaction\n");
                                        printf(" 2.Deposit in Account \n 3.Get Cash");
                                        printf("\n 4.Change Account Status\n 5.Print Account Data\n\n Any Key to Return to Main Menu..\n\n");

                                        scanf("%d" , &chosen_number_1);
                                        switch (chosen_number_1)
                                        {
                                            case 1:
                                                    /*Make Transaction*/
                                                if(search_->Status==1)
                                                {
                                                    printf("Please Enter Receiver's Bank ID:");
                                                    scanf("%lld" , &Scanned_ID);
                                                    printf("Scanned ID: %lld \n\n",Scanned_ID);
                                                    MakeTransaction(Scanned_ID , search_);
                                                    break;
                                                }
                                                else
                                                {   
                                                    system("cls");
                                                    printf("\n\nyour Account isn't Active\n\n");
                                                    break;
                                                }
                                            case 2:
                                                    /*Deposit in Account*/
                                                    Deposit(search_);
                                                    break;
                                            case 3:
                                                    /*Get Cash*/
                                                    Get_Cash(search_);
                                                    break;
                                            case 4:
                                                    /*Change Status*/
                                                    Change_Account_Status(search_);
                                                    break;

                                            case 5:
                                                    /*Print Data*/
                                                    print_ptr(search_);
                                                    break;

                                            default:
                                                    flag=0;
                                                    system("cls");
                                        }   
                                    }        
                                }
                             else
                                {
                                    system("cls");
                                    printf("\t\t\t\t\t\t\tBank ID doesn't Exist\n\n");
                                }
                            break;

                        default:
                            /*default of Admin Page*/
                            system("cls");
                            break;
                    }
                    break;

                case 2:
                        /*Client*/
                        system("cls");
                        printf("Please Enter your Bank ID and Password\n\n ID:");
                        scanf("%lld" ,&Scanned_ID);
                        printf(" Password:");
                        scanf("%d" , &Scanned_Password);
                        if((Scanned_ID ==0) || (Scanned_Password)==0)
                        {
                            system("cls");
                            printf("Invalid ID or Password Please Try Again\n\n");
                            break;
                        }
                        search_ = &head;
                        while((search_->next !=NULL))
                            {
                                if((search_ -> bank_account_id) == Scanned_ID )
                                {
                                    break;
                                }
                                else
                                search_=search_->next;
                            }

                            if((search_ -> password) == Scanned_Password )
                            {
                                u32 chosen_number_2;
                                u32 flag=1;
                                while (flag==1)
                                {
                                    printf("\033[1;31mMADE BY AHMEDMMTALAAT \033[0m\n"); 
                                    printf("\n\n\n\t\t\t\tClient Preview Choose a Process...\n 1.Make Transaction\n");
                                    printf(" 2.Deposit in Account \n 3.Get Cash");
                                    printf("\n 4.Change Password\n 5.Print Data\n\n Any Key to Return to Main Menu..\n\n");
                                    scanf("%d" , &chosen_number_2);
                                    switch (chosen_number_2)
                                    {
                                        case 1:
                                                    /*Make Transaction*/
                                                if(search_->Status==1)
                                                {
                                                    printf("Please Enter Receiver's Bank ID:");
                                                    scanf("%lld" , &Scanned_ID);
                                                    printf("Scanned ID: %lld \n\n",Scanned_ID);
                                                    MakeTransaction(Scanned_ID , search_);
                                                    break;
                                                }
                                                else
                                                {   
                                                    system("cls");
                                                    printf("\n\nyour Account isn't Active\n\n");
                                                    break;
                                                }
                                            case 2:
                                                    /*Deposit in Account*/
                                                    Deposit(search_);
                                                    break;
                                            case 3:
                                                    /*Get Cash*/
                                                    Get_Cash(search_);
                                                    break;
                                            case 4:
                                                    /*Change Password*/
                                                    printf("Enter your new Password: ");
                                                    fflush(stdin);
                                                    scanf("%d", &new_password);
                                                    (search_->password)=new_password;
													while(new_password==0)
													{
														printf("invalid Password Please Try Again:");
														scanf("%d", &new_password);
													}	
                                                    printf("\n\nPassword Changed Successfully\n\n");                                                 
                                                    
                                            case 5:
                                                    /*Print Data*/
                                                    print_ptr_client(search_);
                                                    break;
                                            default:
                                                    /*Default of Client Preview*/
                                                    system("Cls");
                                                    flag=0;
                                                    break;
                                    }
                                }
                            }
                            else
                            {printf("Invalid ID or Password Please Try Again\n\n");}

                        break;

                default:
                /*Default of Admin and Client Pages*/
                    system("cls");
                    break;
            }

        }
    }
}