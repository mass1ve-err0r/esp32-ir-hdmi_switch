#include <WiFi.h>
#include <WebServer.h>

#define IR_CMD_NO_REPEAT 0
#define IR_SEND_PIN 4
#define DISABLE_CODE_FOR_RECEIVER
#define EXCLUDE_EXOTIC_PROTOCOLS
#define NO_LED_FEEDBACK_CODE
#include <IRremote.h>

const char* ssid = "Baig IoT";
const char* password = "some_password";
WebServer server(80);


void setup() {
  Serial.begin(115200);
  delay(100);

  // Infrared
  IrSender.begin();
  disableLEDFeedback();
  
  Serial.println("IR-Sensor started");
  delay(100);

  // WiFi
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.print("Attempting to connect to designated WiFi");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  delay(100);

  // WebServer
  server.on("/hdmi/1", handle_toggle_HDMI_1);
  server.on("/hdmi/2", handle_toggle_HDMI_2);
  server.on("/hdmi/3", handle_toggle_HDMI_3);
  server.on("/hdmi/4", handle_toggle_HDMI_4);
  server.on("/hdmi/5", handle_toggle_HDMI_5);
  server.on("/hdmi/6", handle_toggle_HDMI_6);
  server.on("/hdmi/7", handle_toggle_HDMI_7);
  server.on("/hdmi/8", handle_toggle_HDMI_8);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("IR-Remote-Service started!");

  Serial.println("IoT-Device is ready");
}

void loop() {
  // simply wait for HTTP requests and process accordingly
  server.handleClient();
}


// webserver handlers

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

void handle_toggle_HDMI_1() {
  IrSender.sendNEC(0x0, 0x7, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_2() {
  IrSender.sendNEC(0x0, 0x16, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_3() {
  IrSender.sendNEC(0x0, 0xc, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_4() {
  IrSender.sendNEC(0x0, 0x8, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_5() {
  IrSender.sendNEC(0x0, 0x9, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_6() {
  IrSender.sendNEC(0x0, 0xd, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_7() {
  IrSender.sendNEC(0x0, 0x5e, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}

void handle_toggle_HDMI_8() {
  IrSender.sendNEC(0x0, 0x5a, IR_CMD_NO_REPEAT);
  server.send(200, "text/plain", "");
}
