/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : admin.h                                               */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef ADMIN_H_
#define ADMIN_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "COMMON.h"
#include "database.h"

//----------------------------------------------
// Section: Macro Definitions
//----------------------------------------------
#define ADMIN_USERNAME		1346
#define ADMIN_PASSWORD		6431
#define MAX_LOGIN_TRIES		3

//----------------------------------------------
// Section: APIs Declarations
//----------------------------------------------
void admin_main(void);

#endif /* ADMIN_H_ */
