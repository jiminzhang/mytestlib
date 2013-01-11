class XString:XRef
{
public:
    XString();
    void attach(c8 *data,u32 l);
    void copyFrom(c8 *data,u32 l);
    
    void append(c8 *data,u32 l);
    void subStr(u32 offset,u32 l);
    u32 length();

    XString &format();

private:
    c8 *_data;
    u32 _len;
}