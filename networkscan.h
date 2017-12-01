#include "configure.h"

extern "C" {
#include <termios.h>
}

namespace cpa {


class SerialPort {
    public:
    SerialPort  (Config& config_);
    ~SerialPort (void);

    /* interface */
    void flush      (void);
    void write_data (uint8_t* data, size_t length);
    int  read_data  (uint8_t *data, size_t length);
    bool open_port  (void);

    private:
    
    void close_port     (void);
    void configure_port (void);


    Config         config;
    int            port;
    struct termios port_config;
    struct termios curr_config;
};


}