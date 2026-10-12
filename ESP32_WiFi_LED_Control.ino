#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "your WiFi name";
const char *password = "your WiFi name password";

WebServer myserver(80);

String html =
    "<!DOCTYPE html>"
    "<html>"
    "<head>"

        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
        "<title>ESP32 Control Panel</title>"
        "<style>"

            "body {"
                "text-align: center;"
                "padding-top: 15vh;"
                "font-family: Tahoma;"
                "background-color: #f2f2f2;"
                "margin: 0;"
            "}"

            "h1 {"
                "font-size: 32px;"
                "color: #333;"
            "}"

            "button {"
                "display: block;"
                "width: 80%;"
                "max-width: 300px;"
                "margin: 15px auto;"
                "padding: 15px;"
                "font-size: 24px;"
                "border: none;"
                "border-radius: 12px;"
                "cursor: pointer;"
                "background-color: #af4c8b;"
                "color: white;"
                "box-shadow: 0 4px 8px rgba(0,0,0,0.2);"
            "}"

            "button:active {"
                "transform: scale(0.97);"
            "}"

            "#status {"
                "font-size: 20px;"
                "margin-top: 30px;"
                "color: #333;"
            "}"

        "</style>"

    "</head>"

    "<body>"

        "<h1>ESP32 Control Panel</h1>"

        "<button onclick=\"turnOn()\">LED ON</button>"

        "<button onclick=\"turnOff()\">LED OFF</button>"

        "<p id=\"status\">LED Status: OFF</p>"


        "<script>"

            "function turnOn() {"

                "fetch('/on')"
                ".then(response => {"

                    "if (response.ok) {"
                        "document.getElementById('status').innerHTML = 'LED Status: ON';"
                    "}"

                "});"

            "}"


            "function turnOff() {"

                "fetch('/off')"
                ".then(response => {"

                    "if (response.ok) {"
                        "document.getElementById('status').innerHTML = 'LED Status: OFF';"
                    "}"

                "});"

            "}"

        "</script>"

    "</body>"
    "</html>";


void setup()
{
    pinMode(33, OUTPUT);

    Serial.begin(115200);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("connecting...");
    }

    Serial.println("WiFi connected!");
    Serial.println(WiFi.localIP());


    myserver.on("/", []()
    {
        myserver.send(200, "text/html", html);
    });


    myserver.on("/on", []()
    {
        digitalWrite(33, HIGH);

        myserver.send(200, "text/plain", "LED ON");
    });


    myserver.on("/off", []()
    {
        digitalWrite(33, LOW);

        myserver.send(200, "text/plain", "LED OFF");
    });


    myserver.begin();
}


void loop()
{
    myserver.handleClient();
}
