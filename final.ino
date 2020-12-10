
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 9
// RX buffer size
#define _SS_MAX_RX_BUFF 256

//#include <dht.h>
//dht DHT;
SoftwareSerial gsm(2,4); //RX, TX
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//#define DHT22_PIN 8
int chk;
int humi= 0;
float temp= 0;
float temp1= 0;
String API_Key= "YZB6UQN2318W2YC3" ;
String APN= "internet.ng.airtel.com";//"www.ab.kyivstar.net";
String URL="api.thingspeak.com";
//char incomingByte[] = "FIRST LOOP";



void ShowSerialData()
{
while(gsm.available()!=0)
  Serial.write(gsm.read());
}

void setup() {
  Serial.begin(115200);
  gsm.begin(9600);
  sensors.begin();

 gsm.println("AT+CMGF=1"); // Configuring TEXT mode
   ShowSerialData();
  delay(1000);
  gsm.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
 delay(1000);
 ShowSerialData();
//======================================================
gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(1000);
  ShowSerialData();
  gsm.println("AT+CMGS=\"+2348126159242\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
   delay(1000);
   ShowSerialData();
  gsm.print("Unity Board Presentation to NTU(KhPI)"); //text content
   delay(1000);
   ShowSerialData();
  gsm.write(26);
delay(2000);


//=======================================================================
  
 // falan();
 //singlecon();
//Serial.println(incomingByte);
 
}

void loop() 

{
 //delay(2000);
  /*mySerial.println(Data);
  chk = DHT.read22(DHT22_PIN);
  switch (chk)
  {
    case DHTLIB_OK:
      Serial.print("OK,\t");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print("Time out error,\t");
      break;
    case DHTLIB_ERROR_CONNECT:
      Serial.print("Connect error,\t");
      break;
    case DHTLIB_ERROR_ACK_L:
      Serial.print("Ack Low error,\t");
      break;
    case DHTLIB_ERROR_ACK_H:
      Serial.print("Ack High error,\t");
      break;
      default:
      Serial.print("Unknown error,\t");
      break;
  }
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity, 1);
  Serial.print("%");
  Serial.print(",\t");
  Serial.print("Temperature: ");
  Serial.print(DHT.temperature, 1);
  Serial.println("*C");
*/
  
  humi =humi + 100;// analogRead(A2);//DHT.temperature;
 //humi = analogRead(A4);
  delay(500);
sensors.requestTemperatures();
delay(1000);
temp=sensors.getTempCByIndex(0);
delay(1000);
Serial.println(temp); 
 delay(1000); 

sensors.requestTemperatures();
delay(1000);
temp1=sensors.getTempCByIndex(1);
delay(1000);
Serial.println(temp1); 
 delay(2000);
 
  ShowSerialData();
  falan();
  singlecon();
  ShowSerialData();

//Serial.write(incomingByte);
  
}




void falan()
{
  Serial.println();
  Serial.println("starting.....");
  Serial.println();
  gsm.println("AT");
  delay(1000);

gsm.println("AT");
  delay(1000);

  
  ShowSerialData();
  gsm.println(F("AT+CPIN?"));
  delay(2000);
  ShowSerialData();
  gsm.println("AT+CREG?");
  delay(2000);
  ShowSerialData();
  gsm.println("AT+CIPSHUT");
  delay(3000);
  ShowSerialData();
  gsm.println("AT+CIPSTATUS");
 
  delay(2000);
  ShowSerialData();
}









void singlecon()
{Serial.println();
Serial.println();
  Serial.println("GPRS connecting.....");
  Serial.println();
  gsm.println("AT+CIPMUX=0");
  delay(2000);
  ShowSerialData();
  gsm.print("AT+CSTT=");
  gsm.print('"');
  gsm.print(APN);  //APN="internet.ng.airtel.com"
  gsm.println('"');
 
  delay(2000);
  ShowSerialData();
  delay(1000);
  gsm.println("AT+CIICR");
  delay(2000);
 
  ShowSerialData();
  delay(1000);
  gsm.println("AT+CIFSR");
  delay(2000);
 
  ShowSerialData();
  gsm.print("AT+CIPSTART=");
  gsm.print('"');
  gsm.print("TCP");
  gsm.print('"');
  gsm.print(',');
  gsm.print('"');
  gsm.print(URL); //URL= "api.thingspeak.com"
  gsm.print('"');
  gsm.print(',');
  gsm.print("80");
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(5000);
  
  ShowSerialData();
  delay(1000);
  gsm.println("AT+CIPSEND");
delay(1000);

  
  //uint8_t incomingByte = gsm.read();///////////////////////////////////////////////////
  delay(8000);
//////////////////////////////////////////////////////////////////////////////////////


  
  ShowSerialData();
 
  delay(1000);
  gsm.print("GET");
  gsm.print(' ');
  //gsm.print("http:");
  //gsm.print('/');
  //gsm.print('/');
  //gsm.print("api.thingspeak.com");
  gsm.print('/');
  gsm.print("update?api_key=");
  gsm.print(API_Key);// API_Key= "YZB6UQN2318W2YC3" ;
  gsm.print("&field1=");
  gsm.print(temp,DEC);
  gsm.print("&field2=");
  gsm.print(temp1,DEC);

//gsm.print("&field3=");
  //gsm.print((humi+500),DEC);

//gsm.print("&field4=");
  //gsm.print((temp),DEC);

 
  gsm.write(0x0d);
  gsm.write(0x0a);


//////////////////////////////////////////////////////////////////////////////////////////////////
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  gsm.write(0x1a); // the trick is here to send the request. Its Ctrl+Z to start send process.









  
  delay(8000);
 
  ShowSerialData();
///====================================================================================================





////========================================================================================================

  
 delay(1000);
  gsm.println("AT+CIPSHUT");
  //gsm.println("AT+CIPCLOSE");
  gsm.write(0x0d);
  gsm.write(0x0a);
  delay(15000);
  ShowSerialData();
}
//HP: https://thingspeak.com/channels/960293
