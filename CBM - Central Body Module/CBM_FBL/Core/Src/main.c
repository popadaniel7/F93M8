/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef enum
{
	DEFAULT = 0U,
	EXTENDED = 1U,
	PROGRAMMING = 2U,
	CODING = 3U,
	CALIBRATION = 4U,
	HARDRESET = 5U,
	SOFTRESET = 6U,
	JUMPTOAPPL = 7U
}FBL_DSC_t;
typedef union
{
	struct
	{
		uint8 idType;
		uint32 id;
		uint8 dlc;
		uint8 data0;
		uint8 data1;
		uint8 data2;
		uint8 data3;
		uint8 data4;
		uint8 data5;
		uint8 data6;
		uint8 data7;
	}frame;
}FBL_CANSPI_uCAN_MSG;
typedef union
{
	struct
	{
		unsigned RX0IF      : 1;
		unsigned RX1IF      : 1;
		unsigned TXB0REQ    : 1;
		unsigned TX0IF      : 1;
		unsigned TXB1REQ    : 1;
		unsigned TX1IF      : 1;
		unsigned TXB2REQ    : 1;
		unsigned TX2IF      : 1;
	};
	uint8 CtrlStatus;
}FBL_CANSPI_CtrlStatus_t;
typedef union
{
	struct
	{
		unsigned filter     : 3;
		unsigned msgType    : 2;
		unsigned unusedBit  : 1;
		unsigned rxBuffer   : 2;
	};
	uint8 CtrlRxStatus;
}FBL_CANSPI_CtrlRxStatus_t;
typedef union
{
	struct
	{
		unsigned EWARN      :1;
		unsigned RXWAR      :1;
		unsigned TXWAR      :1;
		unsigned RXEP       :1;
		unsigned TXEP       :1;
		unsigned TXBO       :1;
		unsigned RX0OVR     :1;
		unsigned RX1OVR     :1;
	};
	uint8 CtrlErrorStatus;
}FBL_CANSPI_CtrlErrorStatus_t;
typedef union
{
	struct
	{
		uint8_t RXBnSIDH;
		uint8_t RXBnSIDL;
		uint8_t RXBnEID8;
		uint8_t RXBnEID0;
		uint8_t RXBnDLC;
		uint8_t RXBnD0;
		uint8_t RXBnD1;
		uint8_t RXBnD2;
		uint8_t RXBnD3;
		uint8_t RXBnD4;
		uint8_t RXBnD5;
		uint8_t RXBnD6;
		uint8_t RXBnD7;
	};
	uint8 rx_reg_array[13];
}FBL_CANSPI_rx_reg_t;
typedef struct
{
	uint8 RXF0SIDH;
	uint8 RXF0SIDL;
	uint8 RXF0EID8;
	uint8 RXF0EID0;
}FBL_CANSPI_RXF0;
typedef struct
{
	uint8 RXF1SIDH;
	uint8 RXF1SIDL;
	uint8 RXF1EID8;
	uint8 RXF1EID0;
}FBL_CANSPI_RXF1;
typedef struct
{
	uint8 RXF2SIDH;
	uint8 RXF2SIDL;
	uint8 RXF2EID8;
	uint8 RXF2EID0;
}FBL_CANSPI_RXF2;
typedef struct
{
	uint8 RXF3SIDH;
	uint8 RXF3SIDL;
	uint8 RXF3EID8;
	uint8 RXF3EID0;
}FBL_CANSPI_RXF3;
typedef struct
{
	uint8 RXF4SIDH;
	uint8 RXF4SIDL;
	uint8 RXF4EID8;
	uint8 RXF4EID0;
}FBL_CANSPI_RXF4;

