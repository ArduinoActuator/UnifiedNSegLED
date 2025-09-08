# API

## 返り値

```
typedef enum {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
} UnifiedNSegLedType;

typedef enum {
  NSEGLED_FUNCTION_UNSUPPORTED = 1,
  NSEGLED_FUNCTION_SUCCESS,
  NSEGLED_FUNCTION_FAIL,
} nSegLedFunctionReturnValue;
```


## クラスオブジェクトの作成と初期化

本NセグメントLED用APIのクラスオブジェクトは，各デバイス専用のクラスオブジェクトを作成してから，そのオブジェクトを引数として
NセグメントLED共通のクラスオブジェクトを生成する．

そのため，デバイス種類ごとに手順が変わる．

### 16セグメントLEDの場合([OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA])
NセグメントLEDのクラスオブジェクト作成するためには，多数のピンとその並び順の定義が必要になるが，以下はその事例．
```
#define OSL12306_16_PIN_A1 37
#define OSL12306_16_PIN_A2 34
#define OSL12306_16_PIN_B 33
#define OSL12306_16_PIN_C 29
#define OSL12306_16_PIN_D1 24
#define OSL12306_16_PIN_D2 27
#define OSL12306_16_PIN_E 23
#define OSL12306_16_PIN_F 39
#define OSL12306_16_PIN_G1 22
#define OSL12306_16_PIN_G2 32
#define OSL12306_16_PIN_J 38
#define OSL12306_16_PIN_K 36
#define OSL12306_16_PIN_L 35
#define OSL12306_16_PIN_M 28
#define OSL12306_16_PIN_N 26
#define OSL12306_16_PIN_P 25
#define OSL12306_16_PIN_DP 30
#define OSL12306_16_PIN_DIGIT 31


#define OSL12306_16_NUM_OF_PINS _OSL12306_16_CHAR_PINS // 「_OSL12306_16_CHAR_PINS」は「OSL12306_16.h」で定義
#define OSL12306_16_NUM_OF_DIGITS 1

uint8_t pins[OSL12306_16_NUM_OF_PINS] = {
  OSL12306_16_PIN_A1 , OSL12306_16_PIN_A2 , OSL12306_16_PIN_B , OSL12306_16_PIN_C , OSL12306_16_PIN_D1 , OSL12306_16_PIN_D2 , OSL12306_16_PIN_E , OSL12306_16_PIN_F , 
  OSL12306_16_PIN_G1 , OSL12306_16_PIN_G2 , OSL12306_16_PIN_J , OSL12306_16_PIN_K , OSL12306_16_PIN_L , OSL12306_16_PIN_M , OSL12306_16_PIN_N , OSL12306_16_PIN_P
};

uint8_t digitPins[OSL12306_16_NUM_OF_DIGITS] = {OSL12306_16_PIN_DIGIT};

OSL12306_16 __osl12306_16(
  ANODE_COMMON,  // 「ANODE_COMMON」は「OSL12306_16.h」で定義
  pins,
  OSL12306_16_PIN_DP,
  OSL12306_16_NUM_OF_DIGITS,
  digitPins
);

UnifiedNSegLED osl12306_16(&__osl12306_16, OSL12306_16_TYPE);
```

以下は，作成した16セグメントLED用のクラスオブジェクトを使って，統一APIのクラスオブジェクトを作成して，初期化するAPIである．

```
UnifiedNSegLED(OSL12306_16* osl12306_16, UnifiedNSegLedType type);
nSegLedFunctionReturnValue begin(void);
```
クラスオブジェクトを作成する際の第2引数は，以下の``enum``で定義されている値を用いる．
```
typedef enum {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
} UnifiedNSegLedType;

```

### 14セグメントの場合([OSL20541-IR(秋月電子)][OSL20541IR]など)
NセグメントLEDのクラスオブジェクト作成するためには，多数のピンとその並び順の定義が必要になる．，以下は[OSL20541-IR(秋月電子)][OSL20541IR](14ピン2桁)の事例．

```
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

UnifiedNSegLED osl20541(&__osl20541, OSL20541_TYPE);
```

以下は，作成した16セグメントLED用のクラスオブジェクトを使って，統一APIのクラスオブジェクトを作成して，初期化するAPIである．

