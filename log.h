#include "config.h"

enum LogLevel
{
    eLogInfo = 0,
    eLogDebug,
    eLogWarning,
    eLogError
};

void log_print(LogLevel level,const c8 *file,const c8 *func,const u32 line,const c8 *fmt,...);

#if defined(ENABLE_LOG)
#define log_i(fmt,arg...) log_print(eLogInfo,__FILE__,__func__,__LINE__,fmt,##arg)
#define log_d(fmt,arg...) log_print(eLogDebug,__FILE__,__func__,__LINE__,fmt,##arg)
#define log_w(fmt,arg...) log_print(eLogWarning,__FILE__,__func__,__LINE__,fmt,##arg)
#define log_e(fmt,arg...) log_print(eLogError,__FILE__,__func__,__LINE__,fmt,##arg)
#else
#define log_i(fmt,arg...)
#define log_d(fmt,arg...)
#define log_w(fmt,arg...)
#define log_e(fmt,arg...)
#endif