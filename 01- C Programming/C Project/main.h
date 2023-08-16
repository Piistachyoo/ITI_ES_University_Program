/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : main.h                                                */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "COMMON.h"
#include "admin.h"
#include "client.h"

//----------------------------------------------
// Section: Macro Definitions
//----------------------------------------------
#define MAX_LOGIN_TRIES		3

//----------------------------------------------
// Section: Data type Definitions
//----------------------------------------------
typedef enum{
	STATE_INIT,
	STATE_IDLE,
	STATE_ADMIN,
	STATE_CLIENT,
	STATE_QUIT
}main_states;


#endif /* MAIN_H_ */
