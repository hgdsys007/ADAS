/*H**********************************************************************
* FILENAME :        Serial.h             
*
* DESCRIPTION : Serial Hardware Header
*************************************************************************/
#include <ADAS_Types.h>

#ifndef HAL_SERIAL_H
#define HAL_SERIAL_H

class CSerial{
public:
  typedef enum {
    Port1,
    Port2,
    Port3
  }PortNum_e;
  /*
   * Constructor
   */
  CSerial(PortNum_e ID);
  /*
   * Destructor
   */
  ~CSerial();
  /*
   * Initialization
   */
  void Init(unsigned int baud, unsigned short time_out);
  /*
   * Send Data
   */
   bool Send(char Buff[], uint8_t len);
   bool Read(char Buff[], uint8_t len);
   uint8_t Available(void);
 private:
   PortNum_e m_PortID;
  
};

#endif /*HAL_SERIAL_H*/
