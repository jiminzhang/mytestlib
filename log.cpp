#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define LOG_BUF_LEN 4096

static c8 *kLogLevelStr[4] = {"info","debug","warning","error"};

// TODO: use the string class
void log_print(LogLevel level,const c8 *file,const c8 *func,const u32 line,const c8 *fmt,...)
{
    c8 bufSrc[LOG_BUF_LEN];
    memset(bufSrc,0,LOG_BUF_LEN);
    va_list args;
    va_start(args,fmt);
    s32 size = vsnprintf(bufSrc, LOG_BUF_LEN - 1, fmt, args);// actully the length doesn't need dec 1
    u8 ok = 0;
    if (size > 0 && size < LOG_BUF_LEN)
    {
        // append file and linenum
        c8 bufDst[LOG_BUF_LEN];
        memset(bufDst,0,LOG_BUF_LEN);
        s32 size2 = snprintf(bufDst,LOG_BUF_LEN,"%s: %s#%s#%u %s\n",kLogLevelStr[level],file,func,line,bufSrc);
        if (size2 > 0 && size2 < LOG_BUF_LEN)
        {
            fprintf(stdout,"%s",bufDst);
            return;
        }
    }
    fprintf(stdout,"exceed the log buf limit\n");
}