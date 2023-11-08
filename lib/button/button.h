#ifndef UGO_BUTTON_LIB
#define UGO_BUTTON_LIB
#include <stdint.h>

class Button{
    public:
        Button(uint8_t pinNumber);
        ~Button();

        void poll();
    private:
};
#endif
