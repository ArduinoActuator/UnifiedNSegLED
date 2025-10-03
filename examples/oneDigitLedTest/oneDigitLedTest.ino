
/*
 * 利用するLEDの種類の定義
 */
#define USE_OSL12306_16

/*
 * 接続するピンの定義
 */
#ifdef USE_OSL12306_16
/*
#define OSL12306_16_PIN_2 22
#define OSL12306_16_PIN_3 23
#define OSL12306_16_PIN_4 24
#define OSL12306_16_PIN_5 25
#define OSL12306_16_PIN_6 26
#define OSL12306_16_PIN_7 27
#define OSL12306_16_PIN_8 28
#define OSL12306_16_PIN_9 29
#define OSL12306_16_PIN_10 30
#define OSL12306_16_PIN_11 31
#define OSL12306_16_PIN_12 32
#define OSL12306_16_PIN_13 33
#define OSL12306_16_PIN_14 34
#define OSL12306_16_PIN_15 35
#define OSL12306_16_PIN_16 36
#define OSL12306_16_PIN_17 37
#define OSL12306_16_PIN_18 38
#define OSL12306_16_PIN_19 39
*/
//#define OSL12306_16_PIN_1 41
/*
#define OSL12306_16_PIN_1 38
#define OSL12306_16_PIN_2 39
#define OSL12306_16_PIN_3 37
#define OSL12306_16_PIN_4 35
#define OSL12306_16_PIN_5 33
#define OSL12306_16_PIN_6 31
#define OSL12306_16_PIN_7 29
#define OSL12306_16_PIN_8 27
#define OSL12306_16_PIN_9 25
#define OSL12306_16_PIN_10 23

#define OSL12306_16_PIN_12 22
#define OSL12306_16_PIN_13 24
#define OSL12306_16_PIN_14 26
#define OSL12306_16_PIN_15 28
#define OSL12306_16_PIN_16 30
#define OSL12306_16_PIN_17 32
#define OSL12306_16_PIN_18 34
#define OSL12306_16_PIN_19 36
*/
#define OSL12306_16_PIN_1 41
#define OSL12306_16_PIN_2 39
#define OSL12306_16_PIN_3 37
#define OSL12306_16_PIN_4 35
#define OSL12306_16_PIN_5 33
#define OSL12306_16_PIN_6 31
#define OSL12306_16_PIN_7 29
#define OSL12306_16_PIN_8 27
#define OSL12306_16_PIN_9 25
#define OSL12306_16_PIN_10 23

#define OSL12306_16_PIN_12 22
#define OSL12306_16_PIN_13 24
#define OSL12306_16_PIN_14 26
#define OSL12306_16_PIN_15 28
#define OSL12306_16_PIN_16 30
#define OSL12306_16_PIN_17 32
#define OSL12306_16_PIN_18 34
#define OSL12306_16_PIN_19 36
#define OSL12306_16_PIN_20 38

#endif /* USE_OSL12306_16 */

#include "UnifiedNSegLED.h"
#include "detectArduinoHardware.h"

#ifdef USE_OSL12306_16
#define OSL12306_16_PIN_A1 OSL12306_16_PIN_17
#define OSL12306_16_PIN_A2 OSL12306_16_PIN_14
#define OSL12306_16_PIN_B OSL12306_16_PIN_13
#define OSL12306_16_PIN_C OSL12306_16_PIN_9
#define OSL12306_16_PIN_D1 OSL12306_16_PIN_4
#define OSL12306_16_PIN_D2 OSL12306_16_PIN_7
#define OSL12306_16_PIN_E OSL12306_16_PIN_3
#define OSL12306_16_PIN_F OSL12306_16_PIN_19
#define OSL12306_16_PIN_G1 OSL12306_16_PIN_2
#define OSL12306_16_PIN_G2 OSL12306_16_PIN_12
#define OSL12306_16_PIN_J OSL12306_16_PIN_18
#define OSL12306_16_PIN_K OSL12306_16_PIN_16
#define OSL12306_16_PIN_L OSL12306_16_PIN_15
#define OSL12306_16_PIN_M OSL12306_16_PIN_8
#define OSL12306_16_PIN_N OSL12306_16_PIN_6
#define OSL12306_16_PIN_P OSL12306_16_PIN_5
#define OSL12306_16_PIN_DP OSL12306_16_PIN_10
#define OSL12306_16_PIN_DIGIT OSL12306_16_PIN_1


