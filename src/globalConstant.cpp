#include "globalConstant.h"

void my_sleep(int second)
{
    std::this_thread::sleep_for(std::chrono::seconds(second));
}