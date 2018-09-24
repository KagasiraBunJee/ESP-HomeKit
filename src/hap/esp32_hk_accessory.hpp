//
//  esp32_hk_accessory.hpp
//  coredata-imp
//
//  Created by Sergii on 9/24/18.
//  Copyright © 2018 Sergii. All rights reserved.
//

#ifndef esp32_hk_accessory_hpp
#define esp32_hk_accessory_hpp

#include <stdio.h>
#include "hap.h"

#endif /* esp32_hk_accessory_hpp */

class esp32_hk_accessory {
public:
    bool init(const char* hostName);
    void create_hap_service(int port, const char *devname, const char *mac, const char *acctype, const char *ver, const char *configver);
};
