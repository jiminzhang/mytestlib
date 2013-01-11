#if !defined(__XREFS_H__)
#define __XREFS_H__
class XRef
{
public:
    void addRef();
    void release();
private:
    int _refs;
}