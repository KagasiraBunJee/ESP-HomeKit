//
//  esp32_hk_accessory.cpp
//  coredata-imp
//
//  Created by Sergii on 9/24/18.
//  Copyright © 2018 Sergii. All rights reserved.
//

#include "esp32_hk_accessory.hpp"
#include "mdns.h"
#include <Arduino.h>

bool esp32_hk_accessory::init(const char *hostName) {

  esp_err_t err;

  err = mdns_init();

  if (err) {
    return false;
  }

  err = mdns_hostname_set(hostName);

  if (err) {
    return false;
  }

  return true;
}

void esp32_hk_accessory::create_hap_service(int port, const char *devname, const char *mac, const char *acctype, const char *ver, const char *configver) {

  esp_err_t err;

  err = mdns_instance_name_set(devname);

  if (err)
    Serial.println("error with mdns_instance_name_set");

  err = mdns_service_add(devname, "hap", "_tcp", port, NULL, 0);
  if (err)
    Serial.println("error with mdns_service_add");

  err = mdns_service_txt_item_set("hap", "_tcp", "pv", ver);
  if (err)
    Serial.println("error with mdns_service_txt_item_set");
    
  mdns_service_txt_item_set("hap", "_tcp", "id", mac);
  mdns_service_txt_item_set("hap", "_tcp", "c#", configver);
  mdns_service_txt_item_set("hap", "_tcp", "s#", "1");
  mdns_service_txt_item_set("hap", "_tcp", "ff", "0");
  mdns_service_txt_item_set("hap", "_tcp", "sf", "1");
  mdns_service_txt_item_set("hap", "_tcp", "md", devname);
  mdns_service_txt_item_set("hap", "_tcp", "ci", acctype);

  // mdns_service_txt_set("hap", "_tcp", serviceTxtData, 8);
}