#define OSL12306_16_NUM_OF_PINS _OSL12306_16_CHAR_PINS
#define OSL12306_16_NUM_OF_DIGITS 1

uint8_t pins[OSL12306_16_NUM_OF_PINS] = {
  OSL12306_16_PIN_A1 , OSL12306_16_PIN_A2 , OSL12306_16_PIN_B , OSL12306_16_PIN_C , OSL12306_16_PIN_D1 , OSL12306_16_PIN_D2 , OSL12306_16_PIN_E , OSL12306_16_PIN_F , 
  OSL12306_16_PIN_G1 , OSL12306_16_PIN_G2 , OSL12306_16_PIN_J , OSL12306_16_PIN_K , OSL12306_16_PIN_L , OSL12306_16_PIN_M , OSL12306_16_PIN_N , OSL12306_16_PIN_P
};

uint8_t digitPins[OSL12306_16_NUM_OF_DIGITS] = {OSL12306_16_PIN_DIGIT};

OSL12306_16 __osl12306_16(
  ANODE_COMMON,
  pins,
  OSL12306_16_PIN_DP,
  OSL12306_16_NUM_OF_DIGITS,
  digitPins
);

UnifiedNSegLED osl12306_16(&__osl12306_16, OSL12306_16_TYPE);
#endif /* USE_OSL12306_16 */


//unsigned int test=1;

#define DIGITS OSL12306_16_NUM_OF_DIGITS
#define MAX_BUFF_SIZE 256
#define MAX_TEST 3
struct testResultEntity {
  bool result;
  //String about;
  char about[MAX_BUFF_SIZE];
  //String comment;
  char comment[MAX_BUFF_SIZE];
} testResult[MAX_TEST];

void printStartMessage(String about, uint8_t testNumber){
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE ; i++ ){
    message[i]=0;
  }
  sprintf(message,"Wait for start test No.%d (%s)",testNumber+1, about.c_str());
  Serial.println(message);
}

void waitForStart(void){
  Serial.print("Please press Enter key to start test : ");
  int count =0;
  while (true) {
    if (Serial.available() > 0) {
      char input = Serial.read();
      if (input == '\n') {
        break;
      } else {
        Serial.print(input);
      }
    }
  }
  Serial.println("");
}

void checkTestResult(String about, uint8_t testNumber){
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE ; i++ ){
    message[i]=0;
    testResult[testNumber].about[i]=0;
    testResult[testNumber].comment[i]=0;
  }
  sprintf(message,"Please input the failure of test No.%d (%s), if the test is succeeded, press Enter : ",testNumber+1, about.c_str());
  sprintf(testResult[testNumber].about,"%s", about.c_str());
  testResult[testNumber].result = true;
  Serial.print(message);
  int count =0;
  while (true) {
    if (Serial.available() > 0) {
      char input = Serial.read();
      if ((input != -1) && (input != '\n')) {
        testResult[testNumber].comment[count]=input;
        testResult[testNumber].result = false;
        count++;
        Serial.print(input);
      }
      if ((count == MAX_BUFF_SIZE-2) || (input == '\n')) break;
    }
  }
  Serial.println("");
}

void sumTestResult(void){
  int count = 0;
  Serial.println("======== summary of tests ========");
  for (int i=0 ; i<MAX_TEST ; i++ ) {
    char message[MAX_BUFF_SIZE];
    for (int i=0; i<MAX_BUFF_SIZE; i++) {
      message[i]=0;
    }
    if (testResult[i].result) {
      sprintf(message,"Test result of test No.%d (%s) : Success.",i+1, testResult[i].about);
    } else {
      count++;
      sprintf(message,"Test result of test No.%d (%s) : %s",i+1, testResult[i].about, testResult[i].comment);
    }
    Serial.println(message);
  }
  Serial.println("");
  char finalMessage[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE; i++) {
    finalMessage[i]=0;
  }
  sprintf(finalMessage, "Test result : all(%d) , success(%d) , fail(%d)", MAX_TEST, MAX_TEST-count, count);
  Serial.println(finalMessage);
  Serial.println("");
}


