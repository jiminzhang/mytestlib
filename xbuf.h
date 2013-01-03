#if !defined(__XBUF_H__)
#define __XBUF_H__
#include "config.h"

class XBufInter
{
public:
    XBufInter(c8 *data,u32 len);
    void incRef();
    void decRef();
    ~XBufInter();
private:
    u8 *data;
    u32 len;
    u32 refs;
};

class XBuf
{
public:
    XBuf();
    XBuf(c8 *data,u32 len);
    XBuf(const XBuf &buf);
    ~XBuf() 
    { 
        if (mDataInter != NULL)
            mDataInter.decRef();
    }
private:
    XBufInter *mDataInter;
};


#endif