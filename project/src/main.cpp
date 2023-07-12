#include<Arduino.h>
#include<WiFi.h>
#include<AsyncTCP.h>
#include<ESPAsyncWebServer.h>
#include<math.h>
#include"lib.h"

AsyncWebServer server(80);

const char* ssid = "M12";
const char* password = "mohan2003";

const char* input_parameter30 = "input30";
const char* input_parameter31 = "input31";
const char* input_parameter32 = "input32";
const char* input_parameter00 = "input00";
const char* input_parameter01 = "input01";
const char* input_parameter02 = "input02";

const char* matrix1[3]={input_parameter30,input_parameter31,input_parameter32};
const char* matrix2[3]={input_parameter00,input_parameter01,input_parameter02};

const char index_html[] PROGMEM = R"rawliteral(


  

<!DOCTYPE HTML><html><head>
  <title>Find a vector of magnitude of 5 units</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 2.0rem; color: blue;}
  </style> 
  </head><body>
  <h2>Find a vector of magnitude of 5 units</h2> 
  <p>Enter the values of points a,b
  <form action="/get">
    Enter the values of a: <input type="number" name="input30"><br><input type="number" name="input31"><br><input type="number" name="input32"><br>
    Enter the values of b: <input type="number" name="input00"><br><input type="number" name="input01"><br><input type="number" name="input02"><br>
    <input type="submit" value="Submit">
    
  </form><br>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connecting...");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
        int m=3,n=1;
	double **a,**b,**c,**C,**vector;
	double e;
        a = load_ser(request,matrix1);
	b = load_serv(request,matrix2);
        c = matc(a,b);
	e = linalg_norm(c,m);
	C = scalarProduct(1/e,c);
	vector = scalarProduct(5,C);
        request->send(200, "text/html", "The values of vector is <br>[" + String(vector[0][0]) + "]<br>[" + String(vector[1][0]) + "]<br>[" + String(vector[2][0]) + "]<br><a href=\"/\">Return to Home Page</a>");}
	
);   
  server.onNotFound(notFound);
  server.begin();
}
void loop() {
}
