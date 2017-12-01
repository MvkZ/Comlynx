#include <string>

extern "C" {
#include <termios.h>
}

#include<fcs.h>


namespace cpa {
		
		class Config {
    	public:
    		Config (std::string portname, uint8_t addr = 0x01, uint8_t nw = 0x00) :pn(portname),network(nw),address(addr)
            {
			}

    		const std::string& portname (void) const
    		{
       		return pn;
    		}

    		uint8_t address (void) const {return address;}

    		uint32_t baud (void) const {return baud;}
    		private:
    		std::string pn;

    		uint8_t network;
    		uint8_t address;

    		static const uint8_t frame_se = 0x7E;
    		static const uint8_t frame_address   = 0xFF;
    		static const uint8_t frame_control   = 0x03;

    		static const uint32_t baud           = B19200;
		};
}