#if !defined(__XBUF_H__)
#define __XBUF_H__
#include "config.h"
#include "refs.h"
class XBuf:public XRef
{
public:
    XBuf();
    void attach(c8 *d,u32 l);
    void copyFrom(c8 *d,u32 l);
    void free();

    u32 length();
    void append(XBuf &buf);
    void append(c8 *data,u32 l);
    XBuf *subBuf(u32 offset,u32 l);
    void dump();
private:
    c8 *_data;
    u32 _len;
};


#endif