enum functionList {
  FUNCTION_SET = 0,
  FUNCTION_SET_COLOMN,
  FUNCTION_BEGIN,
  FUNCTION_CLEAR,
  FUNCTION_DISPLAY
};

String functionName[5] = {
  "set()",
  "setColomn()",
  "begin()",
  "clear()",
  "display()"
};

void checkReturnValue(nSegLedFunctionReturnValue val, uint8_t funcType) {
  char buff[MAX_BUFF_SIZE];
  memset(buff,0,MAX_BUFF_SIZE);
  if (val == NSEGLED_FUNCTION_UNSUPPORTED) {
    Serial.println("");
    sprintf(buff,"executed function \"%s\" is unsupported.",functionName[funcType].c_str());
    Serial.println(buff);
    return;
  }
  if (val == NSEGLED_FUNCTION_FAIL) {
    Serial.println("");
    sprintf(buff,"executed function \"%s\" is failed.",functionName[funcType].c_str());
    Serial.println(buff);
    return;
  }
}


//
char dispData[DIGITS];

void clearDispData() {
  for (int i=0; i< DIGITS; i++) {
    dispData[i]=0;
  }
}



//  テストシナリオ1 : ピリオドの点灯/消灯
void test1() {
  String about = "test1";
  printStartMessage(about, 0);
  clearDispData();
  Serial.println("=== action ===");
  Serial.println("ON/OFF period 10 times");
  Serial.println("");
  waitForStart();

  Serial.println("test1 start.");

  nSegLedFunctionReturnValue value;

  uint64_t flag=1;
  for (int i=0; i<10; i++) {
    if (flag==1) {
      flag = 0;
    } else {
      flag = 1;
    }
#ifdef USE_OSL12306_16
    value = osl12306_16.display(flag, dispData);
    checkReturnValue(value, FUNCTION_DISPLAY);
#endif /* USE_OSL12306_16 */
    delay(1000);
  }

  checkTestResult(about, 0);
  Serial.println("");
  Serial.println("");
#ifdef USE_OSL12306_16
  value = osl12306_16.clear();
  checkReturnValue(value, FUNCTION_CLEAR);
#endif /* USE_OSL12306_16 */

}


void test2() {
  String about = "test2";
  printStartMessage(about, 1);
  clearDispData();
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("x (x:-,0,1...,a,b,c...z)");
  Serial.println("");
  waitForStart();

  Serial.println("test2 start.");


  nSegLedFunctionReturnValue value;

  for (int i=0; i< 39 ;i++) {
    switch(i) {
      case 1: {dispData[0]=0;break;}
      case 2: {dispData[0]='-';break;}
      case 3: {dispData[0]='0';break;}
      case 4: {dispData[0]='1';break;}
      case 5: {dispData[0]='2';break;}
      case 6: {dispData[0]='3';break;}
      case 7: {dispData[0]='4';break;}
      case 8: {dispData[0]='5';break;}
      case 9: {dispData[0]='6';break;}
      case 10: {dispData[0]='7';break;}
      case 11: {dispData[0]='8';break;}
      case 12: {dispData[0]='9';break;}
      case 13: {dispData[0]='a';break;}
      case 14: {dispData[0]='b';break;}
      case 15: {dispData[0]='c';break;}
      case 16: {dispData[0]='d';break;}
      case 17: {dispData[0]='e';break;}
      case 18: {dispData[0]='f';break;}
      case 19: {dispData[0]='g';break;}
      case 20: {dispData[0]='h';break;}
      case 21: {dispData[0]='i';break;}
      case 22: {dispData[0]='j';break;}
      case 23: {dispData[0]='k';break;}
      case 24: {dispData[0]='l';break;}
      case 25: {dispData[0]='m';break;}
      case 26: {dispData[0]='n';break;}
      case 27: {dispData[0]='o';break;}
      case 28: {dispData[0]='p';break;}
      case 29: {dispData[0]='q';break;}
      case 30: {dispData[0]='r';break;}
      case 31: {dispData[0]='s';break;}
      case 32: {dispData[0]='t';break;}
      case 33: {dispData[0]='u';break;}
      case 34: {dispData[0]='v';break;}
      case 35: {dispData[0]='w';break;}
      case 36: {dispData[0]='x';break;}
      case 37: {dispData[0]='y';break;}
      case 38: {dispData[0]='z';break;}
    }
#ifdef USE_OSL12306_16
    value = osl12306_16.display(0, dispData);
    checkReturnValue(value, FUNCTION_DISPLAY);
#endif /* USE_OSL12306_16 */
    delay(1000);
    clearDispData();
#ifdef USE_OSL12306_16
    value = osl12306_16.clear();
    checkReturnValue(value, FUNCTION_CLEAR);
#endif /* USE_OSL12306_16 */
  }

  checkTestResult(about, 1);
  Serial.println("");
  Serial.println("");

#ifdef USE_OSL12306_16
  value = osl12306_16.clear();
  checkReturnValue(value, FUNCTION_CLEAR);
#endif /* USE_OSL12306_16 */

}


