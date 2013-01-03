#include "config.h"
#include "log.h"

class Test
{
public:
    void TestLog()
    {
        log_w("fdslfjsdl");
    }
};

int main(int argc, char const *argv[])
{
    Test t;
    t.TestLog();
    return 0;
}