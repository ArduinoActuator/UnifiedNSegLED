#ifndef __UNIFIED_N_SEG_LED_H__
#define __UNIFIED_N_SEG_LED_H__

#include "OSL12306_16.h"
#include "OSL20541.h"
#include "OSL30561.h"
#include "TM1637.h"

enum UnifiedNSegLedType {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
};

enum nSegLedFunctionReturnValue {
  FUNCTION_UNSUPPORTED = 1,
  FUNCTION_SUCCESS,
  FUNCTION_FAIL,
};

class UnifiedNSegLED {
public:
  UnifiedNSegLED(OSL30561* osl30561, UnifiedNSegLedType type);
  UnifiedNSegLED(OSL20541* osl20541, UnifiedNSegLedType type);
  UnifiedNSegLED(OSL12306_16* osl12306_16, UnifiedNSegLedType type);
  UnifiedNSegLED(TM1637* tm1637, UnifiedNSegLedType type);

  nSegLedFunctionReturnValue set(uint8_t = BRIGHT_TYPICAL,uint8_t = 0x40,uint8_t = 0xc0);
  nSegLedFunctionReturnValue setColomn(bool flag);

  nSegLedFunctionReturnValue begin(void);
  nSegLedFunctionReturnValue clear(void);
  nSegLedFunctionReturnValue display(uint64_t points, char dispData[]);
  nSegLedFunctionReturnValue display(char dispData[]);
protected:
  nSegLedFunctionReturnValue analyzeRstValue(uint8_t val);
  int8_t convChar(char);
  UnifiedNSegLedType _type;
  OSL30561 * _osl30561;
  OSL20541 * _osl20541;
  OSL12306_16 * _osl12306_16;
  TM1637 * _tm1637;
};



#endif /* __UNIFIED_N_SEG_LED_H__ */
