#include "Application/Application.h"
/************************************************************************/
/*  Admin Password is 1234
  Admin UserName is 123
  Admin  EEPROM Location is @ 101 byte address page 1             */





int main(){

	 HCLCDInit4BitMode();
		  HKPD_Init();

		  //MTWI_MasterInit();
		  HDimmerLightInit();
		  I2C_Init();
		  HHC05_Init();
		  HLM35Init();
	      HDCMotorInit();
	      HServoInit();
		  HLED_Init(LED0);
		  HLED_Init(LED1);
		  HBUZZERInit();
		  HPushButton_Init();
		  HRELAYInit();
		  DeleteAll();
		  AppInit();


		  char NumberOfUsers = 0;
		  NumberOfUsers = HEEPROM_ReadByte(0, 100);
		  u8 UserID   [IDLENGTH] = {1, 1, 1};
		  u8 UserPassword [PASSWORDLENGTH] = {1,1,5,5};
		  u8 KeyPRESSEDBUTTON = 0;
		  u8 Trails = 0;
		  u8 DoorState = 0;
		  u8 ACState = 0;
		  u8 RelayState = 0;
		  u8 TTLData = 0;
		  u8 AppState = WELCOME;
		  while (1)
		  {
		    switch (AppState)
		    {
		      case WELCOME :
		        Welcoming();
		        _delay_ms(2000);
		        AppState = FIRSTPAGE;
		        break;
		      case FIRSTPAGE:
		    	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		    	HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		        HCLCD_WriteString("    Welcome     ");
		        HHC05_SendString("Choose User using Keypad");
		        HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
		        HCLCD_WriteString("1:Admin 2:User");
		        HHC05_SendString("1:Admin 2:User");
		        KeyPRESSEDBUTTON = HKPD_GetPressedButton();
		        while (!KeyPRESSEDBUTTON)
		        {
		          KeyPRESSEDBUTTON = HKPD_GetPressedButton();
		          if (KeyPRESSEDBUTTON == '1')
		          {
		            AppState = ADMINLOGINPAGE;
		          }
		          else if (KeyPRESSEDBUTTON == '2')
		          {
		            AppState = USERLOGINPAGE;
		          }
		          else
		          {
		            /*DO NOTHING*/
		          }

		        }
		        break;

		      case ADMINLOGINPAGE:
		        Trails = 0;
		        HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		        HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		        HHC05_SendString("Welcome");
		        HCLCD_WriteString("Welcome");
		        _delay_ms(2000);
		        HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		       	HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		       	HCLCD_WriteString("****Admin Mode****");
		    	HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
		    	HCLCD_WriteString("Use Bluetooth");
		    	HHC05_SendString("Use Bluetooth");
		        _delay_ms(3000);

		        while (Trails < MAXTRIALS)
		        {
		          HHC05_SendString("Enter UserName");
		          InputID(&UserID, ADMINMODE);
		          HHC05_SendString("Enter Password");
		          InputPassword(UserPassword, ADMINMODE);

		          if (AdminLogin(UserID, UserPassword) == 0)
		          {
		            AppState = ADMINSECONDPAGE;
		            break;
		          }
		          else
		          {
		            Trails++;
		            if (Trails == MAXTRIALS)
		            {
		              HBUZZERON();
		              CloseTheDoor();
		              KeyPRESSEDBUTTON = HKPD_GetPressedButton();
		              while (1)
		              {
		                if (HKPD_GetPressedButton() == PRESSEDBUTTON)
		                {
		                  _delay_ms(100);
		                  if (HKPD_GetPressedButton() == PRESSEDBUTTON)
		                  {
		                    while (HKPD_GetPressedButton() == PRESSEDBUTTON);
		                    HBUZZEROFF();
		                    AppState = WELCOME;
		                    break;
		                  }
		                }
		              }
		            }
		          }
		        }
		        Trails = 0;
		        break;

		      case USERLOGINPAGE:
		        Trails = 0;
		        HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		        HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		        HCLCD_WriteString("Welcome User");
		        _delay_ms(2000);
		        while (Trails < MAXTRIALS)
		        {
		        HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		        HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		          HCLCD_WriteString("Enter Username");
		          InputID(UserID, USERMODE);
		          HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		          HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		          HCLCD_WriteString("Enter Password");
		          InputPassword(UserPassword, USERMODE);
		          u8 LoginResult = UserLogin(UserID, UserPassword);

		          if (LoginResult == 0)
		          {
		            AppState = USERSECONDPAGE;
		            break;
		          }
		          else if (LoginResult == 2)
		          {
		            AppState = FIRSTPAGE;
		            break;
		          }
		          else if (LoginResult == 1)
		          {
		            Trails++;
		            if (Trails == MAXTRIALS)
		            {
		              HBUZZERON();
		              CloseTheDoor();
		              HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		             HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		              KeyPRESSEDBUTTON = HKPD_GetPressedButton();
		              while (1)
		              {
		                if (HKPD_GetPressedButton() == PRESSEDBUTTON)
		                {
		                  _delay_ms(100);
		                  if (HKPD_GetPressedButton() == PRESSEDBUTTON)
		                  {
		                    while (HKPD_GetPressedButton() == PRESSEDBUTTON);
		                    HBUZZEROFF();
		                    AppState = WELCOME;
		                    break;
		                  }
		                }
		              }
		            }
		          }
		        }
		        Trails = 0;
		        break;

		      case ADMINSECONDPAGE:
		        TTLData = 0;
		        TTLData=  HHC05_RecieveData();
		        switch (TTLData)
		        {
		          //   A/C Switch
		          case 'A':    ACSwitch(&ACState);
		          break;
		          //  Add user
		          case 'B':
		        	 HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		        	 HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		        	HCLCD_WriteString("Use the KeyPad");
		            HHC05_SendString("Use the KeyPad");
		            _delay_ms(3000);
		            InputID(UserID, USERMODE);
		            InputPassword(UserPassword, USERMODE);
		            AddUser(UserID, UserPassword);
		            break;
		          // Remove user
		          case 'C':
		            NumberOfUsers = HEEPROM_ReadByte(0, 100);
		            HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		           	HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		           	HCLCD_WriteString("Use Bluetooth");
		            HHC05_SendString("Use Bluetooth");
		            _delay_ms(3000);
		            InputID(UserID, ADMINMODE);
		            DeleteUser(NumberOfUsers, UserID);
		            break;
		            //  User Mode
		       	   case 'U':     AppState = USERLOGINPAGE;
		       	   break;
		       	       // Reset Mode
		       	  case 'S': Reset(&ACState, &DoorState, &RelayState);
		       	  AppState = WELCOME;
		       	   break;
		          //   Door Switch
		          case 'D':   DoorSwitch(&DoorState);
		          break;
		          //   Relay Switch
		          case 'R':   RelaySwitch(&RelayState);
		          break;
		          //Dimmer
		          case 'L':
		        	 HDimmerLightStart(); break;
		        		HCLCD_WriteString("Use keys to set dimmer");
		        		HHC05_SendString("Use keys to set dimmer");
		        		 HDimmerLightSetLightIntense(HKPD_GetPressedButton()*10);
		        		 HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		        		  HCLCD_SetCursorPosition(HCLCD_LINE_0,0);




		        		          break;
		          //I -> Idle State (OK)
		          case 'I':   AppState = IDLE_STATE;
		          break;
		          default:   break;
		        }
		        break;
		      case IDLE_STATE:
		    	  TTLData = HHC05_RecieveData();
		        while (!TTLData)
		        {
		        TTLData=HHC05_RecieveData();
		          AC(ACState);
		          Relay(RelayState);
		          Door(DoorState);
		        }
		        AppState = WELCOME;

		        break;

		      case USERSECONDPAGE :
		    	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
		        HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		        HCLCD_WriteString("1:Relay ON?");
		        HCLCD_SetCursorPosition(HCLCD_LINE_1,0);
		        HCLCD_WriteString("2:AcSwitch  3:OK");
		        KeyPRESSEDBUTTON = HKPD_GetPressedButton();
		        while (!KeyPRESSEDBUTTON)
		        {
		          KeyPRESSEDBUTTON = HKPD_GetPressedButton();
		          if (KeyPRESSEDBUTTON == '1')
		          {
		            RelaySwitch(&RelayState);
		          }
		          else if (KeyPRESSEDBUTTON == '2')
		          {
		            ACSwitch(&ACState);
		          }
		          else if (KeyPRESSEDBUTTON == '3')
		          {
		            AppState = IDLE_STATE;
		          }
		        }
		        break;
		    }

		  }


	return 1;
}
