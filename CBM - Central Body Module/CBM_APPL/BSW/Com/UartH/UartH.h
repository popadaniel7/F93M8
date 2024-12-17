/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
#include "usart.h"
/* INCLUDE END */
/* VARIABLES START */
#define UART_BUFFER_SIZE 512

extern uint32 UartH_ErrorArr[5];
extern uint8 UartH_InterruptFlag;

typedef struct {
	int hour;
	int min;
	int sec;
}TIME;

typedef struct {
	float latitude;
	char NS;
	float longitude;
	char EW;
}LOCATION;

typedef struct {
	float altitude;
	char unit;
}ALTITUDE;

typedef struct {
	int Day;
	int Mon;
	int Yr;
}DATE;

typedef struct {
	LOCATION lcation;
	TIME tim;
	int isfixValid;
	ALTITUDE alt;
	int numofsat;
}GGASTRUCT;

typedef struct {
	DATE date;
	float speed;
	float course;
	int isValid;
}RMCSTRUCT;

typedef struct {
	GGASTRUCT ggastruct;
	RMCSTRUCT rmcstruct;
}GPSSTRUCT;

typedef struct
{
  unsigned char buffer[UART_BUFFER_SIZE];
  volatile unsigned int head;
  volatile unsigned int tail;
} ring_buffer;

int decodeGGA (char *GGAbuffer, GGASTRUCT *gga);
int decodeRMC (char *RMCbuffer, RMCSTRUCT *rmc);
/* Initialize the ring buffer */
void Ringbuf_init(void);
/* reads the data in the rx_buffer and increment the tail count in rx_buffer */
int Uart_read(void);
/* writes the data to the tx_buffer and increment the head count in tx_buffer */
void Uart_write(int c);
/* function to send the string to the uart */
void Uart_sendstring(const char *s);
/* Print a number with any base
 * base can be 10, 8 etc*/
void Uart_printbase (long n, uint8_t base);
/* Checks if the data is available to read in the rx_buffer */
int IsDataAvailable(void);
/* Look for a particular string in the given buffer
 * @return 1, if the string is found and -1 if not found
 * @USAGE:: if (Look_for ("some string", buffer)) do something
 */
int Look_for (char *str, char *buffertolookinto);
/* Copies the required data from a buffer
 * @startString: the string after which the data need to be copied
 * @endString: the string before which the data need to be copied
 * @USAGE:: GetDataFromBuffer ("name=", "&", buffertocopyfrom, buffertocopyinto);
 */
void GetDataFromBuffer (char *startString, char *endString, char *buffertocopyfrom, char *buffertocopyinto);
/* Resets the entire ring buffer, the new data will start from position 0 */
void Uart_flush (void);
/* Peek for the data in the Rx Bffer without incrementing the tail count
* Returns the character
* USAGE: if (Uart_peek () == 'M') do something
*/
int Uart_peek();
/* Copy the data from the Rx buffer into the bufferr, Upto and including the entered string
* This copying will take place in the blocking mode, so you won't be able to perform any other operations
* Returns 1 on success and -1 otherwise
* USAGE: while (!(Copy_Upto ("some string", buffer)));
*/
int Copy_upto (char *string, char *buffertocopyinto);
/* Copies the entered number of characters (blocking mode) from the Rx buffer into the buffer, after some particular string is detected
* Returns 1 on success and -1 otherwise
* USAGE: while (!(Get_after ("some string", 6, buffer)));
*/
int Get_after (char *string, uint8_t numberofchars, char *buffertosave);
/* Wait until a paricular string is detected in the Rx Buffer
* Return 1 on success and -1 otherwise
* USAGE: while (!(Wait_for("some string")));
*/
int Wait_for (char *string);
/* the ISR for the uart. put it in the IRQ handler */
void Uart_isr (UART_HandleTypeDef *huart);
/* VARIABLES STOP */
/* FUNCTIONS START */
extern void UartH_MainFunction(void);
extern uint8 UartH_ReturnInterruptStatus(void);
extern void UartH_GpsMainFunction(void);
/* FUNCTIONS STOP */
/* STOP OF FILE */
