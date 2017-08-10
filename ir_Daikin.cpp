/*

2. Send a copy of your work to us so we can include it in the library and
   others may benefit from your hard work and maybe even write a song about how
   great you are for helping them! :)

*/

#include "IRremote.h"
#include "IRremoteInt.h"

//==============================================================================
//
//
//                              D A I K I N
//
//
//==============================================================================

#define BITS          99  // The number of bits in the command

#define HDR_MARK    3650  // The length of the Header:Mark
#define HDR_SPACE   1623  // The lenght of the Header:Space

#define BIT_MARK     428  // The length of a Bit:Mark
#define ONE_SPACE   1280  // The length of a Bit:Space for 1's
#define ZERO_SPACE   428  // The length of a Bit:Space for 0's

//+=============================================================================
//
#if SEND_DAIKIN
void  IRsend::sendDaikin (unsigned char buf[], int len)
{
	// Set IR carrier frequency
	enableIROut(38);

	// Header
	mark (HDR_MARK);
	space(HDR_SPACE);

	// Data
  	for (int i = 0; i < len; i++) {
		data = buf[i];  
		for (int j = 0; j < 8; j++) {
    		if ((1 << j & data)) {
				mark(BIT_MARK);
      			space(ONE_SPACE);
 			} else {
      			mark(BIT_MARK);
      			space(ZERO_SPACE);
			}
    	} 
	}

	// Footer
	mark(BIT_MARK);
	space(ZERO_SPACE);
  }
}
#endif
