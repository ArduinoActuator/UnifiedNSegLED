/*
 * LEDの選択
 */
//#define USE_OSL20541
//#define USE_OSL30561
//#define USE_OSL12306_16
#define USE_DFR0090

/*
 * ピン番号の定義
 */
#ifdef USE_OSL20541
#define OSL20541_PIN_1 34
#define OSL20541_PIN_2 35
#define OSL20541_PIN_4 36
#define OSL20541_PIN_5 37
#define OSL20541_PIN_6 38
#define OSL20541_PIN_7 39
#define OSL20541_PIN_8 40
#define OSL20541_PIN_9 41
#define OSL20541_PIN_10 42
#define OSL20541_PIN_11 43
#define OSL20541_PIN_12 44
#define OSL20541_PIN_13 45
#define OSL20541_PIN_14 46
#define OSL20541_PIN_15 47
#define OSL20541_PIN_16 48
#define OSL20541_PIN_17 49
#define OSL20541_PIN_18 50
#endif /* USE_OSL20541 */

#ifdef USE_OSL30561
#define OSL30561_PIN_1 26
#define OSL30561_PIN_2 25
#define OSL30561_PIN_3 29
#define OSL30561_PIN_4 24
#define OSL30561_PIN_5 28
//
#define OSL30561_PIN_7 23
#define OSL30561_PIN_8 30
#define OSL30561_PIN_9 31
#define OSL30561_PIN_10 27
#define OSL30561_PIN_11 22
#define OSL30561_PIN_12 32
#endif /* USE_OSL30561 */

#include "UnifiedNSegLED.h"
#include "detectArduinoHardware.h"


#ifdef USE_OSL20541
#define SEGMENT_NUM 14
#define PRINTABLE_CHAR_NUM 38

#define OSL20541_PIN_A OSL20541_PIN_12
#define OSL20541_PIN_B OSL20541_PIN_10
#define OSL20541_PIN_C OSL20541_PIN_9
#define OSL20541_PIN_D OSL20541_PIN_7
#define OSL20541_PIN_E OSL20541_PIN_1
#define OSL20541_PIN_F OSL20541_PIN_18
#define OSL20541_PIN_G1 OSL20541_PIN_13
#define OSL20541_PIN_G2 OSL20541_PIN_6
#define OSL20541_PIN_H OSL20541_PIN_17
#define OSL20541_PIN_J OSL20541_PIN_15
#define OSL20541_PIN_K OSL20541_PIN_14
#define OSL20541_PIN_L OSL20541_PIN_5
#define OSL20541_PIN_M OSL20541_PIN_4
#define OSL20541_PIN_N OSL20541_PIN_2
#define OSL20541_PIN_DP OSL20541_PIN_8
#define OSL20541_PIN_DIGIT_1 OSL20541_PIN_16
#define OSL20541_PIN_DIGIT_2 OSL20541_PIN_11


#define OSL20541_NUM_OF_DIGITS 2
#define OSL20541_NUM_OF_CHAR_PINS _OSL20541_CHAR_PINS
#define DIGITS OSL20541_NUM_OF_DIGITS

uint8_t osl20541_charPins[OSL20541_NUM_OF_CHAR_PINS] = {
  OSL20541_PIN_A,
  OSL20541_PIN_B,
  OSL20541_PIN_C,
  OSL20541_PIN_D,
  OSL20541_PIN_E,
  OSL20541_PIN_F,
  OSL20541_PIN_G1,
  OSL20541_PIN_G2,
  OSL20541_PIN_H,
  OSL20541_PIN_J,
  OSL20541_PIN_K,
  OSL20541_PIN_L,
  OSL20541_PIN_M,
  OSL20541_PIN_N
};
uint8_t osl20541_digitPins[OSL20541_NUM_OF_DIGITS] = {OSL20541_PIN_DIGIT_1, OSL20541_PIN_DIGIT_2};

OSL20541 __osl20541(
  ANODE_COMMON,
  osl20541_charPins,
  OSL20541_PIN_DP,
  OSL20541_NUM_OF_DIGITS,
  osl20541_digitPins
);

UnifiedNSegLED nSegLed(&__osl20541, OSL20541_TYPE);
#endif /* USE_OSL20541 */

#ifdef USE_OSL30561
#define SEGMENT_NUM 7
#define PRINTABLE_CHAR_NUM 18

#define OSL30561_PIN_A OSL30561_PIN_11
#define OSL30561_PIN_B OSL30561_PIN_7
#define OSL30561_PIN_C OSL30561_PIN_4
#define OSL30561_PIN_D OSL30561_PIN_2
#define OSL30561_PIN_E OSL30561_PIN_1
#define OSL30561_PIN_F OSL30561_PIN_10
#define OSL30561_PIN_G OSL30561_PIN_5
#define OSL30561_PIN_DP OSL30561_PIN_3
#define OSL30561_PIN_DIGIT_1 OSL30561_PIN_12
#define OSL30561_PIN_DIGIT_2 OSL30561_PIN_9
#define OSL30561_PIN_DIGIT_3 OSL30561_PIN_8

