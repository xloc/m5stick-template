# Code Snippets

Some code snippets I learn from many sources


### reset when press the AXP button
```c
if(M5.Axp.GetBtnPress()) {
    while(M5.Axp.GetBtnPress()) delay(20);
    ESP.restart();
}
```

### connect to WiFi
```c
const IPAddress ip(10, 1, 1, 2), gateway(10, 1, 1, 1), subnet(255, 255, 255, 0);
if (!WiFi.config(ip, gateway, subnet)) {
    Serial.println("STA Failed to configure");
}
// to use ip from DHCP, ignore the code above

WiFi.mode(WIFI_STA);
WiFi.begin("ssid", "password");
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}

Serial.println("\nWiFi connected.");
Serial.printf("IP address: %s", WiFi.localIP().toString().c_str());
```

### ESP async web server
from [official example](https://github.com/me-no-dev/ESPAsyncWebServer/blob/master/examples/simple_server/simple_server.ino)
```c

AsyncWebServer server(80); // you may want to put it in the global scope

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    // shouldn't use `delay()` in the callback fn
    request->send(200, "text/plain", "Hello, world");
});

server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "Not found");
});

server.begin(); // non-blocking, main loop can be used to do whatever you want
```