void test3() {
  String about = "test3";

  printStartMessage(about, 2);
  clearDispData();

  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("x (x:-,0,1...,a,b,c...z)");
  Serial.println("");
  waitForStart();

  Serial.println("test3 start.");

  nSegLedFunctionReturnValue value;
  uint64_t flag=1;


  for (int i=0; i< 39 ;i++) {
    if (flag==1) {
      flag = 0;
    } else {
      flag = 1;
    }
    switch(i) {
      case 1: {dispData[0]=0;break;}
      case 2: {dispData[0]='-';break;}
      case 3: {dispData[0]='0';break;}
      case 4: {dispData[0]='1';break;}
      case 5: {dispData[0]='2';break;}
      case 6: {dispData[0]='3';break;}
      case 7: {dispData[0]='4';break;}
      case 8: {dispData[0]='5';break;}
      case 9: {dispData[0]='6';break;}
      case 10: {dispData[0]='7';break;}
      case 11: {dispData[0]='8';break;}
      case 12: {dispData[0]='9';break;}
      case 13: {dispData[0]='a';break;}
      case 14: {dispData[0]='b';break;}
      case 15: {dispData[0]='c';break;}
      case 16: {dispData[0]='d';break;}
      case 17: {dispData[0]='e';break;}
      case 18: {dispData[0]='f';break;}
      case 19: {dispData[0]='g';break;}
      case 20: {dispData[0]='h';break;}
      case 21: {dispData[0]='i';break;}
      case 22: {dispData[0]='j';break;}
      case 23: {dispData[0]='k';break;}
      case 24: {dispData[0]='l';break;}
      case 25: {dispData[0]='m';break;}
      case 26: {dispData[0]='n';break;}
      case 27: {dispData[0]='o';break;}
      case 28: {dispData[0]='p';break;}
      case 29: {dispData[0]='q';break;}
      case 30: {dispData[0]='r';break;}
      case 31: {dispData[0]='s';break;}
      case 32: {dispData[0]='t';break;}
      case 33: {dispData[0]='u';break;}
      case 34: {dispData[0]='v';break;}
      case 35: {dispData[0]='w';break;}
      case 36: {dispData[0]='x';break;}
      case 37: {dispData[0]='y';break;}
      case 38: {dispData[0]='z';break;}
    }
#ifdef USE_OSL12306_16
    value = osl12306_16.display(flag, dispData);
    checkReturnValue(value, FUNCTION_DISPLAY);
#endif /* USE_OSL12306_16 */
    delay(1000);
    clearDispData();
#ifdef USE_OSL12306_16
    value = osl12306_16.clear();
    checkReturnValue(value, FUNCTION_CLEAR);
#endif /* USE_OSL12306_16 */
  }

  checkTestResult(about, 2);
  Serial.println("");
  Serial.println("");

#ifdef USE_OSL12306_16
  value = osl12306_16.clear();
  checkReturnValue(value, FUNCTION_CLEAR);
#endif /* USE_OSL12306_16 */

}

void setup() {
  Serial.begin(9600);

  if (SERIAL_RESET) {
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB
    }
  } else {
    delay(3000);
  }

  Serial.println("");
  Serial.println("");
  Serial.println("1digit led device driver test.");
  Serial.println("");

  nSegLedFunctionReturnValue value;

#ifdef USE_OSL12306_16
  value = osl12306_16.begin();
  checkReturnValue(value, FUNCTION_BEGIN);
  value = osl12306_16.clear();
  checkReturnValue(value, FUNCTION_CLEAR);
#endif /* USE_OSL12306_16 */

  test1();
  test2();
  test3();
  sumTestResult();

}

void loop() {

}


