/*
 * GPSService.h
 *
 *  Created on: Aug 14, 2014
 *      Author: Cameron Karlsson
 *
 *  See the license file included with this source.
 */

#ifndef GPSSERVICE_H_
#define GPSSERVICE_H_

#include <nmeaparse/Event.h>
#include <nmeaparse/GPSFix.h>
#include <nmeaparse/NMEAParser.h>

#include <chrono>
#include <functional>
#include <string>

namespace nmea {

class GPSService {
   private:
    void read_PSRF150(const NMEASentence& nmea);
    void read_GPGGA(const NMEASentence& nmea);
    void read_GPGSA(const NMEASentence& nmea);
    void read_GPGSV(const NMEASentence& nmea);
    void read_GPRMC(const NMEASentence& nmea);
    void read_GPVTG(const NMEASentence& nmea);
    void read_GNGSA(const NMEASentence& nmea);
    void read_GLGSV(const NMEASentence& nmea);
    void read_GNGLL(const NMEASentence& nmea);
    void read_GNRMC(const NMEASentence& nmea);
    void read_GNVTG(const NMEASentence& nmea);
    void read_GNGGA(const NMEASentence& nmea);

   public:
    GPSFix fix;

    GPSService(NMEAParser& parser);
    virtual ~GPSService();

    Event<void(bool)> onLockStateChanged;  // user assignable handler, called
                                           // whenever lock changes
    Event<void()>
        onUpdate;  // user assignable handler, called whenever fix changes

    void attachToParser(NMEAParser& parser);  // will attach to this parser's
                                              // nmea sentence events
};

}  // namespace nmea

#endif /* GPSSERVICE_H_ */
