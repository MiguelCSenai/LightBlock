#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Miguel";     // Insira o nome da sua rede WiFi
const char* password = "Miguel.2008"; // Insira a senha da sua rede WiFi

#define Red 4;
#define Green 6;
#define Blue 8;

WebServer servidor(80); // Cria um servidor na porta 80

void setup() {
  Serial.begin(115200);

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  // Conecta-se à rede WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando à rede WiFi...");
  }

  Serial.println("Conectado à rede WiFi");
  Serial.println("Endereço IP: ");
  Serial.print(WiFi.localIP());

  // Define a rota para a página HTML
  servidor.on("/", HTTP_GET, PaginaInicial);

  servidor.on("/off", HTTP_GET, desligar);
  servidor.on("/ferro", HTTP_GET, ferro);
  servidor.on("/lapis", HTTP_GET, lapis);
  servidor.on("/redstone", HTTP_GET, redstone);
  servidor.on("/ouro", HTTP_GET, ouro);
  servidor.on("/esmeralda", HTTP_GET, esmeralda);
  servidor.on("/diamante", HTTP_GET, diamante);

  servidor.begin();
}

void loop() {
  servidor.handleClient(); // Lida com as solicitações dos clientes
}

void PaginaInicial() {
  // Página HTML simples para controlar o LED e o Buzzer
  String pagina = "<html><body>";
  pagina += "<h1>Controle do LED e Buzzer</h1>";
  pagina += "<a href=\"/ligar\"><button>Ligar LED e Buzzer</button></a><br>";
  pagina += "<a href=\"/desligar\"><button>Desligar LED e Buzzer</button></a>";
  pagina += "</body></html>";
  servidor.send(200, "text/html", pagina);
}

void ferro() {
  
  setColor(222, 188, 167);

}

void lapis() {
  
  setColor(69, 108, 215);

}

void redstone() {
  
  setColor(250, 0, 0);

}

void ouro() {
  
  setColor(247, 233, 74);

}

void esmeralda() {
  
  setColor(22, 216, 96);

}

void diamante() {
  
  setColor(99, 242, 222);

}

void desligar() {
  
  setColor(0, 0, 0);

}
