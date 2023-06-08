/*
 * Ext_interrupt.c
 *
 * Created: 4/8/2023 8:29:59 PM
 *  Author: Amr
 */ 
#include "Ext_IntCnfg.h"

void static (*int0_callback_function) (void);
void static (*int1_callback_function) (void);
void static (*int2_callback_function) (void);



enu_ext_int_error_status_t enu_ext_int_error_status = EXT_INT_OK ;

/***************************************************/
//			 EXTERNAL INTERRUPT INIT
/***************************************************/
enu_ext_int_error_status_t ext_int_init(){

/****************** INTERRRUPT 0 ******************/	

#if INT0_ENABLE == ENABLE
	
		
//CHOOSE INTERUPT SENSE MODE
#if INT0_SENSE_MODE == LOW_LEVEL
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		
#elif INT0_SENSE_MODE == ANY_LOGIC
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
	
#elif INT0_SENSE_MODE == FALLING_EDGE
			SET_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
		
#elif INT0_SENSE_MODE == RAISING_EDGE
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
#else
	enu_ext_int_error_status = WRONG_SENSE_MODE;
	
#endif 

//ENABLE INTERRUPT_0
SET_BIT(GICR,INT_0);

#elif INT0_ENABLE != DISABLE && INT0_ENABLE != ENABLE
	enu_ext_int_error_status = INT_ENABLE_ERROR;


#endif
	
	
/***************** INTERRRUPT 1 ******************/

#if INT1_ENABLE == ENABLE

//CHOOSE INTERUPT SENSE MODE
#if INT1_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);

#elif INT1_SENSE_MODE == ANY_LOGIC
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);

#elif INT1_SENSE_MODE == FALLING_EDGE
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);

#elif INT1_SENSE_MODE == RAISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	
#else
enu_ext_int_error_status = WRONG_SENSE_MODE;

#endif

//ENABLE INTERRUPT_1
SET_BIT(GICR,INT_1);

#elif INT1_ENABLE != DISABLE && INT0_ENABLE != ENABLE
	enu_ext_int_error_status = INT_ENABLE_ERROR;

#endif


	
/****************** INTERRRUPT 2 ******************/


#if INT2_ENABLE == ENABLE

//CHOOSE INTERUPT SENSE MODE
#if INT2_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);

#elif INT2_SENSE_MODE == RAISING_EDGE
	SET_BIT(MCUCSR,ISC2);
	
#else
enu_ext_int_error_status = WRONG_SENSE_MODE;

#endif

//ENABLE INTERRUPT_2
SET_BIT(GICR,INT_2);

#elif INT2_ENABLE != DISABLE && INT0_ENABLE != ENABLE
	enu_ext_int_error_status = INT_ENABLE_ERROR;

#endif



return enu_ext_int_error_status;
} // END OF ext_int_init 


/*************************************************/
//				CALLBACK FUNCTIONS
/**************************************************/

// CALLBACK FUNCTION TO INT_0
enu_ext_int_error_status_t int0_set_callback(void(*callback)(void))
{
	if(callback != NULLPTR)
	{
		int0_callback_function=callback;
		return EXT_INT_OK;
	}
	else
	{
		//do nothing
	}
}


// CALLBACK FUNCTION TO INT_1
enu_ext_int_error_status_t int1_set_callback(void(*callback)(void))
{
	if(callback != NULLPTR)
	{
		int1_callback_function=callback;
		return EXT_INT_OK;
	}
	else
	{
		//do nothing
	}
	
}


// CALLBACK FUNCTION TO INT_2
enu_ext_int_error_status_t int2_set_callback(void(*callback)(void))
{
	if(callback != NULLPTR)
	{
		int2_callback_function=callback;
		return EXT_INT_OK;
	}
	else
	{
		//do nothing
	}
}



/***************************************************/
//					 ISR FUNCTION
/***************************************************/
 
/**********  ISR OF INT_0  ************/

ISR(EXT_INT_0)
{
	int0_callback_function();	
}


/**********  ISR OF INT_1  ************/

ISR(EXT_INT_1)
{
	int1_callback_function();
}


/**********  ISR OF INT_2  ************/

ISR(EXT_INT_2)
{
	int2_callback_function();
}