```
UnifiedNSegLED(OSL20541* osl20541, UnifiedNSegLedType type);
nSegLedFunctionReturnValue begin(void);
```
クラスオブジェクトを作成する際の第2引数は，以下の``enum``で定義されている値を用いる．
```
typedef enum {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
} UnifiedNSegLedType;

```

### 7セグメントの場合([OSL30561-IRA(秋月電子)][OSL30561IRA])
NセグメントLEDのクラスオブジェクト作成するためには，多数のピンとその並び順の定義が必要になる．，以下は[OSL30561-IRA(秋月電子)][OSL30561IRA](7ピン3桁)の事例．

```
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

UnifiedNSegLED osl30561(&__osl30561, OSL30561_TYPE);
```



以下は，作成した16セグメントLED用のクラスオブジェクトを使って，統一APIのクラスオブジェクトを作成して，初期化するAPIである．

```
UnifiedNSegLED(OSL30561* osl30561, UnifiedNSegLedType type);
nSegLedFunctionReturnValue begin(void);
```
クラスオブジェクトを作成する際の第2引数は，以下の``enum``で定義されている値を用いる．
```
typedef enum {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
} UnifiedNSegLedType;

```


### [Grove - 4-Digit Display][Grove4DigitLED]の場合(TM1637をコントローラとして利用した時計型7セグメントLED)の場合

NセグメントLEDのクラスオブジェクト作成するためには，多数のピンとその並び順の定義が必要になる．，以下は[Grove - 4-Digit Display][Grove4DigitLED]の事例．

```
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 3
TM1637 __tm1637(CLK,DIO);
UnifiedNSegLED tm1637(&__tm1637, GROVE_TM1637_TYPE);
```

```
UnifiedNSegLED(TM1637* tm1637, UnifiedNSegLedType type);
nSegLedFunctionReturnValue begin(void);
```
クラスオブジェクトを作成する際の第2引数は，以下の``enum``で定義されている値を用いる．
```
typedef enum {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
} UnifiedNSegLedType;

```


## 表示を消す

```
nSegLedFunctionReturnValue clear(void);
```

## 時計型LEDのコロンの点灯/消灯([Grove - 4-Digit Display][Grove4DigitLED]のみ)
引数の真偽でコロンを点けるか消すかを制御．
```
nSegLedFunctionReturnValue setColomn(bool flag);
```

## 時計型LEDの明るさ設定([Grove - 4-Digit Display][Grove4DigitLED]のみ)

```
nSegLedFunctionReturnValue set(uint8_t = BRIGHT_TYPICAL,uint8_t brightness, uint8_t set_data, uint8_t set_addr);
```
第1引数に渡される値(明るさ)のうち，
よく使われる明るさは，[Grove - 4-Digit Display][Grove4DigitLED]のドライバで定義されている．
```
#define BRIGHT_DARKEST 0
#define BRIGHT_TYPICAL 2
#define BRIGHTEST 7
```
第2,3引数は[Grove - 4-Digit Display][Grove4DigitLED]を使う場合はデフォルト(引数省略)で良い．

## 文字の表示
各桁に文字を表示するためのAPI．
```
nSegLedFunctionReturnValue display(const char dispData[]);
```


## 文字の表示([Grove - 4-Digit Display][Grove4DigitLED]以外)
[Grove - 4-Digit Display][Grove4DigitLED]以外は，各桁に句点(ピリオド)がつくため，
各桁のピリオドのON/OFFを2進数の各桁と対応付けて表し，それを第1引数とする．
第2引数は表示する文字の配列．
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

## 注意事項
[Grove - 4-Digit Display][Grove4DigitLED]以外のNセグメントLEDは，目の残像現象を使って文字表示を実現しているため，
文字表示設定直後に一瞬だけ表示され，その後は消えるもしくは，1箇所のみ点灯している状態となるため，文字表示を
繰り返して実行する必要がある．

Arduinoの場合は，``loop()``の内部には，本APIの``display()``以外の処理は極力行わないようにし，
行う場合でも，実行時間が極めて短いもののみに留める必要がある．



<!-- NセグメントLED -->

