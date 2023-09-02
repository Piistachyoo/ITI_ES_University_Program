/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : ATMEGA32.h                           				 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MCAL_ATMEGA32_H_
#define MCAL_ATMEGA32_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "../../SERVICES/STD_LIB.h"

//----------------------------------------------
// Section: Base addresses for Peripherals
//----------------------------------------------
#define PORTA_BASE		(0x39)
#define PORTB_BASE		(0x36)
#define PORTC_BASE		(0x33)
#define PORTD_BASE		(0x30)
#define EXTI_BASE		(0x54)
#define ADC_BASE		(0x24)
#define TIMER0_BASE		(0x50)
#define TIMER1_BASE		(0x46)
#define TIMER2_BASE		(0x42)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
/* GPIO */
typedef struct{
	volatile uint8 PIN;
	volatile uint8 DDR;
	volatile uint8 PORT;
}GPIO_Typedef;

/* EXTI */
typedef union{
	volatile uint8 MCUCR_REG;
	struct{
		volatile uint8 ISC0	:2;
		volatile uint8 ISC1	:2;
		volatile uint8 SM0	:1;
		volatile uint8 SM1	:1;
		volatile uint8 SM2	:1;
		volatile uint8 SE	:1;
	};
	struct{
		volatile uint8 ISC00	:1;
		volatile uint8 ISC01	:1;
		volatile uint8 ISC10	:1;
		volatile uint8 ISC11	:1;
	};
}MCUCR_bits;

typedef union{
	volatile uint8 MCUCSR_REG;
	struct{
		volatile uint8 PORF		:1;
		volatile uint8 EXTRF	:1;
		volatile uint8 BORF		:1;
		volatile uint8 WDRF		:1;
		volatile uint8 JTRF		:1;
		volatile uint8 			:1;
		volatile uint8 ISC2		:1;
		volatile uint8 JTD		:1;
	};
}MCUCSR_bits;

typedef union{
	volatile uint8 GICR_REG;
	struct{
		volatile uint8 IVCE		:1;
		volatile uint8 IVSEL	:1;
		volatile uint8 			:3;
		volatile uint8 INT2		:1;
		volatile uint8 INT0		:1;
		volatile uint8 INT1		:1;
	};
}GICR_bits;

typedef union{
	volatile uint8 GIFR_REG;
	struct{
		volatile uint8 			:5;
		volatile uint8 INTF2	:1;
		volatile uint8 INTF0	:1;
		volatile uint8 INTF1	:1;
	};
}GIFR_bits;

typedef struct{
	MCUCSR_bits MCUCSR;
	MCUCR_bits	MCUCR;
	volatile uint8 reserved[4];
	GIFR_bits	GIFR;
	GICR_bits	GICR;
}EXTI_Typedef;

/* ADC */
typedef union{
	volatile uint8 ADMUX_REG;
	struct{
		volatile uint8 MUX 		:5;
		volatile uint8 ADLAR 	:1;
		volatile uint8 REFS		:2;
	};
	struct{
		volatile uint8 MUX0		:1;
		volatile uint8 MUX1		:1;
		volatile uint8 MUX2		:1;
		volatile uint8 MUX3		:1;
		volatile uint8 MUX4		:1;
		volatile uint8 			:1;
		volatile uint8 REFS0	:1;
		volatile uint8 REFS1	:1;
	};
}ADMUX_bits;

typedef union{
	volatile uint8 ADCSRA_REG;
	struct{
		volatile uint8 ADPS		:3;
		volatile uint8 ADIE		:1;
		volatile uint8 ADIF		:1;
		volatile uint8 ADATE	:1;
		volatile uint8 ADSC		:1;
		volatile uint8 ADEN		:1;
	};
	struct{
		volatile uint8 ADPS0	:1;
		volatile uint8 ADPS1	:1;
		volatile uint8 ADPS2	:1;
	};
}ADCSRA_bits;

typedef union{
	volatile uint8 SFIOR_REG;
	struct{
		volatile uint8 PSR10	:1;
		volatile uint8 PSR2		:1;
		volatile uint8 PUD		:1;
		volatile uint8 ACME		:1;
		volatile uint8 			:1;
		volatile uint8 ADTS		:3;
	};
	struct{
		volatile uint8 			:5;
		volatile uint8 ADTS0	:1;
		volatile uint8 ADTS1	:1;
		volatile uint8 ADTS2	:1;
	};
}SFIOR_bits;

typedef union{
	volatile uint16 ADCLH_REG;
	struct{
		volatile uint8 ADCL;
		volatile uint8 ADCH;
	};
}ADCLH_bits;

