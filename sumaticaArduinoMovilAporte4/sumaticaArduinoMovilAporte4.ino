#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <addons/TokenHelper.h>
#include <ArduinoJson.h>
#define FIREBASE_USE_PSRAM

int led1=21, led2=19, led3=18, led4=15, led5=13, led6=12, led7=14, led8=27,led9=26;
int led10=25, led11=33, led12=2, led13=4, led14=5, led15=34, led16=35, led17=17,led18=16;

//Conectar a una red WiFi 
const char* WIFI_SSID = "Celerity_LFAJARDO";//el nombre de la red
const char* WIFI_PASSWORD = "LUFACO8520";//la contraseña de la red
//Recursos de Firebase
const char* API_KEY = "AIzaSyCERqfZgDb8Gpi1RsycNIq75xio6bcRtvE";
const char* FIREBASE_PROJECT_ID = "pokedex-cf2a8";
//CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "esp32fajardo@gmail.com";
const char* USER_PASSWORD = "ESP32Fajardo.@";

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setupWiFi() {
  // put your setup code here, to run once:
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}
void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback;  // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(led11,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
  pinMode(led14,OUTPUT);
  pinMode(led15,OUTPUT);
  pinMode(led16,OUTPUT);
  pinMode(led17,OUTPUT);
  pinMode(led18,OUTPUT);
  //pinMode(passWa,OUTPUT);
  
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  digitalWrite(led9,LOW);
  digitalWrite(led10LOW);
  digitalWrite(led11,LOW);
  digitalWrite(led12,LOW);
  digitalWrite(led13,LOW);
  digitalWrite(led14,LOW);
  digitalWrite(led15,LOW);
  digitalWrite(led16,LOW);
  digitalWrite(led17,LOW);
  digitalWrite(led18,LOW);
  //digitalWrite(passWa,LOW);

  Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);//Verificamos la version
  setupWiFi();//Llamamos la funcion de configuración wifi
  setupFirebase();//Llamamos la funcion de configuración Firebase
}

void loop(){
String path = "Tipo";//RUTA DE COLECCION
  FirebaseJson json;

  if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", path.c_str(), "")) {

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());

    if (!error) {
      for (JsonObject document : doc["documents"].as<JsonArray>()) {
        const char* document_name = document["name"];//PARAMETRO NOMBRE
     //   Serial.print(document);
        const bool state = document["fields"]["Encender"]["booleanValue"];//PARAMETRO DE CAMPOS A REVISAR
     //   Serial.println(" : ");
        if (strstr(document_name, "Steel") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom1, state);
          state ? Serial.print("Control 1 On") : Serial.println("Control 1 OFF");
        }
        if (strstr(document_name, "Water") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Bug") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Dragon") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Electric") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Ghost") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Fire") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Fairy") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Ice") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Fighting") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Normal") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
        if (strstr(document_name, "Grass") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
         if (strstr(document_name, "Psychic") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
         if (strstr(document_name, "Rock") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
         if (strstr(document_name, "Dark") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
         if (strstr(document_name, "Ground") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
         if (strstr(document_name, "Poison") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
         if (strstr(document_name, "Flying") != nullptr) {//COMPARAR NOMBRE CON  RESULTADO ESPERADO LED1
          digitalWrite(bom2, state);
          state ? Serial.print("Control 2 On") : Serial.println("Control 2 OFF");
        }
      }
    }
	}
}