#define OSL30561_NUM_OF_DIGITS 3
#define DIGITS OSL30561_NUM_OF_DIGITS
uint8_t osl30561_digitPins[OSL30561_NUM_OF_DIGITS] = {OSL30561_PIN_DIGIT_1, OSL30561_PIN_DIGIT_2, OSL30561_PIN_DIGIT_3};

OSL30561 __osl30561(
  OSL30561_TYPE_ANODE_COMMON,
  OSL30561_PIN_A,
  OSL30561_PIN_B,
  OSL30561_PIN_C,
  OSL30561_PIN_D,
  OSL30561_PIN_E,
  OSL30561_PIN_F,
  OSL30561_PIN_G,
  OSL30561_PIN_DP,
  OSL30561_NUM_OF_DIGITS,
  osl30561_digitPins
);

UnifiedNSegLED nSegLed(&__osl30561, OSL30561_TYPE);
#endif /* USE_OSL30561 */

#ifdef USE_OSL12306_16
#endif /* USE_OSL12306_16 */


#ifdef USE_DFR0090
//Pin connected to clock pin (SH_CP) of 74HC595
#define DFR0090_CLOCK_PIN 3
//Pin connected to latch pin (ST_CP) of 74HC595
#define DFR0090_LATCH_PIN 8
//Pin connected to Data in (DS) of 74HC595
#define DFR0090_DATA_PIN  9
//7SegLEDの数
#define DFR0090_DIGITS    8

#define DIGITS DFR0090_DIGITS
#define PRINTABLE_CHAR_NUM 18

DFR0090 _dfr(DFR0090_CLOCK_PIN, DFR0090_LATCH_PIN, DFR0090_DATA_PIN, DFR0090_DIGITS);

UnifiedNSegLED nSegLed(&_dfr, DFR0090_TYPE);
#endif /* USE_DFR0090 */

unsigned int stage=0;
unsigned int test=1;

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
  test++;
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

unsigned long lastTime=0;

//  テストシナリオ1 : ピリオドの点灯/消灯

unsigned long test1_stage0() {

  //
  unsigned long retVal =1;
  for (int i=0; i<DIGITS; i++) {
    retVal=retVal*2;
  }

  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("ON/OFF period 10 times");
  Serial.println("");
  waitForStart();

  Serial.println("test1 start.");
  stage = 1;

  return retVal;
}

void test1_stageX() {
  nSegLedFunctionReturnValue value;

  value = nSegLed.display(stage, dispData);
  checkReturnValue(value, FUNCTION_DISPLAY);
}

unsigned long max_loop;

void test1() {

  nSegLedFunctionReturnValue value;

  
  String about = "test1";

  if (stage==0) {
    printStartMessage(about, 0);
    clearDispData();
    max_loop =test1_stage0();
    lastTime=millis();
  } else if ((stage >0) && (stage < max_loop)) {
    test1_stageX();
    unsigned long currentTime=millis();
    if (500 < (currentTime - lastTime)) {
      lastTime = currentTime;
      stage++;
    };
  } else {
    checkTestResult(about, 0);
    Serial.println("");
    Serial.println("");

    value = nSegLed.clear();
    checkReturnValue(value, FUNCTION_CLEAR);

    test++;
    stage=0;
  }
}

void test2_stage0() {
  // テスト内容の説明
  Serial.println("=== action ===");

#if PRINTABLE_CHAR_NUM==38
  Serial.println("x (x:-,0,1...,a,b,c...z)");
#else
  Serial.println("x (x:-,0,1...,a,b,c,d,e,f)");
#endif

  Serial.println("");
  waitForStart();

  Serial.println("test2 start.");
  stage =1;
}

void test2() {
  nSegLedFunctionReturnValue value;
  String about = "test2";

  if (stage==0) {
    printStartMessage(about, 1);
    clearDispData();
    test2_stage0();
    lastTime=millis();
  } else if ((stage>0) &&(stage <(PRINTABLE_CHAR_NUM+1))) {
    for (int j=0; j< DIGITS; j++) {
      switch(stage) {
        case 1: {dispData[j]=0;break;}
        case 2: {dispData[j]='-';break;}
        case 3: {dispData[j]='0';break;}
        case 4: {dispData[j]='1';break;}
        case 5: {dispData[j]='2';break;}
        case 6: {dispData[j]='3';break;}
        case 7: {dispData[j]='4';break;}
        case 8: {dispData[j]='5';break;}
        case 9: {dispData[j]='6';break;}
        case 10: {dispData[j]='7';break;}
        case 11: {dispData[j]='8';break;}
        case 12: {dispData[j]='9';break;}
        case 13: {dispData[j]='a';break;}
        case 14: {dispData[j]='b';break;}
        case 15: {dispData[j]='c';break;}
        case 16: {dispData[j]='d';break;}
        case 17: {dispData[j]='e';break;}
        case 18: {dispData[j]='f';break;}
#if PRINTABLE_CHAR_NUM==38
        case 19: {dispData[j]='g';break;}
        case 20: {dispData[j]='h';break;}
        case 21: {dispData[j]='i';break;}
        case 22: {dispData[j]='j';break;}
        case 23: {dispData[j]='k';break;}
        case 24: {dispData[j]='l';break;}
        case 25: {dispData[j]='m';break;}
        case 26: {dispData[j]='n';break;}
        case 27: {dispData[j]='o';break;}
        case 28: {dispData[j]='p';break;}
        case 29: {dispData[j]='q';break;}
        case 30: {dispData[j]='r';break;}
        case 31: {dispData[j]='s';break;}
        case 32: {dispData[j]='t';break;}
        case 33: {dispData[j]='u';break;}
        case 34: {dispData[j]='v';break;}
        case 35: {dispData[j]='w';break;}
        case 36: {dispData[j]='x';break;}
        case 37: {dispData[j]='y';break;}
        case 38: {dispData[j]='z';break;}
#endif
      }
    }

    value = nSegLed.display(0, dispData);
    checkReturnValue(value, FUNCTION_DISPLAY);

    unsigned long currentTime=millis();
    if (500 < (currentTime - lastTime)) {
      lastTime = currentTime;
      stage++;
    };
  } else {
    checkTestResult(about, 1);
    Serial.println("");
    Serial.println("");

    value = nSegLed.clear();
    checkReturnValue(value, FUNCTION_CLEAR);


    test++;
    stage=0;
    clearDispData();
  }
}

