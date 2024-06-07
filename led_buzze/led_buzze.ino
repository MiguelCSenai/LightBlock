#include <WebServer.h>
#include <WiFi.h>

const char* ssid = "Miguel";     // Insira o nome da sua rede WiFi
const char* password = "Miguel.3001"; // Insira a senha da sua rede WiFi

#define r 25
#define b 32
#define g 12

WebServer servidor(80); // Cria um servidor na porta 80

void setup() {
  Serial.begin(115200);

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

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

      String pagina = "<!DOCTYPE html>";
  pagina += "<html lang=\"en\">";
  pagina += "<head>";
  pagina += "<meta charset=\"UTF-8\">";
  pagina += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  pagina += "<title>LightBlock</title>";
  pagina += "<style>";
  pagina += "body{";
  pagina += "background: url('https://wallpapers.com/images/hd/stone-cave-and-oak-village-minecraft-hd-qmdm97bkjy0dxgtp.jpg');";
  pagina += "background-position: center";
  pagina += "background-size: cover;";
  pagina += "display: flex;";
  pagina += "flex-direction: column;";
  pagina += "align-items: center;";
  pagina += "justify-content: center;";
  pagina += "padding: 10%;";
  pagina += "}";
  pagina += ".container{";
  pagina += "background: gray;";
  pagina += "border-radius: 20px;";
  pagina += "width: 40%;";
  pagina += "display: flex;";
  pagina += "flex-direction: row;";
  pagina += "gap: 50px;";
  pagina += "justify-content: space-around;";
  pagina += "flex-wrap: wrap;";
  pagina += "padding: 30px;";
  pagina += "}";
  pagina += "a{";
  pagina += "text-decoration: none;";
  pagina += "color: black;";
  pagina += "}";
  pagina += ".items{";
  pagina += "margin: 10px;";
  pagina += "text-decoration: none;";
  pagina += "background-color: azure;";
  pagina += "width: 100px;";
  pagina += "height: 30px;";
  pagina += "text-align: center;";
  pagina += "display: flex;";
  pagina += "flex-direction: column;";
  pagina += "justify-content: center;";
  pagina += "}";
  pagina += "</style>";
  pagina += "</head>";
  pagina += "<body>";
  pagina += "<div class=\"container\">";
  pagina += "<a href=\"/ferro\">";
  pagina += "<div class=\"items\">Ferro</div>";
  pagina += "</a>";
  pagina += "<a href=\"/lapis\">";
  pagina += "<div class=\"items\">Lápis Lazuli</div>";
  pagina += "</a>";
  pagina += "<a href=\"/redstone\">";
  pagina += "<div class=\"items\">Redstone</div>";
  pagina += "</a>";
  pagina += "<a href=\"/ouro\">";
  pagina += "<div class=\"items\">Ouro</div>";
  pagina += "</a>";
  pagina += "<a href=\"/esmeralda\">";
  pagina += "<div class=\"items\">Esmeralda</div>";
  pagina += "</a>";
  pagina += "<a href=\"/diamante\">";
  pagina += "<div class=\"items\">Diamante</div>";
  pagina += "</a>";
  pagina += "</div>";
  pagina += "</body>";
  pagina += "</html>";


  servidor.send(200, "text/html", pagina);
}

void ferro() {
  
  analogWrite(r, 205);
  analogWrite(g, 30);
  analogWrite(b, 10);
  PaginaInicial();

}

void lapis() {
  
  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 255);
  PaginaInicial();

}

void redstone() {
  
  analogWrite(r, 255);
  analogWrite(g, 0);
  analogWrite(b, 0);
  PaginaInicial();

}

void ouro() {

  analogWrite(r, 255);
  analogWrite(g, 30);
  analogWrite(b, 0);
  PaginaInicial();

}

void esmeralda() {
  
  analogWrite(r, 0);
  analogWrite(g, 255);
  analogWrite(b, 0);
  PaginaInicial();

}

void diamante() {
  
  analogWrite(r, 0);
  analogWrite(g, 172);
  analogWrite(b, 252);
  PaginaInicial();

}