typedef struct
{
	uint8 RXF5SIDH;
	uint8 RXF5SIDL;
	uint8 RXF5EID8;
	uint8 RXF5EID0;
}FBL_CANSPI_RXF5;
typedef struct
{
	uint8 RXM0SIDH;
	uint8 RXM0SIDL;
	uint8 RXM0EID8;
	uint8 RXM0EID0;
}FBL_CANSPI_RXM0;
typedef struct
{
	uint8 RXM1SIDH;
	uint8 RXM1SIDL;
	uint8 RXM1EID8;
	uint8 RXM1EID0;
}FBL_CANSPI_RXM1;
typedef struct
{
	uint8 tempSIDH;
	uint8 tempSIDL;
	uint8 tempEID8;
	uint8 tempEID0;
}FBL_CANSPI_id_reg_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SESSIONSTATUS_ADDR 						0x2001fdc0
#define NCR_START_ADDRESS 						0x2001F30C
#define NCR_END_ADDRESS   						0x2001FFFF
#define FBL_BLU_RAM_EXECUTION_ADDRESS 			0x20001000
#define NCR_SIZE          						(NCR_END_ADDRESS - NCR_START_ADDRESS + 1)
#define APPL_START_ADDRESS 						0x800C000
#define FBL_START_ADDRESS 						0x8000000
#define FBL_CANSPI_MCP2515_RESET           		0xC0
#define FBL_CANSPI_MCP2515_READ            		0x03
#define FBL_CANSPI_MCP2515_READ_RXB0SIDH   		0x90
#define FBL_CANSPI_MCP2515_READ_RXB0D0     		0x92
#define FBL_CANSPI_MCP2515_READ_RXB1SIDH   		0x94
#define FBL_CANSPI_MCP2515_READ_RXB1D0     		0x96
#define FBL_CANSPI_MCP2515_WRITE           		0x02
#define FBL_CANSPI_MCP2515_LOAD_TXB0SIDH   		0x40
#define FBL_CANSPI_MCP2515_LOAD_TXB0D0     		0x41
#define FBL_CANSPI_MCP2515_LOAD_TXB1SIDH   		0x42
#define FBL_CANSPI_MCP2515_LOAD_TXB1D0     		0x43
#define FBL_CANSPI_MCP2515_LOAD_TXB2SIDH   		0x44
#define FBL_CANSPI_MCP2515_LOAD_TXB2D0     		0x45
#define FBL_CANSPI_MCP2515_RTS_TX0         		0x81
#define FBL_CANSPI_MCP2515_RTS_TX1         		0x82
#define FBL_CANSPI_MCP2515_RTS_TX2         		0x84
#define FBL_CANSPI_MCP2515_RTS_ALL        		0x87
#define FBL_CANSPI_MCP2515_READ_STATUS    		0xA0
#define FBL_CANSPI_MCP2515_RX_STATUS       		0xB0
#define FBL_CANSPI_MCP2515_BIT_MOD         		0x05
#define FBL_CANSPI_MCP2515_RXF0SIDH				0x00
#define FBL_CANSPI_MCP2515_RXF0SIDL				0x01
#define FBL_CANSPI_MCP2515_RXF0EID8				0x02
#define FBL_CANSPI_MCP2515_RXF0EID0				0x03
#define FBL_CANSPI_MCP2515_RXF1SIDH				0x04
#define FBL_CANSPI_MCP2515_RXF1SIDL				0x05
#define FBL_CANSPI_MCP2515_RXF1EID8				0x06
#define FBL_CANSPI_MCP2515_RXF1EID0				0x07
#define FBL_CANSPI_MCP2515_RXF2SIDH				0x08
#define FBL_CANSPI_MCP2515_RXF2SIDL				0x09
#define FBL_CANSPI_MCP2515_RXF2EID8				0x0A
#define FBL_CANSPI_MCP2515_RXF2EID0				0x0B
#define FBL_CANSPI_MCP2515_CANSTAT				0x0E
#define FBL_CANSPI_MCP2515_CANCTRL				0x0F
#define FBL_CANSPI_MCP2515_RXF3SIDH				0x10
#define FBL_CANSPI_MCP2515_RXF3SIDL				0x11
#define FBL_CANSPI_MCP2515_RXF3EID8				0x12
#define FBL_CANSPI_MCP2515_RXF3EID0				0x13
#define FBL_CANSPI_MCP2515_RXF4SIDH				0x14
#define FBL_CANSPI_MCP2515_RXF4SIDL				0x15
#define FBL_CANSPI_MCP2515_RXF4EID8				0x16
#define FBL_CANSPI_MCP2515_RXF4EID0				0x17
#define FBL_CANSPI_MCP2515_RXF5SIDH				0x18
#define FBL_CANSPI_MCP2515_RXF5SIDL				0x19
#define FBL_CANSPI_MCP2515_RXF5EID8				0x1A
#define FBL_CANSPI_MCP2515_RXF5EID0				0x1B
#define FBL_CANSPI_MCP2515_TEC					0x1C
#define FBL_CANSPI_MCP2515_REC					0x1D
#define FBL_CANSPI_MCP2515_RXM0SIDH				0x20
#define FBL_CANSPI_MCP2515_RXM0SIDL				0x21
#define FBL_CANSPI_MCP2515_RXM0EID8				0x22
#define FBL_CANSPI_MCP2515_RXM0EID0				0x23
#define FBL_CANSPI_MCP2515_RXM1SIDH				0x24
#define FBL_CANSPI_MCP2515_RXM1SIDL				0x25
#define FBL_CANSPI_MCP2515_RXM1EID8				0x26
#define FBL_CANSPI_MCP2515_RXM1EID0				0x27
#define FBL_CANSPI_MCP2515_CNF3					0x28
#define FBL_CANSPI_MCP2515_CNF2					0x29
#define FBL_CANSPI_MCP2515_CNF1					0x2A
#define FBL_CANSPI_MCP2515_CANINTE				0x2B
#define FBL_CANSPI_MCP2515_CANINTF				0x2C
#define FBL_CANSPI_MCP2515_EFLG					0x2D
#define FBL_CANSPI_MCP2515_TXB0CTRL				0x30
#define FBL_CANSPI_MCP2515_TXB1CTRL				0x40
#define FBL_CANSPI_MCP2515_TXB2CTRL				0x50
#define FBL_CANSPI_MCP2515_RXB0CTRL				0x60
#define FBL_CANSPI_MCP2515_RXB0SIDH				0x61
#define FBL_CANSPI_MCP2515_RXB1CTRL				0x70
#define FBL_CANSPI_MCP2515_RXB1SIDH				0x71
#define FBL_CANSPI_MSG_IN_RXB0             		0x01
#define FBL_CANSPI_MSG_IN_RXB1             		0x02
#define FBL_CANSPI_MSG_IN_BOTH_BUFFERS     		0x03
#define FBL_CANSPI_dSTANDARD_CAN_MSG_ID_2_0B 	1
#define FBL_CANSPI_dEXTENDED_CAN_MSG_ID_2_0B 	2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define FBL_CANSPI_SPI_CAN                 	&hspi1
#define FBL_CANSPI_MCP2515_CS_HIGH()   		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET)
#define FBL_CANSPI_MCP2515_CS_LOW()    		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET)
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
FBL_CANSPI_uCAN_MSG FBL_RxFrame = {0};
FBL_CANSPI_uCAN_MSG FBL_TxFrame = {0};
uint32* FBL_DSC_Pointer = (uint32*)(SESSIONSTATUS_ADDR);
FBL_DSC_t FBL_DSC_State = JUMPTOAPPL;
uint32 FBL_ProgrammingData = 0;
uint32 FBL_ProgrammingIndex = 0;
uint32 FBL_ProgrammingAddress = 0;
uint32 ROM_APPL_START_ADDR_storedValue = 0;
uint32 ROM_APPL_START_ADDR = 0x080601A0;
uint32 FBL_DSC_Status = 0;
FBL_CANSPI_id_reg_t FBL_idReg = {0};
FBL_CANSPI_CtrlStatus_t FBL_ctrlStatus = {0};
FBL_CANSPI_CtrlErrorStatus_t FBL_errorStatus = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */
void FBL_JumpToAppl(void);
void FBL_DiagRoutine_ER_SoftReset(void);
void FBL_DiagRoutine_ER_HardReset(void);
void FBL_DiagRoutine_DSC_Programming(void);
void FBL_DiagRoutine_DSC_Coding(void);
void FBL_DiagRoutine_DSC_Calibration(void);
void FBL_DiagRoutine_DSC_RequestDownload(void);
void FBL_DiagRoutine_DSC_TransferData(void);
void FBL_DiagRoutine_DSC_RequestTransferExit(void);
void FBL_DiagRoutine_RAR_MassEraseAPPL(void);
void FBL_DiagRoutine_RAR_MassEraseCODING(void);
void FBL_DiagRoutine_RAR_MassEraseCALIBRATION(void);
void FBL_DiagRoutine_RDBI_ReadActiveDiagnosticSession(void);
void FBL_NvM_FlashReadData(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords);
uint32 FBL_NvM_FlashWriteData(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords);
uint32 FBL_NvM_EraseFlash_APPL(void);
uint32 FBL_NvM_EraseFlash_CODING(void);
uint32 FBL_NvM_EraseFlash_CALIBRATION(void);
uint32 FBL_NvM_GetSector(uint32 Address);
uint32 FBL_CanSpi_ConvertReg2ExtendedCANid(uint8 tempRXBn_EIDH, uint8 tempRXBn_EIDL, uint8 tempRXBn_SIDH, uint8 tempRXBn_SIDL);
uint32 FBL_CanSpi_ConvertReg2StandardCANid(uint8 tempRXBn_SIDH, uint8 tempRXBn_SIDL);
uint8 FBL_CanSpi_SPI_Rx(void);
void FBL_CanSpi_ConvertCANid2Reg(uint32 tempPassedInID, uint8 canIdType, FBL_CANSPI_id_reg_t *passedIdReg);
void FBL_CanSpi_SPI_Tx(uint8 data);
void FBL_CanSpi_SPI_TxBuffer(uint8 *buffer, uint8 length);
void FBL_CanSpi_SPI_RxBuffer(uint8 *buffer, uint8 length);
void FBL_CanSpi_MCP2515_Reset(void);
void FBL_CanSpi_MCP2515_BitModify(uint8 address, uint8 mask, uint8 data);
void FBL_CanSpi_MCP2515_ReadRxSequence(uint8 instruction, uint8 *data, uint8 length);
void FBL_CanSpi_MCP2515_WriteByte(uint8 address, uint8 data);
void FBL_CanSpi_MCP2515_WriteByteSequence(uint8 startAddress, uint8 endAddress, uint8 *data);
void FBL_CanSpi_MCP2515_LoadTxSequence(uint8 instruction, uint8 *idReg, uint8 dlc, uint8 *data);
void FBL_CanSpi_MCP2515_RequestToSend(uint8 instruction);
uint32 FBL_CanSpi_MessagesInBuffer(void);
uint8 FBL_CanSpi_MCP2515_ReadByte (uint8 address);
uint8 FBL_CanSpi_IsRxErrorPassive(void);
uint8 FBL_CanSpi_IsTxErrorPassive(void);
uint8 FBL_CanSpi_MCP2515_ReadStatus(void);
uint8 FBL_CanSpi_MCP2515_GetRxStatus(void);
bool FBL_CanSpi_MCP2515_Initialize(void);
bool FBL_CanSpi_MCP2515_SetConfigMode(void);
bool FBL_CanSpi_MCP2515_SetNormalMode(void);
bool FBL_CanSpi_MCP2515_SetSleepMode(void);
void FBL_CanSpi_Sleep(void);
uint8 FBL_CanSpi_Initialize(void);
uint8 FBL_CanSpi_Transmit(FBL_CANSPI_uCAN_MSG *tempCanMsg);
uint8 FBL_CanSpi_Receive(FBL_CANSPI_uCAN_MSG *tempCanMsg);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
	FBL_ProgrammingAddress = 0;
	FBL_ProgrammingIndex = 0;
	FBL_CanSpi_Initialize();
	FBL_NvM_FlashReadData(ROM_APPL_START_ADDR, &ROM_APPL_START_ADDR_storedValue, 1);
	if(ROM_APPL_START_ADDR_storedValue != 0xFFFFFFFF)
	{
		FBL_DSC_Pointer = (uint32*)(SESSIONSTATUS_ADDR);
		FBL_DSC_Status = *FBL_DSC_Pointer;
	}
	else
	{
		/* Do nothing. */
	}
	if((FBL_DSC_Status == PROGRAMMING) || (FBL_DSC_Status == SOFTRESET) || (FBL_DSC_Status == HARDRESET) || (FBL_DSC_Status == CODING) || (FBL_DSC_Status == CALIBRATION)) FBL_DSC_State = FBL_DSC_Status;
	else
	{
		if(ROM_APPL_START_ADDR_storedValue != 0xFFFFFFFF)
		{
			if((RCC->CSR & RCC_CSR_PORRSTF) != 0)
			{
				for(uint32* addr = ((uint32_t*)0x2001FDA8); addr <= ((uint32_t*)0x2001FFFF); addr++) *addr = 0;
				/* Reset the flag. */
				RCC->CSR |= RCC_CSR_PORRSTF;
			}/* Check if brown-out reset wake-up event occurred.*/
			else if((RCC->CSR & RCC_CSR_BORRSTF) != 0)
			{
				for(uint32* addr = ((uint32_t*)0x2001FDA8); addr <= ((uint32_t*)0x2001FFFF); addr++) *addr = 0;
				/* Reset the flag. */
				RCC->CSR |= RCC_CSR_BORRSTF;
			}
			else
			{
				/* Do nothing. */
			}
			FBL_JumpToAppl();
		}
		else
		{
			/* Do nothing. */
		}
	}
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		switch(FBL_DSC_State)
		{
		case CODING:
			FBL_DiagRoutine_DSC_Coding();
			break;
		case CALIBRATION:
			FBL_DiagRoutine_DSC_Calibration();
			break;
		case PROGRAMMING:
			FBL_DiagRoutine_DSC_Programming();
			break;
		case HARDRESET:
			FBL_DiagRoutine_ER_HardReset();
			break;
		case SOFTRESET:
			FBL_DiagRoutine_ER_SoftReset();
			break;
		default:
			if(FBL_CanSpi_Receive(&FBL_RxFrame))
			{
				if(FBL_RxFrame.frame.id == 0x700 && FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x02 && FBL_RxFrame.frame.data0 == 0x02)
				{
					FBL_TxFrame.frame.dlc = 3;
					FBL_TxFrame.frame.id = FBL_RxFrame.frame.id + 1;
					FBL_TxFrame.frame.idType = 1;
					FBL_TxFrame.frame.data0 = 0x02;
					FBL_TxFrame.frame.data1 = 0x50;
					FBL_TxFrame.frame.data2 = 0x02;
					FBL_CanSpi_Transmit(&FBL_TxFrame);
					FBL_DSC_State = PROGRAMMING;
					FBL_DiagRoutine_DSC_Programming();
				}
				else
				{
					/* Do nothing. */
				}
			}
			else
			{
				/* Do nothing. */
			}
			break;
		}
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* PVD_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(PVD_IRQn);
  /* FLASH_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(FLASH_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(FLASH_IRQn);
  /* RCC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RCC_IRQn);
  /* SPI1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SPI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(SPI1_IRQn);
  /* USART1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* FPU_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(FPU_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(FPU_IRQn);
}

/* USER CODE BEGIN 4 */
void FBL_CanSpi_Sleep(void)
{
	FBL_CanSpi_MCP2515_BitModify(FBL_CANSPI_MCP2515_CANINTF, 0x40, 0x00);
	FBL_CanSpi_MCP2515_BitModify(FBL_CANSPI_MCP2515_CANINTE, 0x40, 0x40);
	FBL_CanSpi_MCP2515_SetSleepMode();
}
uint8 FBL_CanSpi_Initialize(void)
{
	FBL_CanSpi_MCP2515_Reset();
	FBL_CANSPI_RXF0 FBL_RXF0reg;
	FBL_CANSPI_RXF1 FBL_RXF1reg;
	FBL_CANSPI_RXF2 FBL_RXF2reg;
	FBL_CANSPI_RXF3 FBL_RXF3reg;
	FBL_CANSPI_RXF4 FBL_RXF4reg;
	FBL_CANSPI_RXF5 FBL_RXF5reg;
	FBL_CANSPI_RXM0 FBL_RXM0reg;
	FBL_CANSPI_RXM1 FBL_RXM1reg;
	FBL_RXM0reg.RXM0SIDH = 0xFF;
	FBL_RXM0reg.RXM0SIDL = 0xE0;
	FBL_RXM0reg.RXM0EID8 = 0x00;
	FBL_RXM0reg.RXM0EID0 = 0x00;
	FBL_RXM1reg.RXM1SIDH = 0x00;
	FBL_RXM1reg.RXM1SIDL = 0x00;
	FBL_RXM1reg.RXM1EID8 = 0x00;
	FBL_RXM1reg.RXM1EID0 = 0x00;
	FBL_RXF0reg.RXF0SIDH = (0x701 >> 3) & 0xFF;
	FBL_RXF0reg.RXF0SIDL = (0x701 << 5) & 0xE0;
	FBL_RXF0reg.RXF0EID8 = 0x00;
	FBL_RXF0reg.RXF0EID0 = 0x00;
	FBL_RXF1reg.RXF1SIDH = 0x00;
	FBL_RXF1reg.RXF1SIDL = 0x08;
	FBL_RXF1reg.RXF1EID8 = 0x00;
	FBL_RXF1reg.RXF1EID0 = 0x00;
	FBL_RXF2reg.RXF2SIDH = 0x00;
	FBL_RXF2reg.RXF2SIDL = 0x00;
	FBL_RXF2reg.RXF2EID8 = 0x00;
	FBL_RXF2reg.RXF2EID0 = 0x00;
	FBL_RXF3reg.RXF3SIDH = 0x00;
	FBL_RXF3reg.RXF3SIDL = 0x00;
	FBL_RXF3reg.RXF3EID8 = 0x00;
	FBL_RXF3reg.RXF3EID0 = 0x00;
	FBL_RXF4reg.RXF4SIDH = 0x00;
	FBL_RXF4reg.RXF4SIDL = 0x00;
	FBL_RXF4reg.RXF4EID8 = 0x00;
	FBL_RXF4reg.RXF4EID0 = 0x00;
	FBL_RXF5reg.RXF5SIDH = 0x00;
	FBL_RXF5reg.RXF5SIDL = 0x08;
	FBL_RXF5reg.RXF5EID8 = 0x00;
	FBL_RXF5reg.RXF5EID0 = 0x00;
	FBL_CanSpi_MCP2515_Initialize();
	FBL_CanSpi_MCP2515_SetConfigMode();
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXM0SIDH, FBL_CANSPI_MCP2515_RXM0EID0, &(FBL_RXM0reg.RXM0SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXM1SIDH, FBL_CANSPI_MCP2515_RXM1EID0, &(FBL_RXM1reg.RXM1SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXF0SIDH, FBL_CANSPI_MCP2515_RXF0EID0, &(FBL_RXF0reg.RXF0SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXF1SIDH, FBL_CANSPI_MCP2515_RXF1EID0, &(FBL_RXF1reg.RXF1SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXF2SIDH, FBL_CANSPI_MCP2515_RXF2EID0, &(FBL_RXF2reg.RXF2SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXF3SIDH, FBL_CANSPI_MCP2515_RXF3EID0, &(FBL_RXF3reg.RXF3SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXF4SIDH, FBL_CANSPI_MCP2515_RXF4EID0, &(FBL_RXF4reg.RXF4SIDH));
	FBL_CanSpi_MCP2515_WriteByteSequence(FBL_CANSPI_MCP2515_RXF5SIDH, FBL_CANSPI_MCP2515_RXF5EID0, &(FBL_RXF5reg.RXF5SIDH));
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_RXB0CTRL, 0x04);
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_RXB1CTRL, 0x01);
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_CNF1, 0x00);
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_CNF2, 0x90);
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_CNF3, 0x82);
	FBL_CanSpi_MCP2515_SetNormalMode();
	return 1;
}
uint8 FBL_CanSpi_Transmit(FBL_CANSPI_uCAN_MSG *tempCanMsg)
{
	uint8 FBL_returnValue = 0;
	FBL_idReg.tempSIDH = 0;
	FBL_idReg.tempSIDL = 0;
	FBL_idReg.tempEID8 = 0;
	FBL_idReg.tempEID0 = 0;
	FBL_ctrlStatus.CtrlStatus = FBL_CanSpi_MCP2515_ReadStatus();
	if (FBL_ctrlStatus.TXB0REQ != 1)
	{
		FBL_CanSpi_ConvertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &FBL_idReg);
		FBL_CanSpi_MCP2515_LoadTxSequence(FBL_CANSPI_MCP2515_LOAD_TXB0SIDH, &(FBL_idReg.tempSIDH), tempCanMsg->frame.dlc, &(tempCanMsg->frame.data0));
		FBL_CanSpi_MCP2515_RequestToSend(FBL_CANSPI_MCP2515_RTS_TX0);
		FBL_returnValue = 1;
	}
	else if (FBL_ctrlStatus.TXB1REQ != 1)
	{
		FBL_CanSpi_ConvertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &FBL_idReg);
		FBL_CanSpi_MCP2515_LoadTxSequence(FBL_CANSPI_MCP2515_LOAD_TXB1SIDH, &(FBL_idReg.tempSIDH), tempCanMsg->frame.dlc, &(tempCanMsg->frame.data0));
		FBL_CanSpi_MCP2515_RequestToSend(FBL_CANSPI_MCP2515_RTS_TX1);
		FBL_returnValue = 1;
	}
	else if (FBL_ctrlStatus.TXB2REQ != 1)
	{
		FBL_CanSpi_ConvertCANid2Reg(tempCanMsg->frame.id, tempCanMsg->frame.idType, &FBL_idReg);
		FBL_CanSpi_MCP2515_LoadTxSequence(FBL_CANSPI_MCP2515_LOAD_TXB2SIDH, &(FBL_idReg.tempSIDH), tempCanMsg->frame.dlc, &(tempCanMsg->frame.data0));
		FBL_CanSpi_MCP2515_RequestToSend(FBL_CANSPI_MCP2515_RTS_TX2);
		FBL_returnValue = 1;
	}
	else
	{
		/* Do nothing. */
	}
	return (FBL_returnValue);
}
uint8 FBL_CanSpi_Receive(FBL_CANSPI_uCAN_MSG *tempCanMsg)
{
	uint8 FBL_returnValue = 0;
	FBL_CANSPI_rx_reg_t FBL_rxReg ={0};
	FBL_CANSPI_CtrlRxStatus_t FBL_rxStatus = {0};
	FBL_rxStatus.CtrlRxStatus = FBL_CanSpi_MCP2515_GetRxStatus();
	if (FBL_rxStatus.rxBuffer != 0)
	{
		if ((FBL_rxStatus.rxBuffer == FBL_CANSPI_MSG_IN_RXB0)|(FBL_rxStatus.rxBuffer == FBL_CANSPI_MSG_IN_BOTH_BUFFERS))
		{
			FBL_CanSpi_MCP2515_ReadRxSequence(FBL_CANSPI_MCP2515_READ_RXB0SIDH, FBL_rxReg.rx_reg_array, sizeof(FBL_rxReg.rx_reg_array));
		}
		else if (FBL_rxStatus.rxBuffer == FBL_CANSPI_MSG_IN_RXB1)
		{
			FBL_CanSpi_MCP2515_ReadRxSequence(FBL_CANSPI_MCP2515_READ_RXB1SIDH, FBL_rxReg.rx_reg_array, sizeof(FBL_rxReg.rx_reg_array));
		}
		if (FBL_rxStatus.msgType == FBL_CANSPI_dEXTENDED_CAN_MSG_ID_2_0B)
		{
			tempCanMsg->frame.idType = (uint8) FBL_CANSPI_dEXTENDED_CAN_MSG_ID_2_0B;
			tempCanMsg->frame.id = FBL_CanSpi_ConvertReg2ExtendedCANid(FBL_rxReg.RXBnEID8, FBL_rxReg.RXBnEID0, FBL_rxReg.RXBnSIDH, FBL_rxReg.RXBnSIDL);
		}
		else
		{
			tempCanMsg->frame.idType = (uint8) FBL_CANSPI_dSTANDARD_CAN_MSG_ID_2_0B;
			tempCanMsg->frame.id = FBL_CanSpi_ConvertReg2StandardCANid(FBL_rxReg.RXBnSIDH, FBL_rxReg.RXBnSIDL);
		}
		tempCanMsg->frame.dlc   = FBL_rxReg.RXBnDLC;
		tempCanMsg->frame.data0 = FBL_rxReg.RXBnD0;
		tempCanMsg->frame.data1 = FBL_rxReg.RXBnD1;
		tempCanMsg->frame.data2 = FBL_rxReg.RXBnD2;
		tempCanMsg->frame.data3 = FBL_rxReg.RXBnD3;
		tempCanMsg->frame.data4 = FBL_rxReg.RXBnD4;
		tempCanMsg->frame.data5 = FBL_rxReg.RXBnD5;
		tempCanMsg->frame.data6 = FBL_rxReg.RXBnD6;
		tempCanMsg->frame.data7 = FBL_rxReg.RXBnD7;
		FBL_returnValue = 1;
	}
	else
	{
		/* Do nothing. */
	}
	return (FBL_returnValue);
}
uint32 FBL_CanSpi_MessagesInBuffer(void)
{
	uint8 FBL_messageCount = 0;
	FBL_ctrlStatus.CtrlStatus = FBL_CanSpi_MCP2515_ReadStatus();
	if(FBL_ctrlStatus.RX0IF != 0) FBL_messageCount++;
	else
	{
		/* Do nothing */
	}
	if(FBL_ctrlStatus.RX1IF != 0) FBL_messageCount++;
	else
	{
		/* Do nothing */
	}
	return (FBL_messageCount);
}
uint8 CanSpi_IsBussOff(void)
{
	uint8 FBL_returnValue = 0;
	FBL_errorStatus.CtrlErrorStatus = FBL_CanSpi_MCP2515_ReadByte(FBL_CANSPI_MCP2515_EFLG);
	if(FBL_errorStatus.TXBO == 1) FBL_returnValue = 1;
	else
	{
		/* Do nothing. */
	}
	return (FBL_returnValue);
}
uint8 FBL_CanSpi_IsRxErrorPassive(void)
{
	uint8 FBL_returnValue = 0;
	FBL_errorStatus.CtrlErrorStatus = FBL_CanSpi_MCP2515_ReadByte(FBL_CANSPI_MCP2515_EFLG);
	if(FBL_errorStatus.RXEP == 1) FBL_returnValue = 1;
	else
	{
		/* Do nothing. */
	}

	return (FBL_returnValue);
}
uint8 FBL_CanSpi_IsTxErrorPassive(void)
{
	uint8 FBL_returnValue = 0;
	FBL_errorStatus.CtrlErrorStatus = FBL_CanSpi_MCP2515_ReadByte(FBL_CANSPI_MCP2515_EFLG);
	if(FBL_errorStatus.TXEP == 1) FBL_returnValue = 1;
	else
	{
		/* Do nothing. */
	}
	return (FBL_returnValue);
}
uint32 FBL_CanSpi_ConvertReg2ExtendedCANid(uint8 tempRXBn_EIDH, uint8 tempRXBn_EIDL, uint8 tempRXBn_SIDH, uint8 tempRXBn_SIDL)
{
	static uint32 returnValue = 0;
	static uint32 ConvertedID = 0;
	static uint8 CAN_standardLo_ID_lo2bits;
	static uint8 CAN_standardLo_ID_hi3bits;
	CAN_standardLo_ID_lo2bits = (tempRXBn_SIDL & 0x03);
	CAN_standardLo_ID_hi3bits = (tempRXBn_SIDL >> 5);
	ConvertedID = (tempRXBn_SIDH << 3);
	ConvertedID = ConvertedID + CAN_standardLo_ID_hi3bits;
	ConvertedID = (ConvertedID << 2);
	ConvertedID = ConvertedID + CAN_standardLo_ID_lo2bits;
	ConvertedID = (ConvertedID << 8);
	ConvertedID = ConvertedID + tempRXBn_EIDH;
	ConvertedID = (ConvertedID << 8);
	ConvertedID = ConvertedID + tempRXBn_EIDL;
	returnValue = ConvertedID;
	return (returnValue);
}
uint32 FBL_CanSpi_ConvertReg2StandardCANid(uint8 tempRXBn_SIDH, uint8 tempRXBn_SIDL)
{
	static uint32 returnValue = 0;
	static uint32 ConvertedID = 0;
	ConvertedID = (tempRXBn_SIDH << 3);
	ConvertedID = ConvertedID + (tempRXBn_SIDL >> 5);
	returnValue = ConvertedID;
	return (returnValue);
}
void FBL_CanSpi_ConvertCANid2Reg(uint32 tempPassedInID, uint8 canIdType, FBL_CANSPI_id_reg_t *passedIdReg)
{
	static uint8 wipSIDL = 0;
	if (canIdType == FBL_CANSPI_dEXTENDED_CAN_MSG_ID_2_0B)
	{
		passedIdReg->tempEID0 = 0xFF & tempPassedInID;
		tempPassedInID = tempPassedInID >> 8;
		passedIdReg->tempEID8 = 0xFF & tempPassedInID;
		tempPassedInID = tempPassedInID >> 8;
		wipSIDL = 0x03 & tempPassedInID;
		tempPassedInID = tempPassedInID << 3;
		wipSIDL = (0xE0 & tempPassedInID) + wipSIDL;
		wipSIDL = wipSIDL + 0x08;
		passedIdReg->tempSIDL = 0xEB & wipSIDL;
		tempPassedInID = tempPassedInID >> 8;
		passedIdReg->tempSIDH = 0xFF & tempPassedInID;
	}
	else
	{
		passedIdReg->tempEID8 = 0;
		passedIdReg->tempEID0 = 0;
		tempPassedInID = tempPassedInID << 5;
		passedIdReg->tempSIDL = 0xFF & tempPassedInID;
		tempPassedInID = tempPassedInID >> 8;
		passedIdReg->tempSIDH = 0xFF & tempPassedInID;
	}
}
bool FBL_CanSpi_MCP2515_Initialize(void)
{
	uint8 loop = 10;
	FBL_CANSPI_MCP2515_CS_HIGH();
	do
	{
		if(HAL_SPI_GetState(FBL_CANSPI_SPI_CAN) == HAL_SPI_STATE_READY) return true;
		else
		{
			/* Do nothing. */
		}
		loop--;
	}while(loop > 0);
	return false;
}
bool FBL_CanSpi_MCP2515_SetConfigMode(void)
{
	uint8 loop = 10;
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_CANCTRL, 0x80);
	do
	{
		if((FBL_CanSpi_MCP2515_ReadByte(FBL_CANSPI_MCP2515_CANSTAT) & 0xE0) == 0x80) return true;
		else
		{
			/* Do nothing. */
		}
		loop--;
	}while(loop > 0);
	return false;
}
bool FBL_CanSpi_MCP2515_SetNormalMode(void)
{
	uint8 loop = 10;
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_CANCTRL, 0x00);
	do
	{
		if((FBL_CanSpi_MCP2515_ReadByte(FBL_CANSPI_MCP2515_CANSTAT) & 0xE0) == 0x00) return true;
		else
		{
			/* Do nothing. */
		}
		loop--;
	}while(loop > 0);
	return false;
}
bool FBL_CanSpi_MCP2515_SetSleepMode(void)
{
	uint8 loop = 10;
	FBL_CanSpi_MCP2515_WriteByte(FBL_CANSPI_MCP2515_CANCTRL, 0x20);
	do
	{
		if((FBL_CanSpi_MCP2515_ReadByte(FBL_CANSPI_MCP2515_CANSTAT) & 0xE0) == 0x20) return true;
		else
		{
			/* Do nothing. */
		}

		loop--;
	}while(loop > 0);
	return false;
}
void FBL_CanSpi_MCP2515_Reset(void)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_RESET);
	FBL_CANSPI_MCP2515_CS_HIGH();
}
uint8 FBL_CanSpi_MCP2515_ReadByte (uint8 address)
{
	static uint8 FBL_retVal = 0;
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_READ);
	FBL_CanSpi_SPI_Tx(address);
	FBL_retVal = FBL_CanSpi_SPI_Rx();
	FBL_CANSPI_MCP2515_CS_HIGH();
	return (FBL_retVal);
}
void FBL_CanSpi_MCP2515_ReadRxSequence(uint8 instruction, uint8 *data, uint8 length)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(instruction);
	FBL_CanSpi_SPI_RxBuffer(data, length);
	FBL_CANSPI_MCP2515_CS_HIGH();
}
void FBL_CanSpi_MCP2515_WriteByte(uint8 address, uint8 data)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_WRITE);
	FBL_CanSpi_SPI_Tx(address);
	FBL_CanSpi_SPI_Tx(data);
	FBL_CANSPI_MCP2515_CS_HIGH();
}
void FBL_CanSpi_MCP2515_WriteByteSequence(uint8 startAddress, uint8 endAddress, uint8 *data)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_WRITE);
	FBL_CanSpi_SPI_Tx(startAddress);
	FBL_CanSpi_SPI_TxBuffer(data, (endAddress - startAddress + 1));
	FBL_CANSPI_MCP2515_CS_HIGH();
}
void FBL_CanSpi_MCP2515_LoadTxSequence(uint8 instruction, uint8 *idReg, uint8 dlc, uint8 *data)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(instruction);
	FBL_CanSpi_SPI_TxBuffer(idReg, 4);
	FBL_CanSpi_SPI_Tx(dlc);
	FBL_CanSpi_SPI_TxBuffer(data, dlc);
	FBL_CANSPI_MCP2515_CS_HIGH();
}
void FBL_CanSpi_MCP2515_RequestToSend(uint8 instruction)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(instruction);
	FBL_CANSPI_MCP2515_CS_HIGH();
}
uint8 FBL_CanSpi_MCP2515_ReadStatus(void)
{
	static uint8 FBL_retVal = 0;
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_READ_STATUS);
	FBL_retVal = FBL_CanSpi_SPI_Rx();
	FBL_CANSPI_MCP2515_CS_HIGH();
	return FBL_retVal;
}
uint8 FBL_CanSpi_MCP2515_GetRxStatus(void)
{
	static uint8 FBL_retVal = 0;
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_RX_STATUS);
	FBL_retVal = FBL_CanSpi_SPI_Rx();
	FBL_CANSPI_MCP2515_CS_HIGH();
	return FBL_retVal;
}
void FBL_CanSpi_MCP2515_BitModify(uint8 address, uint8 mask, uint8 data)
{
	FBL_CANSPI_MCP2515_CS_LOW();
	FBL_CanSpi_SPI_Tx(FBL_CANSPI_MCP2515_BIT_MOD);
	FBL_CanSpi_SPI_Tx(address);
	FBL_CanSpi_SPI_Tx(mask);
	FBL_CanSpi_SPI_Tx(data);
	FBL_CANSPI_MCP2515_CS_HIGH();
}
void FBL_CanSpi_SPI_Tx(uint8 data)
{
	HAL_SPI_Transmit(FBL_CANSPI_SPI_CAN, &data, 1, 3);
}
void FBL_CanSpi_SPI_TxBuffer(uint8 *buffer, uint8 length)
{
	HAL_SPI_Transmit(FBL_CANSPI_SPI_CAN, buffer, length, 3);
}
uint8 FBL_CanSpi_SPI_Rx(void)
{
	static uint8 FBL_retVal = 0;

	HAL_SPI_Receive(FBL_CANSPI_SPI_CAN, &FBL_retVal, 1, 3);

	return FBL_retVal;
}
void FBL_CanSpi_SPI_RxBuffer(uint8 *buffer, uint8 length)
{
	HAL_SPI_Receive(FBL_CANSPI_SPI_CAN, buffer, length, 3);
}
uint32 FBL_NvM_GetSector(uint32 Address)
{
	uint32 sector = 0;
	if((Address < 0x08003FFF) && (Address >= 0x08000000)) sector = FLASH_SECTOR_0;
	else if((Address < 0x08007FFF) && (Address >= 0x08004000)) sector = FLASH_SECTOR_1;
	else if((Address < 0x0800BFFF) && (Address >= 0x08008000)) sector = FLASH_SECTOR_2;
	else if((Address <= 0x0800FFFF) && (Address >= 0x0800C000)) sector = FLASH_SECTOR_3;
	else if((Address <= 0x0801FFFF) && (Address >= 0x08010000)) sector = FLASH_SECTOR_4;
	else if((Address < 0x0803FFFF) && (Address >= 0x08020000)) sector = FLASH_SECTOR_5;
	else if((Address < 0x0805FFFF) && (Address >= 0x08040000)) sector = FLASH_SECTOR_6;
	else if((Address < 0x0807FFFF) && (Address >= 0x08060000)) sector = FLASH_SECTOR_7;
	else
	{
		/* Do nothing. */
	}
	return sector;
}
uint32 FBL_NvM_EraseFlash_CODING(void)
{
	FLASH_EraseInitTypeDef EraseInitStruct = {0};
	uint32 SECTORError = 0;
	uint32 StartSector = 0;
	uint32 EndSector = 0;
	StartSector = FLASH_SECTOR_3;
	EndSector = FLASH_SECTOR_3;
	HAL_FLASH_Unlock();
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = StartSector;
	EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK) return HAL_FLASH_GetError();
	else
	{
		/* Do nothing. */
	}
	HAL_FLASH_Lock();
	return 0;
}
uint32 FBL_NvM_EraseFlash_CALIBRATION(void)
{
	FLASH_EraseInitTypeDef EraseInitStruct = {0};
	uint32 SECTORError = 0;
	uint32 StartSector = 0;
	uint32 EndSector = 0;
	StartSector = FLASH_SECTOR_2;
	EndSector = FLASH_SECTOR_2;
	HAL_FLASH_Unlock();
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = StartSector;
	EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK) return HAL_FLASH_GetError();
	else
	{
		/* Do nothing. */
	}
	HAL_FLASH_Lock();
	return 0;
}
uint32 FBL_NvM_EraseFlash_APPL(void)
{
	FLASH_EraseInitTypeDef EraseInitStruct = {0};
	uint32 SECTORError = 0;
	uint32 StartSector = 0;
	uint32 EndSector = 0;
	StartSector = FLASH_SECTOR_7;
	EndSector = FLASH_SECTOR_7;
	HAL_FLASH_Unlock();
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = StartSector;
	EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK) return HAL_FLASH_GetError();
	else
	{
		/* Do nothing. */
	}
	HAL_FLASH_Lock();
	return 0;
}
uint32 FBL_NvM_FlashWriteData(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords)
{
	uint32 sofar = 0;
	HAL_FLASH_Unlock();
	while (sofar < numberofwords)
	{
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, StartSectorAddress, Data[sofar]) == HAL_OK)
		{
			StartSectorAddress += 4;
			sofar++;
		}
		else return HAL_FLASH_GetError ();
	}
	HAL_FLASH_Lock();
	return 0;
}
void FBL_NvM_FlashReadData(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords)
{
	for (uint16_t i = 0; i < numberofwords; i++) RxBuf[i] = *(__IO uint32_t *)(StartSectorAddress + (i * 4));
}
void FBL_DiagRoutine_DSC_RequestDownload(void)
{
	FBL_TxFrame.frame.dlc = 8;
	FBL_TxFrame.frame.id = 0x701;
	FBL_TxFrame.frame.idType = 1;
	FBL_TxFrame.frame.data0 = 0x05;
	FBL_TxFrame.frame.data1 = 0x74;
	FBL_TxFrame.frame.data2 = 0x20;
	FBL_TxFrame.frame.data3 = 0x02;
	FBL_TxFrame.frame.data4 = 0x02;
	FBL_CanSpi_Transmit(&FBL_TxFrame);
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
}
void FBL_DiagRoutine_DSC_TransferData(void)
{
	if(FBL_DSC_State == PROGRAMMING)
	{
		FBL_ProgrammingData = (FBL_RxFrame.frame.data6 << 24) | (FBL_RxFrame.frame.data5 << 16) | (FBL_RxFrame.frame.data4 << 8) | FBL_RxFrame.frame.data3;
		__disable_irq();
		FBL_NvM_FlashWriteData(FBL_ProgrammingAddress, &FBL_ProgrammingData, 1);
		__enable_irq();
		FBL_ProgrammingAddress += 4;
		FBL_ProgrammingIndex += 1;
		FBL_TxFrame.frame.dlc = 3;
		FBL_TxFrame.frame.id = 0x701;
		FBL_TxFrame.frame.idType = 1;
		FBL_TxFrame.frame.data0 = 0x02;
		FBL_TxFrame.frame.data1 = 0x76;
		FBL_TxFrame.frame.data2 = 0x01;
		FBL_CanSpi_Transmit(&FBL_TxFrame);
	}
	else if(FBL_DSC_State == CODING)
	{
		FBL_ProgrammingData = (FBL_RxFrame.frame.data6 << 0) | (FBL_RxFrame.frame.data5 << 8) | (FBL_RxFrame.frame.data4 << 16) | (FBL_RxFrame.frame.data3 << 24);
		__disable_irq();
		FBL_NvM_FlashWriteData(FBL_ProgrammingAddress, &FBL_ProgrammingData, 1);
		__enable_irq();
		FBL_ProgrammingAddress += 4;
		FBL_ProgrammingIndex += 1;
		FBL_TxFrame.frame.dlc = 3;
		FBL_TxFrame.frame.id = 0x701;
		FBL_TxFrame.frame.idType = 1;
		FBL_TxFrame.frame.data0 = 0x02;
		FBL_TxFrame.frame.data1 = 0x76;
		FBL_TxFrame.frame.data2 = 0x01;
		FBL_CanSpi_Transmit(&FBL_TxFrame);
	}
	else if(FBL_DSC_State == CALIBRATION)
	{
		FBL_ProgrammingData = (FBL_RxFrame.frame.data6 << 0) | (FBL_RxFrame.frame.data5 << 8) | (FBL_RxFrame.frame.data4 << 16) | (FBL_RxFrame.frame.data3 << 24);
		__disable_irq();
		FBL_NvM_FlashWriteData(FBL_ProgrammingAddress, &FBL_ProgrammingData, 1);
		__enable_irq();
		FBL_ProgrammingAddress += 4;
		FBL_ProgrammingIndex += 1;
		FBL_TxFrame.frame.dlc = 3;
		FBL_TxFrame.frame.id = 0x701;
		FBL_TxFrame.frame.idType = 1;
		FBL_TxFrame.frame.data0 = 0x02;
		FBL_TxFrame.frame.data1 = 0x76;
		FBL_TxFrame.frame.data2 = 0x01;
		FBL_CanSpi_Transmit(&FBL_TxFrame);
	}
	else
	{
		/* Do nothing. */
	}
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
}
void FBL_DiagRoutine_DSC_RequestTransferExit(void)
{
	FBL_TxFrame.frame.dlc = 2;
	FBL_TxFrame.frame.id = 0x701;
	FBL_TxFrame.frame.idType = 1;
	FBL_TxFrame.frame.data0 = 0x01;
	FBL_TxFrame.frame.data1 = 0x77;
	FBL_CanSpi_Transmit(&FBL_TxFrame);
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
}
void FBL_DiagRoutine_RAR_MassEraseCODING(void)
{
	__disable_irq();
	FBL_TxFrame.frame.dlc = 5;
	FBL_TxFrame.frame.id = 0x701;
	FBL_TxFrame.frame.idType = 1;
	FBL_TxFrame.frame.data0 = 0x04;
	FBL_TxFrame.frame.data1 = 0x71;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0x03;
	FBL_CanSpi_Transmit(&FBL_TxFrame);
	FBL_NvM_EraseFlash_CODING();
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
	__enable_irq();
}
void FBL_DiagRoutine_RAR_MassEraseCALIBRATION(void)
{
	__disable_irq();
	FBL_TxFrame.frame.dlc = 5;
	FBL_TxFrame.frame.id = 0x701;
	FBL_TxFrame.frame.idType = 1;
	FBL_TxFrame.frame.data0 = 0x04;
	FBL_TxFrame.frame.data1 = 0x71;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0x02;
	FBL_CanSpi_Transmit(&FBL_TxFrame);
	FBL_NvM_EraseFlash_CALIBRATION();
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
	__enable_irq();
}
void FBL_DiagRoutine_RAR_MassEraseAPPL(void)
{
	__disable_irq();
	FBL_TxFrame.frame.dlc = 5;
	FBL_TxFrame.frame.id = 0x701;
	FBL_TxFrame.frame.idType = 1;
	FBL_TxFrame.frame.data0 = 0x04;
	FBL_TxFrame.frame.data1 = 0x71;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_CanSpi_Transmit(&FBL_TxFrame);
	FBL_NvM_EraseFlash_APPL();
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
	__enable_irq();
}
void FBL_JumpToAppl(void)
{
	typedef void (*pFunction)(void);
	static uint32 app_address = 0x08060000;
	static pFunction app_entry;
	uint32 msp_value = *((uint32*)app_address);
	__disable_irq();
	SCB->VTOR = app_address;
	__set_MSP(msp_value);
	app_entry = (pFunction)(*((uint32*)(app_address + 4)));
	app_entry();
}
void FBL_DiagRoutine_ER_SoftReset(void)
{
	__disable_irq();
	*FBL_DSC_Pointer = 0;
	__NVIC_SystemReset();
}
void FBL_DiagRoutine_ER_HardReset(void)
{
	__disable_irq();
	*FBL_DSC_Pointer = 0;
	for(uint32* addr = ((uint32_t*)0x2001FDA8); addr <= ((uint32_t*)0x2001FFFF); addr++) *addr = 0;
	__NVIC_SystemReset();
}
void FBL_DiagRoutine_DSC_Coding(void)
{
	if(FBL_CanSpi_Receive(&FBL_RxFrame) != 0)
	{
		if(FBL_RxFrame.frame.id == 0x700)
		{
			if(FBL_RxFrame.frame.data1 == 0x22 && FBL_RxFrame.frame.data2 == 0xF1 && FBL_RxFrame.frame.data3 == 0x86) FBL_DiagRoutine_RDBI_ReadActiveDiagnosticSession();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data0 == 0x04 && FBL_RxFrame.frame.data1 == 0x31 && FBL_RxFrame.frame.data4 == 0x03) FBL_DiagRoutine_RAR_MassEraseCODING();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x34)
			{
				if(FBL_ProgrammingAddress == 0) FBL_ProgrammingAddress = 0x0800C000;
				else
				{
					/* Do nothing. */
				}
				FBL_DiagRoutine_DSC_RequestDownload();
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x36) FBL_DiagRoutine_DSC_TransferData();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x05)
			{
				FBL_DSC_State = CALIBRATION;
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x50;
				FBL_TxFrame.frame.data2 = 0x05;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_DSC_Calibration();
				FBL_TxFrame.frame.dlc = 0;
				FBL_TxFrame.frame.id = 0;
				FBL_TxFrame.frame.idType = 0;
				FBL_TxFrame.frame.data0 = 0;
				FBL_TxFrame.frame.data1 = 0;
				FBL_TxFrame.frame.data2 = 0;
				FBL_TxFrame.frame.data3 = 0;
				FBL_TxFrame.frame.data4 = 0;
				FBL_TxFrame.frame.data5 = 0;
				FBL_TxFrame.frame.data6 = 0;
				FBL_TxFrame.frame.data7 = 0;
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x02)
			{
				FBL_DSC_State = PROGRAMMING;
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x50;
				FBL_TxFrame.frame.data2 = 0x02;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_DSC_Calibration();
				FBL_TxFrame.frame.dlc = 0;
				FBL_TxFrame.frame.id = 0;
				FBL_TxFrame.frame.idType = 0;
				FBL_TxFrame.frame.data0 = 0;
				FBL_TxFrame.frame.data1 = 0;
				FBL_TxFrame.frame.data2 = 0;
				FBL_TxFrame.frame.data3 = 0;
				FBL_TxFrame.frame.data4 = 0;
				FBL_TxFrame.frame.data5 = 0;
				FBL_TxFrame.frame.data6 = 0;
				FBL_TxFrame.frame.data7 = 0;
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x37 && FBL_RxFrame.frame.data0 == 0x01) FBL_DiagRoutine_DSC_RequestTransferExit();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x11 && FBL_RxFrame.frame.data2 == 0x01 && FBL_RxFrame.frame.data0 == 0x02)
			{
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x51;
				FBL_TxFrame.frame.data2 = 0x01;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_ER_HardReset();
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
		FBL_RxFrame.frame.dlc = 0;
		FBL_RxFrame.frame.id = 0;
		FBL_RxFrame.frame.idType = 0;
		FBL_RxFrame.frame.data0 = 0;
		FBL_RxFrame.frame.data1 = 0;
		FBL_RxFrame.frame.data2 = 0;
		FBL_RxFrame.frame.data3 = 0;
		FBL_RxFrame.frame.data4 = 0;
		FBL_RxFrame.frame.data5 = 0;
		FBL_RxFrame.frame.data6 = 0;
		FBL_RxFrame.frame.data7 = 0;
	}
}
void FBL_DiagRoutine_DSC_Calibration(void)
{
	if(FBL_CanSpi_Receive(&FBL_RxFrame) != 0)
	{
		if(FBL_RxFrame.frame.id == 0x700)
		{
			if(FBL_RxFrame.frame.data1 == 0x22 && FBL_RxFrame.frame.data2 == 0xF1 && FBL_RxFrame.frame.data3 == 0x86) FBL_DiagRoutine_RDBI_ReadActiveDiagnosticSession();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data0 == 0x04 && FBL_RxFrame.frame.data1 == 0x31 && FBL_RxFrame.frame.data4 == 0x02) FBL_DiagRoutine_RAR_MassEraseCALIBRATION();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x34)
			{
				if(FBL_ProgrammingAddress == 0) FBL_ProgrammingAddress = 0x08008000;
				else
				{
					/* Do nothing. */
				}
				FBL_DiagRoutine_DSC_RequestDownload();
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x36) FBL_DiagRoutine_DSC_TransferData();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x37 && FBL_RxFrame.frame.data0 == 0x01) 	FBL_DiagRoutine_DSC_RequestTransferExit();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x04)
			{
				FBL_DSC_State = CODING;
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x50;
				FBL_TxFrame.frame.data2 = 0x04;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_DSC_Calibration();
				FBL_TxFrame.frame.dlc = 0;
				FBL_TxFrame.frame.id = 0;
				FBL_TxFrame.frame.idType = 0;
				FBL_TxFrame.frame.data0 = 0;
				FBL_TxFrame.frame.data1 = 0;
				FBL_TxFrame.frame.data2 = 0;
				FBL_TxFrame.frame.data3 = 0;
				FBL_TxFrame.frame.data4 = 0;
				FBL_TxFrame.frame.data5 = 0;
				FBL_TxFrame.frame.data6 = 0;
				FBL_TxFrame.frame.data7 = 0;
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x02)
			{
				FBL_DSC_State = PROGRAMMING;
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x50;
				FBL_TxFrame.frame.data2 = 0x02;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_DSC_Calibration();
				FBL_TxFrame.frame.dlc = 0;
				FBL_TxFrame.frame.id = 0;
				FBL_TxFrame.frame.idType = 0;
				FBL_TxFrame.frame.data0 = 0;
				FBL_TxFrame.frame.data1 = 0;
				FBL_TxFrame.frame.data2 = 0;
				FBL_TxFrame.frame.data3 = 0;
				FBL_TxFrame.frame.data4 = 0;
				FBL_TxFrame.frame.data5 = 0;
				FBL_TxFrame.frame.data6 = 0;
				FBL_TxFrame.frame.data7 = 0;
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x11 && FBL_RxFrame.frame.data2 == 0x01 && FBL_RxFrame.frame.data0 == 0x02)
			{
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x51;
				FBL_TxFrame.frame.data2 = 0x01;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_ER_HardReset();
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
		FBL_RxFrame.frame.dlc = 0;
		FBL_RxFrame.frame.id = 0;
		FBL_RxFrame.frame.idType = 0;
		FBL_RxFrame.frame.data0 = 0;
		FBL_RxFrame.frame.data1 = 0;
		FBL_RxFrame.frame.data2 = 0;
		FBL_RxFrame.frame.data3 = 0;
		FBL_RxFrame.frame.data4 = 0;
		FBL_RxFrame.frame.data5 = 0;
		FBL_RxFrame.frame.data6 = 0;
		FBL_RxFrame.frame.data7 = 0;
	}
}
void FBL_DiagRoutine_RDBI_ReadActiveDiagnosticSession(void)
{
	FBL_TxFrame.frame.dlc = 5;
	FBL_TxFrame.frame.id =0x701;
	FBL_TxFrame.frame.idType = 1;
	FBL_TxFrame.frame.data0 = 0x04;
	FBL_TxFrame.frame.data1 = 0x62;
	FBL_TxFrame.frame.data2 = 0xF1;
	FBL_TxFrame.frame.data3 = 0x86;
	FBL_TxFrame.frame.data4 = FBL_DSC_State;
	FBL_CanSpi_Transmit(&FBL_TxFrame);
	FBL_TxFrame.frame.idType = 0;
	FBL_TxFrame.frame.id = 0;
	FBL_TxFrame.frame.dlc = 0;
	FBL_TxFrame.frame.data0 = 0;
	FBL_TxFrame.frame.data1 = 0;
	FBL_TxFrame.frame.data2 = 0;
	FBL_TxFrame.frame.data3 = 0;
	FBL_TxFrame.frame.data4 = 0;
	FBL_TxFrame.frame.data5 = 0;
	FBL_TxFrame.frame.data6 = 0;
	FBL_TxFrame.frame.data7 = 0;
}
void FBL_DiagRoutine_DSC_Programming(void)
{
	if(FBL_CanSpi_Receive(&FBL_RxFrame) != 0)
	{
		if(FBL_RxFrame.frame.id == 0x700)
		{
			if(FBL_RxFrame.frame.data1 == 0x22 && FBL_RxFrame.frame.data2 == 0xF1 && FBL_RxFrame.frame.data3 == 0x86) FBL_DiagRoutine_RDBI_ReadActiveDiagnosticSession();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data0 == 0x04 && FBL_RxFrame.frame.data1 == 0x31 && FBL_RxFrame.frame.data4 == 0x00) FBL_DiagRoutine_RAR_MassEraseAPPL();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x34)
			{
				FBL_ProgrammingAddress = (0x08 << 24)
				| (FBL_RxFrame.frame.data4 << 16)
				| (FBL_RxFrame.frame.data5 << 8)
				| (FBL_RxFrame.frame.data6);
				FBL_DiagRoutine_DSC_RequestDownload();
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x36) FBL_DiagRoutine_DSC_TransferData();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x37 && FBL_RxFrame.frame.data0 == 0x01) FBL_DiagRoutine_DSC_RequestTransferExit();
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x04)
			{
				FBL_DSC_State = CODING;
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x50;
				FBL_TxFrame.frame.data2 = 0x04;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_DSC_Calibration();
				FBL_TxFrame.frame.dlc = 0;
				FBL_TxFrame.frame.id = 0;
				FBL_TxFrame.frame.idType = 0;
				FBL_TxFrame.frame.data0 = 0;
				FBL_TxFrame.frame.data1 = 0;
				FBL_TxFrame.frame.data2 = 0;
				FBL_TxFrame.frame.data3 = 0;
				FBL_TxFrame.frame.data4 = 0;
				FBL_TxFrame.frame.data5 = 0;
				FBL_TxFrame.frame.data6 = 0;
				FBL_TxFrame.frame.data7 = 0;
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x10 && FBL_RxFrame.frame.data2 == 0x05)
			{
				FBL_DSC_State = CALIBRATION;
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id =0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x50;
				FBL_TxFrame.frame.data2 = 0x05;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_DSC_Calibration();
				FBL_TxFrame.frame.dlc = 0;
				FBL_TxFrame.frame.id = 0;
				FBL_TxFrame.frame.idType = 0;
				FBL_TxFrame.frame.data0 = 0;
				FBL_TxFrame.frame.data1 = 0;
				FBL_TxFrame.frame.data2 = 0;
				FBL_TxFrame.frame.data3 = 0;
				FBL_TxFrame.frame.data4 = 0;
				FBL_TxFrame.frame.data5 = 0;
				FBL_TxFrame.frame.data6 = 0;
				FBL_TxFrame.frame.data7 = 0;
			}
			else
			{
				/* Do nothing. */
			}
			if(FBL_RxFrame.frame.data1 == 0x11 && FBL_RxFrame.frame.data2 == 0x01 && FBL_RxFrame.frame.data0 == 0x02)
			{
				FBL_TxFrame.frame.dlc = 3;
				FBL_TxFrame.frame.id = 0x701;
				FBL_TxFrame.frame.idType = 1;
				FBL_TxFrame.frame.data0 = 0x02;
				FBL_TxFrame.frame.data1 = 0x51;
				FBL_TxFrame.frame.data2 = 0x01;
				FBL_CanSpi_Transmit(&FBL_TxFrame);
				FBL_DiagRoutine_ER_HardReset();
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
		FBL_RxFrame.frame.dlc = 0;
		FBL_RxFrame.frame.id = 0;
		FBL_RxFrame.frame.idType = 0;
		FBL_RxFrame.frame.data0 = 0;
		FBL_RxFrame.frame.data1 = 0;
		FBL_RxFrame.frame.data2 = 0;
		FBL_RxFrame.frame.data3 = 0;
		FBL_RxFrame.frame.data4 = 0;
		FBL_RxFrame.frame.data5 = 0;
		FBL_RxFrame.frame.data6 = 0;
		FBL_RxFrame.frame.data7 = 0;
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM5 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */
  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM5)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	__NVIC_SystemReset();
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