void test3_stage0() {
  // テスト内容の説明
  Serial.println("=== action ===");
#if PRINTABLE_CHAR_NUM==38
  Serial.println("x. (x:-,0,1...,a,b,c...z)");
#else
  Serial.println("x. (x:-,0,1...,a,b,c,d,e,f)");
#endif
  Serial.println("");
  waitForStart();

  Serial.println("test3 start.");
  stage =1;
}

void test3() {
  nSegLedFunctionReturnValue value;
  String about = "test3";

  if (stage==0) {
    printStartMessage(about, 2);
    clearDispData();
    test3_stage0();
    lastTime=millis();
  } else if ((stage>0) &&(stage <(PRINTABLE_CHAR_NUM+1))) {
    for (int j=0; j< DIGITS; j++) {
      switch(stage) {
        case 1: {dispData[j]=0;break;}
        case 2: {dispData[j]='-';break;}
        case 3: {dispData[j]='0';break;}
        case 4: {dispData[j]='1';break;}
        case 5: {dispData[j]='2';break;}
        case 6: {dispData[j]='3';break;}
        case 7: {dispData[j]='4';break;}
        case 8: {dispData[j]='5';break;}
        case 9: {dispData[j]='6';break;}
        case 10: {dispData[j]='7';break;}
        case 11: {dispData[j]='8';break;}
        case 12: {dispData[j]='9';break;}
        case 13: {dispData[j]='a';break;}
        case 14: {dispData[j]='b';break;}
        case 15: {dispData[j]='c';break;}
        case 16: {dispData[j]='d';break;}
        case 17: {dispData[j]='e';break;}
        case 18: {dispData[j]='f';break;}
#if PRINTABLE_CHAR_NUM==38
        case 19: {dispData[j]='g';break;}
        case 20: {dispData[j]='h';break;}
        case 21: {dispData[j]='i';break;}
        case 22: {dispData[j]='j';break;}
        case 23: {dispData[j]='k';break;}
        case 24: {dispData[j]='l';break;}
        case 25: {dispData[j]='m';break;}
        case 26: {dispData[j]='n';break;}
        case 27: {dispData[j]='o';break;}
        case 28: {dispData[j]='p';break;}
        case 29: {dispData[j]='q';break;}
        case 30: {dispData[j]='r';break;}
        case 31: {dispData[j]='s';break;}
        case 32: {dispData[j]='t';break;}
        case 33: {dispData[j]='u';break;}
        case 34: {dispData[j]='v';break;}
        case 35: {dispData[j]='w';break;}
        case 36: {dispData[j]='x';break;}
        case 37: {dispData[j]='y';break;}
        case 38: {dispData[j]='z';break;}
#endif
      }
    }
    uint64_t flag = (stage-1) % max_loop ;

    value = nSegLed.display(flag, dispData);
    checkReturnValue(value, FUNCTION_DISPLAY);

    unsigned long currentTime=millis();
    if (1500 < (currentTime - lastTime)) {
      lastTime = currentTime;
      stage++;
    };
  } else {
    checkTestResult(about, 2);
    Serial.println("");
    Serial.println("");

    value = nSegLed.clear();
    checkReturnValue(value, FUNCTION_CLEAR);

    test++;
    stage=0;
    clearDispData();
  }
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
  Serial.println("multipul digit n-seg led device driver test.");
  Serial.println("");

  nSegLedFunctionReturnValue value;

  value = nSegLed.begin();
  checkReturnValue(value, FUNCTION_BEGIN);
  value = nSegLed.clear();
  checkReturnValue(value, FUNCTION_CLEAR);

}

void loop() {
  switch(test){
    case 1: {
      test1();break;
    }
    case 2: {
      test2();break;
    }
    case 3: {
      test3();break;
    }
    case 4: {
      sumTestResult();break;
    }
  }
}