|セグメント数|桁数|種別番号|名称/型番|コントローラ|電圧(V)|
|---|---|---|---|---|---|
|16|1|2|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|なし|3.6～5.0(逆電圧:10)|
|14|2|2|[OSL20541-IR(秋月電子)][OSL20541IR]|なし|2.1(逆電圧:5)|
|7|3|2|[OSL30561-IRA(秋月電子)][OSL30561IRA]|なし|2.1(逆電圧:5)|
|7|4|1|[Grove - 4-Digit Display][Grove4DigitLED]|TM1637|3.3～5.5|

|種別番号|コンマ/コロン/ピリオド等|
|---|---|
|1|時計タイプ(真ん中にセミコロン)|
|2|各桁にピリオド|

<!-- 16セグLED -->
[OSL12306-16-IRA]:https://akizukidenshi.com/catalog/g/g114656/
<!-- 2桁 14セグLED + 2*コンマ -->
[OSL20541IR]:https://akizukidenshi.com/catalog/g/g116389/
<!-- 3桁 7セグLED + 3*コンマ -->
[OSL30561IRA]:https://akizukidenshi.com/catalog/g/g117364/
<!-- 4桁 7セグLED + 1*コロン -->
[Grove4DigitLED]:https://wiki.seeedstudio.com/Grove-4-Digit_Display/




<!-- Arduino 本体 -->

|機種名|コア|MCU|動作電圧|
|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|Xtensa LX6|ESP32-S3|3.3V|
|[Arduino Mega 2560][Mega2560]|AVR|ATmega2560|5V|
|[Arduino M0 pro][M0Pro]|ARM Cortex-M0+|ATSAMD21G18|3.3V|
|[Arduino UNO R4 WiFi][UnoR4WiFi]|ARM Cortex-M4|RA4M1|5V|
|[Arduino UNO R4 Minima][UnoR4Minima]|ARM Cortex-M4|RA4M1|5V|
|[Arduino Nano 33 IoT][Nano33IoT]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|ARM Cortex-M7|STM32H747XI|3.3V|
|[Arduino MKR WiFi 1010][MKRWiFi1010]|ARM Cortex-M0+|SAMD21|3.3V|
|[Ardino MKR Zero][MKRZero]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|ARM Cortex-M0+|Raspberry Pi RP2040|3.3V|

<!-- Arduino Nano ESP32 -->
[NanoESP32]:https://docs.arduino.cc/hardware/nano-esp32/
<!--Arduino Mega 2560-->
[Mega2560]:https://docs.arduino.cc/hardware/mega-2560/
<!--Arduino M0 pro-->
[M0Pro]:https://docs.arduino.cc/retired/boards/arduino-m0-pro/
<!--Arduino UNO R4 WiFi-->
[UnoR4WiFi]:https://docs.arduino.cc/hardware/uno-r4-wifi/
<!--Arduino UNO R4 Minima-->
[UnoR4Minima]:https://docs.arduino.cc/hardware/uno-r4-minima/
<!--Arduino Nano 33 IoT-->
[Nano33IoT]:https://docs.arduino.cc/hardware/nano-33-iot/
<!--Arduino Giga R1 Wifi-->
[GigaR1WiFi]:https://docs.arduino.cc/hardware/giga-r1-wifi/
<!--Arduino MKR WiFi 1010-->
[MKRWiFi1010]:https://docs.arduino.cc/hardware/mkr-wifi-1010/
<!--Ardino MKR Zero-->
[MKRZero]:https://docs.arduino.cc/hardware/mkr-zero/
<!--Arduino Nano RP2040 Connect-->
[NanoRP2040Connect]:https://docs.arduino.cc/hardware/nano-rp2040-connect/




<!--- コメント
[Adafruit Unified Sensor Driver][AdafruitUSD]
[Groveシールド][shield]
[Arduino M0 Pro][M0Pro]
[Arduino Due][Due]
[Arduino Uno R3][Uno]
[Arduino Mega2560 R3][Mega]
[Arduino Leonardo Ethernet][LeonardoEth]
[Arduino Pro mini 328 - 3.3V/8MHz][ProMini]
[ESpr one][ESPrOne]
[ESPr one 32][ESPrOne32]
[Grove][Grove]
[Seed Studio][SeedStudio]
[Arduino][Arduino]
[Sparkfun][Sparkfun]
[スイッチサイエンス][SwitchScience]
--->
