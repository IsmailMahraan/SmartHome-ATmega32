/*
 * Application.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Ismail
 */


#include "Application.h"

void InputID (u8* ID, u8 Mode)
{
  u8  PRESSEDBUTTONKeys = 0, KeyPRESSEDBUTTON = 0 , TTLData = 0;
  switch (Mode)
  {
    case ADMINMODE:
      HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
      HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
      HCLCD_WriteString("Enter User ID");
      HCLCD_SetCursorPosition(HCLCD_LINE_1, 0);
      while(PRESSEDBUTTONKeys < IDLENGTH)
      {
    	  TTLData=  HHC05_RecieveData();
        if (TTLData)
        {
          ID[PRESSEDBUTTONKeys] = TTLData;
          HCLCD_WriteChar4Bit(ID[PRESSEDBUTTONKeys]);
          PRESSEDBUTTONKeys++;
        }
      }
      _delay_ms(100);
      break;

    case USERMODE:
      HCLCD_SetCursorPosition(HCLCD_LINE_1, 0);
      while (PRESSEDBUTTONKeys < IDLENGTH)
      {
        KeyPRESSEDBUTTON = HKPD_GetPressedButton();
        if (KeyPRESSEDBUTTON)
        {
          ID[PRESSEDBUTTONKeys] = KeyPRESSEDBUTTON;

          HCLCD_WriteChar4Bit(ID[PRESSEDBUTTONKeys]);
          PRESSEDBUTTONKeys++;
        }
      }
      _delay_ms(200);
      break;

    default:      break;
  }
}
void InputPassword (u8* Password, u8 Mode)
{
  u8 TTLData = 0, DigitsEntered = 0, KeyPRESSEDBUTTON = 0;
  switch (Mode)
  {
    case ADMINMODE:
    	   HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
    	   HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
    	   HCLCD_WriteString("Enter Password");
    	   HCLCD_SetCursorPosition(HCLCD_LINE_1, 0);
      while (DigitsEntered < PASSWORDLENGTH)
      {
    	  TTLData= HHC05_RecieveData();
        if (TTLData)
        {
          Password[DigitsEntered] = TTLData;
          HCLCD_WriteChar4Bit('*');
          DigitsEntered++;
        }
      }
      _delay_ms(200);
      break;

    case USERMODE:
    	HCLCD_SetCursorPosition(HCLCD_LINE_1, 0);
      while (DigitsEntered < PASSWORDLENGTH)
      {
        KeyPRESSEDBUTTON = HKPD_GetPressedButton();
        if (KeyPRESSEDBUTTON)
        {
          Password[DigitsEntered] = KeyPRESSEDBUTTON;
          HCLCD_WriteChar4Bit('*');
          DigitsEntered++;
        }
      }
      _delay_ms(200);
  }

}
u8 AdminLogin (u8* ID, u8* Password)
{
   HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
   HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
  u8 ByteAddress = 0, ValidUsername = 0, ValidPassword = 0, LocalCounter = 0, EEPROMData = 0, WrongEntry = 0;
  for (; LocalCounter < IDLENGTH; LocalCounter++)
  {
    ByteAddress = 101 + LocalCounter;
    EEPROMData = HEEPROM_ReadByte(HCLCD_LINE_0,ByteAddress);
    if (ID[LocalCounter] == EEPROMData)
    {
      ValidUsername++;
    }
    else
    {
      /*Do Nothing*/
    }
  }

  for (LocalCounter = 0; LocalCounter < PASSWORDLENGTH; LocalCounter++)
  {
    ByteAddress = 101 + LocalCounter + IDLENGTH;
    EEPROMData = HEEPROM_ReadByte(HCLCD_LINE_0,ByteAddress);
    if (Password[LocalCounter]==EEPROMData)
    {
      ValidPassword++;
    }
    else
    {
     /*Do Nothing*/
    }

  }
  if ((ValidUsername == IDLENGTH) && (ValidPassword == PASSWORDLENGTH))
  {
    HCLCD_WriteString("Login Successful");
    HHC05_SendString("Login Successful");
    _delay_ms(500);
  }
  else if((ValidPassword == PASSWORDLENGTH) && (ValidUsername != IDLENGTH))
  {
	  HCLCD_WriteString("Invalid User Name!");
	  HHC05_SendString("Invalid User Name!");
      _delay_ms(500);
      WrongEntry++;
  }
  else if ((ValidUsername == IDLENGTH) && (ValidPassword != PASSWORDLENGTH))
  {
	  HCLCD_WriteString("Invalid Password!");
	  HHC05_SendString("Invalid Password!");
     _delay_ms(500);
     WrongEntry++;
  }
  else if ((ValidUsername != IDLENGTH) && (ValidPassword != PASSWORDLENGTH))
  {
	 HCLCD_WriteString("Wrong User Name!");
    HCLCD_SetCursorPosition(HCLCD_LINE_1, 0);
    HHC05_SendString("Wrong Password!");
    _delay_ms(500);
    HHC05_SendString("Wrong User Name & Password!");
    WrongEntry++;
  }
  else
  {
    /*Do Nothing*/
  }
  _delay_ms(300);
  HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
  HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
  _delay_ms(300);
  return WrongEntry;
}
u8 UserLogin (u8* ID, u8* Password)
{
  u8 NumberOfUsers = HEEPROM_ReadByte(0, 100);
  u8 UserLocation = 0, ValidUsername = 0, ValidPassword = 0, LocalCounter = 0, EEPROMData = 0, WrongEntry = 0, EEPROMDataLocation = 0;
  if (NumberOfUsers > 0)
  {
    for (; LocalCounter < NumberOfUsers; LocalCounter++)
    {
      ValidPassword = 0;
      ValidUsername = 0;
      UserLocation = LocalCounter * 7;
      u8 LocalCounter = 0;

      for (; LocalCounter < IDLENGTH; LocalCounter++)
      {
        EEPROMDataLocation = UserLocation + LocalCounter;
        EEPROMData = HEEPROM_ReadByte(0, (EEPROMDataLocation));
        if (ID[LocalCounter] == EEPROMData)
        {
          ValidUsername++;
        }

      }

      for (LocalCounter = 0; LocalCounter < PASSWORDLENGTH; LocalCounter++)
      {
        EEPROMDataLocation = UserLocation + LocalCounter + IDLENGTH;
        EEPROMData = HEEPROM_ReadByte(0,(EEPROMDataLocation));
        if (Password[LocalCounter] == EEPROMData)
        {
          ValidPassword++;
        }

      }

      if (ValidUsername == IDLENGTH && ValidPassword == PASSWORDLENGTH)
      {
        break;
      }
      else
      {
        ValidUsername = 0;
        ValidPassword = 0;
      }
    }
    if (ValidUsername == IDLENGTH && ValidPassword == PASSWORDLENGTH)
    {

      HCLCD_WriteString("Login Successful!");
      HHC05_SendString("Login Successful!");
    }
    else
    {
      HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
      HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
      HCLCD_WriteString("Invalid User Name");
      HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
      HCLCD_WriteString("Or Password");
      HHC05_SendString("Invalid User Name Or Password!");
      _delay_ms(1000);
      WrongEntry++;

    }
  }
  else
  {
	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
	HCLCD_WriteString("There is no users");
    HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
    HCLCD_WriteString("added yet");
    HHC05_SendString("There is no users added yet");
    _delay_ms(1000);
    WrongEntry = 2;
  }
  return WrongEntry;
}
void AddUser (u8* ID, u8* Password)
{

  u8 NumberOfUsers = HEEPROM_ReadByte(0, 100);
  if (NumberOfUsers < 10)
  {
    u8 LocalCounter = 0, UserLocation  = 0;

    if (NumberOfUsers > 0)
    {
      u8 WrongEntry = 0;

      for (; LocalCounter < NumberOfUsers; LocalCounter++)
      {

        UserLocation = (LocalCounter * 7);
        u8 LocalCounter = 0, EEPROMData = 0, EEPROMDataLocation = 0, ValidEntries = 3;
        for (; LocalCounter < IDLENGTH; LocalCounter++)
        {
          EEPROMDataLocation = UserLocation + LocalCounter;
          EEPROMData = HEEPROM_ReadByte(0,EEPROMDataLocation);
          if (ID[LocalCounter] == EEPROMData )
          {
            ValidEntries--;
          }

        }

        if (ValidEntries == 0)
        {
          WrongEntry ++;
          HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
          HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
          HCLCD_WriteString("Invalid UserName");
          HCLCD_WriteString("Invalid UserName");
          _delay_ms(500);
        }
      }

      if (WrongEntry == 0)
      {

        HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
        HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
        HCLCD_WriteString("Valid Entry");
        HHC05_SendString("Valid Entry");
        _delay_ms(500);
        u8 LocalCounter = 0, EEPROMDataLocation = 0;
        UserLocation = NumberOfUsers * 7;
        for (; LocalCounter < IDLENGTH; LocalCounter++)
        {
          EEPROMDataLocation = UserLocation + LocalCounter;
          HEEPROM_WriteByte(ID[LocalCounter], 0, EEPROMDataLocation);
        }

        for (LocalCounter = 0; LocalCounter < PASSWORDLENGTH; LocalCounter++)
        {
          EEPROMDataLocation = UserLocation + LocalCounter + IDLENGTH;
          HEEPROM_WriteByte(Password[LocalCounter], 0, EEPROMDataLocation);
        }
        NumberOfUsers++;
        HEEPROM_WriteByte(NumberOfUsers, 0, 100);

      }
    }
    else
    {
       HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
       HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
      HCLCD_WriteString("Valid Entry");
      _delay_ms(500);
      HHC05_SendString("Valid Entry");
      u8 LocalCounter = 0, EEPROMDataLocation = 0;
      UserLocation = NumberOfUsers * 7;
      for (; LocalCounter <IDLENGTH; LocalCounter++)
      {
        EEPROMDataLocation = UserLocation + LocalCounter;
        HEEPROM_WriteByte(ID[LocalCounter], 0, EEPROMDataLocation);
      }

      for (LocalCounter = 0; LocalCounter < PASSWORDLENGTH; LocalCounter++)
      {
        EEPROMDataLocation = UserLocation + LocalCounter + IDLENGTH;
        HEEPROM_WriteByte(Password[LocalCounter], 0, EEPROMDataLocation);
      }
      NumberOfUsers++;
      HEEPROM_WriteByte(NumberOfUsers, 0, 100);
      HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
      HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
      HCLCD_WriteString("User Added");
      HHC05_SendString("User Added");
      HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
      HCLCD_WriteString("No of Users ");
      HHC05_SendString("No of Users ");
      HCLCD_WriteNumber(HEEPROM_ReadByte(0, 100));
      HHC05_SendChar(HEEPROM_ReadByte(0, 100));
      _delay_ms(500);
    }
  }
  else
  {
    HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
    HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
    HCLCD_WriteString("Max Users");
    HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
    HCLCD_WriteString("Number Reached!");
    HHC05_SendString("Max users Number Reached!");
    _delay_ms(500);
  }
}
void DeleteUser (u8 NumberOfUsers, u8* ID)
{
  _delay_ms(100);
  HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
  HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
  if (NumberOfUsers > 0)
  {
    u8 LocalCounter = 0, UserLocation  = 0, Accurate = 0;

    for (; LocalCounter < NumberOfUsers; LocalCounter++)
    {
      UserLocation = (LocalCounter * 7);
      u8 LocalCounter = 0, EEPROMData = 0, EEPROMDataLocation = 0, ValidEntries = 0;

      for (; LocalCounter < 3; LocalCounter++)
      {
        EEPROMDataLocation = UserLocation + LocalCounter;
        EEPROMData = HEEPROM_ReadByte(0,EEPROMDataLocation);
        if (ID[LocalCounter] == EEPROMData )
        {
          ValidEntries++;
        }

      }

      if (ValidEntries == 3)
      {
        HCLCD_WriteString("Valid UserName");
        HHC05_SendString("Valid UserName");
        _delay_ms(200);
        Accurate ++;

      }
      if (Accurate == 1)
      {
        u8 LocalCounter = 0, EEPROMDataLocation = 0;
        for (; LocalCounter < IDLENGTH; LocalCounter++)
        {
          EEPROMDataLocation = UserLocation + LocalCounter;
          EEPROMData = HEEPROM_ReadByte(0, (EEPROMDataLocation + 7));
          HEEPROM_WriteByte(EEPROMData, 0, EEPROMDataLocation);
        }
        LocalCounter = 0;
        for (; LocalCounter < PASSWORDLENGTH; LocalCounter++)
        {
          EEPROMDataLocation = UserLocation + LocalCounter + IDLENGTH;
          EEPROMData = HEEPROM_ReadByte(0, (EEPROMDataLocation + 7));
          HEEPROM_WriteByte(EEPROMData, 0, EEPROMDataLocation);

        }
      }
    }
    if (Accurate == 1)
    {
      NumberOfUsers--;
      HEEPROM_WriteByte(NumberOfUsers, 0, 100);
    }

  }

  else
  {
    /*Do Nothing*/

  }

}
void CheckEEPROM(void){
	  for (u16 LocalCounter = 0; LocalCounter <= 16; LocalCounter++)
	  {
	    HCLCD_WriteChar4Bit(HEEPROM_ReadByte(0,LocalCounter));
	  }
	  HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
	  for (u32 LocalCounter = 17; LocalCounter < 33; LocalCounter++)
	  {
		  HCLCD_WriteChar4Bit(HEEPROM_ReadByte(0, LocalCounter));
	  }

}
void DeleteAll (void)
{
  for (u16 LocalCounter = 0; LocalCounter <= 0xFF; LocalCounter++)
  {
    HEEPROM_WriteByte(0xFF,0, LocalCounter);
  }
  HEEPROM_WriteByte(0, 0, 100);
}
void ACSwitch (u8* ACState)
{
	if (*ACState == 0)
	{
	 u16 Temperature = 0;
	 while(1){
	 HLM35Read(&Temperature);

	 if (Temperature > MAXTEMPERATURE)
	 {
		 HDCMotorSetDirection(CW);
		 HDCMotorSpeed(100);
		 HDCMotorStart();
	 }
	 else if (Temperature < MINTEMPERATURE)
	 {
		 HDCMotorStop();
	 }

	 *ACState = 1;
	 }

 }
 else
 {
	 HDCMotorStop();
	 HLED_OFF(LED1);
	 HLED_OFF(LED0);
	 *ACState = 0;
 }

}
void DoorSwitch (u8* DoorOpened)
{
  if (*DoorOpened == 0)
  {
	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
    HCLCD_WriteString("Door is Opened!");
    HHC05_SendString("Door is Opened!");
    HServoSetAngel(120);
    _delay_ms(500);
    *DoorOpened = 1;
  }
  else
  {
	  HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	  HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
	  HCLCD_WriteString("Door is Closed!");
      HHC05_SendString("Door is Opened!");
      HServoSetAngel(0);
    _delay_ms(500);
    *DoorOpened = 0;
  }

}
void RelaySwitch(u8* RelayOpened)
{
  if (*RelayOpened == 0)
  {
	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
	HCLCD_WriteString("Lamps are ON!");
	HHC05_SendString("Lamps are ON!");
    HRELAYON();
    *RelayOpened = 1;
  }
  else if (*RelayOpened == 1)
  {
	 HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	 HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
	 HCLCD_WriteString("Lamps are OFF!");
	 HHC05_SendString("Lamps are OFF!");
     HRELAYOFF();
    *RelayOpened = 0;
  }
}
void CloseTheDoor(void)
{
  HServoSetAngel(0);
  HRELAYOFF();
}
void Door(u8 DoorState){
  if (DoorState == 1)
  {
	HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
	HCLCD_WriteString("Door is Opened!");
	HHC05_SendString("Door is Opened!");
    HServoSetAngel(120);
    _delay_ms(500);
  }
  else
  {
	HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
	 HCLCD_WriteString("Door is Closed!");
	 HHC05_SendString("Door is Opened!");
	 HServoSetAngel(0);
    _delay_ms(500);
  }

}
void AC(u8 ACState)
{
  if (ACState == 1)
  {
	  u16 Temperature = 0;
	   HLM35Read(&Temperature);
	  if (Temperature >= MAXTEMPERATURE)
	  {
		  HDCMotorSetDirection(CW);
		  HDCMotorSpeed(100);
		  HDCMotorStart();
	  }
	  else if (Temperature < MINTEMPERATURE)
	  {
		  HLED_ON(LED1);
		  HLED_OFF(LED0);
		  HDCMotorStop();
	  }
	  HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	 	 HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
	 	HCLCD_WriteString("AC is ON!");
	 	HHC05_SendString("AC is ON!");
  }
  else
  {
	  HDCMotorStop();
	  HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
	  HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
	  HCLCD_WriteString("AC is OFF!");
	  HHC05_SendString("AC is OFF!");
  }
}
void Relay(u8 RelayState)
{
  if (RelayState == 1)
  {
	  HCLCD_WriteString("Relay ON!");
	  HHC05_SendString("Relay ON!");
    HRELAYON();
  }
  else if (RelayState == 0)
  {
	  HCLCD_WriteString("Relay OFF!");
	  HHC05_SendString("Relay OFF!");
   HRELAYOFF();
  }
}
void AppInit(void)
{
  HEEPROM_WriteByte('1', 0, 101);
  HEEPROM_WriteByte('1', 0, 102);
  HEEPROM_WriteByte('5', 0, 103);
  HEEPROM_WriteByte('5', 0, 104);
  HEEPROM_WriteByte('9', 0, 105);
  HEEPROM_WriteByte('1', 0, 106);
  HEEPROM_WriteByte('1', 0, 107);
}

void Welcoming(void)
{
	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
    HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
    HCLCD_WriteString("Welcome User!");
    HHC05_SendString("Welcome User!");
   _delay_ms(1000);
 HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
  HCLCD_SetCursorPosition(HCLCD_LINE_0,0);

}
void Reset(u8* ACState, u8* DoorState, u8* RelayState)
{
  *ACState = 0;
  *DoorState = 0;
  *RelayState = 0;
  HDCMotorStop();
  CloseTheDoor();
  HRELAYOFF();
  HHC05_SendString("AC Off");
  HHC05_SendString("Door is closed");
  HHC05_SendString("Relay Off");
  HHC05_SendString("Resetting  the system...");
  DeleteAll();
  AppInit();
}


























