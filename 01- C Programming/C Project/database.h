/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : database.h                                            */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef DATABASE_H_
#define DATABASE_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "COMMON.h"

//----------------------------------------------
// Section: Macro Definitions
//----------------------------------------------
#define ACCOUNT_RESTRICTED	2
#define ACCOUNT_CLOSED		1
#define ACCOUNT_ACTIVE		0

#define ID_FOUND			1
#define ID_NOT_FOUND		0

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef struct acc{
	uint8 	age;
	uint8	guardian;
	uint8	status;
	uint8 	name[100];
	uint8 	address[100];
	uint16	password;
	double	balance;
	uint64 	national_ID;
	uint64	bank_ID;
	uint64 	guardian_ID;
	struct acc *next;
}account_t;

//----------------------------------------------
// Section: APIs Declarations
//----------------------------------------------
void add_new_account(account_t *pAccount);
void display_all_accounts(void);
uint8 check_id_valid(uint64 _ID);
void get_account_info(uint64 _ID, account_t **retAccount);
void print_account_details(account_t *pAccount);
void import_database(void);
void export_database(void);
void make_transaction(account_t *pAccount);
void change_account_status(account_t *pAccount);
void get_cash(account_t *pAccount);
void deposit_cash(account_t *pAccount);
void change_password(account_t *pAccount);

#endif /* DATABASE_H_ */
