/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : STD_TYPES.h                                           */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef COMMON_H_
#define COMMON_H_

#define FLUSH_BUFFER()	fflush(stdin); fflush(stdout);
#define Block_getchar() printf("\nPress any key to continue..."); getch();



typedef unsigned char 		uint8;
typedef unsigned short 		uint16;
typedef unsigned long 		uint32;
typedef unsigned long long 	uint64;


typedef signed char			sint8;
typedef signed short 		sint16;
typedef signed long 		sint32;
typedef signed long long 	sint64;

#endif /* COMMON_H_ */
