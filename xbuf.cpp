#include "xbuf.h"

XBufInter::XBufInter(c8 *data,u32 len)
{
    this->data = data;
    this->len = len;
    refs = 1;
}

void XBufInter::incRef()
{
    refs++;
}

void XBufInter::decRef()
{
    refs--;
}

XBufInter::~XBufInter()
{
    delete data;
    data = NULL;
    u32 = 0;
    refs = 0;
}

XBuf::XBuf()
{
    mDataInter = NULL:
}

XBuf::XBuf(c8 *data,u32 len,b8 copy)
{
    if (!copy) {
        this->data = data;
        this->len = len;
    } else {
        this->data = new c8[len];
        memcpy(this->data,data,len);
    }
}

XBuf::~XBuf() 
{ 
    if (mDataInter != NULL)
        mDataInter.decRef();
}