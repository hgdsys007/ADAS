/*H**********************************************************************
* FILENAME :        PLSCOmms.h             
*
* DESCRIPTION : PLS communication layer
*************************************************************************/
#include "ADAS_Types.h"
#include "ADAS_Cfg.h"
#include "HAL_Serial_IF.h"
#include "CBuffer.h"

#ifndef COMMS_PLS_H
#define COMMS_PLS_H



class CPLSComms
{
public:
    typedef enum {
        MsgSuccess =0,
        CRCCheckFail = 1,
        CommsError = 2,
        PartialMsg = 3,
        Msg_NCK =4,
        InvalidReq =5
    } Status_e;
    typedef struct {
        uint8_t* data;
        uint16_t len;
        uint16_t start;
        uint8_t messageID;
    } Message_t;

    CPLSComms(CSerial& serPort);
    ~CPLSComms();
    /*
    * init
    */
    Status_e Init(void);
    /*
    * Get Measurements
    */
    bool GetMeasurements(Message_t& msg, uint16_t& len, bool onlyVert);
    bool GetAsyncData(Message_t& msg, uint16_t& len);
    /*is protectuve field breached
    */
    bool IsPFBreached();
    /*
    * Get status of PLS
    */
    Status_e GetStatus(void);
    /*
    * Parse recieved message
    */
    bool SearchMsg(Message_t& msg, uint8_t ID, uint16_t len);
    /*
    * Recieve a packet
    */
    Status_e  RecievePkt(uint16_t& len);
private:
    /*
    * Calculate CRC
    */
    uint16_t CalcCrC(uint8_t* data, uint16_t len);
    /*
    * Parse recieved message
    */
    Status_e  ParseMsgContent(Message_t& msg, uint16_t start, uint16_t len);
    /*
    * Parse recieved message
    */
    void  CreatePacket(CBuffAdas& buff, uint8_t* Data);
    
    CSerial& m_serPort;
    uint8_t m_sndBuff[PLS_SND_BUFF_SIZE];
    uint8_t m_rcvBuff[PLS_RCV_BUFF_SIZE];
    Status_e m_status;
};

#endif /*COMMS_PLS_H*/
