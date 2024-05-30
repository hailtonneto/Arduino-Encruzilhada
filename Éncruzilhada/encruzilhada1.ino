//SEMÁFORO 1
#define LED_VERMELHO1 2
#define LED_AMARELO1 3
#define LED_VERDE1 4

//SEMÁFORO 2
#define LED_VERMELHO2 5
#define LED_AMARELO2 6
#define LED_VERDE2 7

//BOTÃO
#define BTN 8

//ESTADO DO SEMÁFORO
bool estadoVerde = false;
bool estadoAmarelo = false;
bool estadoVermelho = false;
bool temPedestre = false;

void setup(){
  //PORTAS DE SAÍDA DO SEMÁFORO 1
  pinMode(LED_VERMELHO1, OUTPUT);
  pinMode(LED_AMARELO1, OUTPUT);
  pinMode(LED_VERDE1, OUTPUT);
  
  //PORTAS DE SAÍDA DO SEMÁFORO 2
  pinMode(LED_VERMELHO2, OUTPUT);
  pinMode(LED_AMARELO2, OUTPUT);
  pinMode(LED_VERDE2, OUTPUT);
  
  //PORTA DE ENTRADA DO BOTÃO
  pinMode(BTN, INPUT);
}

void loop(){
  //ACIONAMENTO DO LED VERDE DO SEMÁFORO 1 E VERMELHO DO SEMÁFORO 2
  if (!estadoVerde and !estadoAmarelo and !estadoVermelho){
    //MUDANDO SEMÁFORO 1
    digitalWrite(LED_VERMELHO1, LOW);
  	digitalWrite(LED_AMARELO1, LOW);
  	digitalWrite(LED_VERDE1, HIGH);
  
    //MUDANDO SEMÁFORO 2
  	digitalWrite(LED_VERMELHO2, HIGH);
  	digitalWrite(LED_AMARELO2, LOW);
  	digitalWrite(LED_VERDE2, LOW);
    
    //ATUALIZANDO ESTADOS DO SEMÁFORO
    estadoVerde = true;
    estadoAmarelo = false;
    estadoVermelho = false;
    
    //TEMPO DE ESPERA
    delayInterativo(100);
  }
  
  //ACIONAMENTO DO LED AMARELO DO SEMÁFORO 1 E VERMELHO DO SEMÁFORO 2
  else if (estadoVerde and !estadoAmarelo and !estadoVermelho){
    //MUDANDO SEMÁFORO 1
    digitalWrite(LED_VERMELHO1, LOW);
  	digitalWrite(LED_AMARELO1, HIGH);
  	digitalWrite(LED_VERDE1, LOW);
    
  	//MUDANDO SEMÁFORO 2
  	digitalWrite(LED_VERMELHO2, HIGH);
  	digitalWrite(LED_AMARELO2, LOW);
  	digitalWrite(LED_VERDE2, LOW);
    
    //ATUALIZANDO ESTADOS DO SEMÁFORO
    estadoVerde = false;
    estadoAmarelo = true;
    estadoVermelho = false;
    
    //TEMPO DE ESPERA
    delayInterativo(50);
    
    //VERIFICA PRESENÇA DE PEDESTRE
    if (temPedestre){
      atravessarPedestre();
    }
  }
  
  //ACIONAMENTO DO LED VERMELHO DO SEMÁFORO 1 E VERDE DO SEMÁFORO 2
  else if (!estadoVerde and estadoAmarelo and !estadoVermelho){
    //MUDANDO SEMÁFORO 1
    digitalWrite(LED_VERMELHO1, HIGH);
  	digitalWrite(LED_AMARELO1, LOW);
  	digitalWrite(LED_VERDE1, LOW);
    
  	//MUDANDO SEMÁFORO 2
  	digitalWrite(LED_VERMELHO2, LOW);
  	digitalWrite(LED_AMARELO2, LOW);
  	digitalWrite(LED_VERDE2, HIGH);
    
    //ATUALIZANDO ESTADOS DO SEMÁFORO
    estadoVerde = false;
    estadoAmarelo = false;
    estadoVermelho = true;
    
    //TEMPO DE ESPERA
    delayInterativo(100);
  }
  
  //ACIONAMENTO DO LED VERMELHO DO SEMÁFORO 1 E AMARELO DO SEMÁFORO 2
  else if (!estadoVerde and !estadoAmarelo and estadoVermelho){
    //MUDANDO SEMÁFORO 1
    digitalWrite(LED_VERMELHO1, HIGH);
  	digitalWrite(LED_AMARELO1, LOW);
  	digitalWrite(LED_VERDE1, LOW);
  	
    //MUDANDO SEMÁFORO 2
  	digitalWrite(LED_VERMELHO2, LOW);
  	digitalWrite(LED_AMARELO2, HIGH);
  	digitalWrite(LED_VERDE2, LOW);
    
    //TEMPO DE ESPERA
    delayInterativo(50);
    
    //VERIFICA PRESENÇA DE PEDESTRE
    if (temPedestre){
      atravessarPedestre();
    }
    
    //ATUALIZANDO ESTADOS DO SEMÁFORO
    estadoVerde = false;
    estadoAmarelo = false;
    estadoVermelho = false;
  }
  
  //CASO QUALQUER OUTRA COMBINAÇÃO, REINICIA O CICLO
  else {
    //DEIXA APENAS O LED VERDE DO SEMÁFORO 1 ACESO
    digitalWrite(LED_VERMELHO1, LOW);
  	digitalWrite(LED_AMARELO1, LOW);
  	digitalWrite(LED_VERDE1, HIGH);
  
    //DEIXA APENAS O LED VERMELHO DO SEMÁFORO 2 ACESO
  	digitalWrite(LED_VERMELHO2, HIGH);
  	digitalWrite(LED_AMARELO2, LOW);
  	digitalWrite(LED_VERDE2, LOW);
    
    //REINICIA ESTADOS DO SEMÁFORO
    estadoVerde = false;
    estadoAmarelo = false;
    estadoVermelho = false;
  }
}

void delayInterativo(int delayParcial) {
  //DELAYS PARCIAL PARA A LEITURA DO BOTAO
  for (int i = 0; i < 100; i++) {
    //LEITURA DO BOTAO
    if (digitalRead(BTN) == HIGH) {
      //SE BOTAO FOR APERTADO, ACIONA O SINAL DE PEDESTRE
      temPedestre = true;
    }
    //DELAYS PARCIAIS PARA CADA INTERAÇÃO
    delay(delayParcial);
  }
}

void atravessarPedestre(){
  //DEIXA APENAS O LED VERMELHO DO SEMÁFORO 1 ACESO
  digitalWrite(LED_VERMELHO1, HIGH);
  digitalWrite(LED_AMARELO1, LOW);
  digitalWrite(LED_VERDE1, LOW);
  
  //DEIXA APENAS O LED VERMELHO DO SEMÁFORO 2 ACESO
  digitalWrite(LED_VERMELHO2, HIGH);
  digitalWrite(LED_AMARELO2, LOW);
  digitalWrite(LED_VERDE2, LOW);
  
  //TEMPO PARA ATRAVESSAR
  delay(10000);
  
  //ATUALIZA ESTADO DO PEDESTRE
  temPedestre = false;
}