typedef struct{
	ADCLH_bits 	ADCLH;
	ADCSRA_bits ADCSRA;
	ADMUX_bits	ADMUX;
	volatile uint8 reserved[39];
	SFIOR_bits	SFIOR;
}ADC_Typedef;
/*
typedef union{
	volatile uint8 TCCR_REG;
	struct{
		volatile uint8 CS	:3;
		volatile uint8 WGM1	:1;
		volatile uint8 COM	:2;
		volatile uint8 WGM0	:1;
		volatile uint8 FOC	:1;
	};
	struct{
		volatile uint8 CS00	 :1;
		volatile uint8 CS01	 :1;
		volatile uint8 CS02	 :1;
		volatile uint8 		 :1;
		volatile uint8 COM00 :1;
		volatile uint8 COM01 :1;
		volatile uint8 		 :1;
		volatile uint8 		 :1;

	};
}TCCR_bits;

typedef union{
	volatile uint8 TIMSK_REG;
	struct{
		volatile uint8 TOIE0	:1;
		volatile uint8 OCIE0	:1;
		volatile uint8 TOIE1	:1;
		volatile uint8 OCIE1B	:1;
		volatile uint8 OCIE1A	:1;
		volatile uint8 TICIE1	:1;
		volatile uint8 TOIE2	:1;
		volatile uint8 OCIE2	:1;
	};
}TIMSK_bits;

typedef union{
	volatile uint8 TIFR_REG;
	struct{
		volatile uint8 TOV0		:1;
		volatile uint8 OCF0		:1;
		volatile uint8 TOV1		:1;
		volatile uint8 OCF1B	:1;
		volatile uint8 OCF1A	:1;
		volatile uint8 ICF1		:1;
		volatile uint8 TOV2		:1;
		volatile uint8 OCF2		:1;
	};
}TIFR_bits;

typedef union{
	volatile uint8 TCCRA_REG;
	struct{
		volatile uint8 WGM		:2;
		volatile uint8 FOC		:2;
		volatile uint8 COMB		:2;
		volatile uint8 COMA		:2;
	};
	struct{
		volatile uint8 WGM10	:1;
		volatile uint8 WGM11	:1;
		volatile uint8 FOC1B	:1;
		volatile uint8 FOC1A	:1;
		volatile uint8 COM1B0	:1;
		volatile uint8 COM1B1	:1;
		volatile uint8 COM1A0	:1;
		volatile uint8 COM1A1	:1;
	};
}TCCRA_bits;

typedef union{
	volatile uint8 TCCRA_REG;
	struct{
		volatile uint8 CS		:3;
		volatile uint8 WGM		:2;
		volatile uint8 			:1;
		volatile uint8 ICES		:1;
		volatile uint8 ICNC		:1;
	};
	struct{
		volatile uint8 CS10		:1;
		volatile uint8 CS11		:1;
		volatile uint8 CS12		:1;
		volatile uint8 WGM12	:1;
		volatile uint8 WGM13	:1;
		volatile uint8 			:3;
	};
}TCCRB_bits;

typedef union{
	volatile uint16 TCNT1_reg;
	struct{
		volatile uint8 TCNT1L;
		volatile uint8 TCNT1H;
	};
}TCNT1_bits;

typedef union{
	volatile uint16 OCR1_reg;
	struct{
		volatile uint8 OCR1L;
		volatile uint8 OCR1H;
	};
}OCR1_bits;

typedef union{
	volatile uint16 ICR1_reg;
	struct{
		volatile uint8 ICR1L;
		volatile uint8 ICR1H;
	};
}ICR1_bits;

typedef struct{
	volatile uint8 TCR2UB	:1;
	volatile uint8 OCR2UB	:1;
	volatile uint8 TCN2UB	:1;
	volatile uint8 AS2		:1;
	volatile uint8			:4;
}ASSR_bits;

typedef struct{
	SFIOR_bits SFIOR;
	volatile uint8 reserved;
	volatile uint8 TCNT0;
	TCCR_bits TCCR0;
	volatile uint8 reserved2[4];
	TIFR_bits TIFR;
	TIMSK_bits TIMSK;
	volatile uint8 reserved3[2];
	volatile uint8 OCR0;
}TIMER0_Typedef;

typedef struct{
	ICR1_bits ICR1;
	OCR1_bits OCR1B;
	OCR1_bits OCR1A;
	TCNT1_bits TCNT1;
	TCCRB_bits TCCR1B;
	TCCRA_bits TCCR1A;
	SFIOR_bits SFIOR;
	volatile uint8 reserved[7];
	TIFR_bits TIFR;
	TIMSK_bits TIMSK;
}TIMER1_Typedef;

typedef struct{
	ASSR_bits ASSR;
	volatile uint8 OCR2;
	volatile uint8 TCNT2;
	TCCR_bits TCCR2;
	volatile uint8 reserved[10];
	SFIOR_bits SFIOR;
	volatile uint8 reserved2[7];
	TIFR_bits TIFR;
	TIMSK_bits TIMSK;
}TIMER2_Typedef;
*/
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
#define SREG	(*((volatile uint8*)0x5F))
#define GPIOA	((GPIO_Typedef*)PORTA_BASE)
#define GPIOB	((GPIO_Typedef*)PORTB_BASE)
#define GPIOC	((GPIO_Typedef*)PORTC_BASE)
#define GPIOD	((GPIO_Typedef*)PORTD_BASE)
#define EXTI	((EXTI_Typedef*)EXTI_BASE)
#define ADC		((ADC_Typedef*) ADC_BASE)
#define TIMER0	((TIMER0_Typedef*)TIMER0_BASE)
#define TIMER1	((TIMER1_Typedef*)TIMER1_BASE)
#define TIMER2	((TIMER2_Typedef*)TIMER2_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: General Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
#define GLOBAL_INTERRUPT_ENABLE()	(SREG |= (1U<<7))
#define GLOBAL_INTERRUPT_DISABLE()	(SREG &= ~(1U<<7))

#endif /* MCAL_ATMEGA32_H_ */
