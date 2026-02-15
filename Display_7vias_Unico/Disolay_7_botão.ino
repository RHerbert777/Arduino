#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define X 12 //virgula

#define BOTAO 10

void configurarPinos() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(X, OUTPUT);
  
  //CONFIGURADO COMO RESISTOR INTERNO
  pinMode(BOTAO, INPUT_PULLUP);

}

void Clear(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void Number_1(){
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void Number_2(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
}

void Number_3(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

void Number_4(){
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void Number_5(){
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
}

void Number_6(){
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
}

void Number_7(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void Number_8(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void Number_9(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void Number_0(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
}

void AtualizarDisplay(uint8_t acm){
  Clear();
  
  switch(acm){
  case 0: Number_0(); break;
  case 1: Number_1(); break;
  case 2: Number_2(); break;
  case 3: Number_3(); break;
  case 4: Number_4(); break;
  case 5: Number_5(); break;
  case 6: Number_6(); break;
  case 7: Number_7(); break;
  case 8: Number_8(); break;
  case 9: Number_9(); break;
  }
}

//Setup
void setup() {
  configurarPinos();
  AtualizarDisplay(0);

}



//Inicialização
uint8_t acm = 0; //variavel de 8 Bytes
void loop() {

 if (digitalRead(BOTAO) == LOW) {
    acm ++;
    
    // Soma 1 e tira o "resto de 10" imediatamente
    acm = (acm + 1) % 10;

    AtualizarDisplay(acm);

    delay(150); // Evita ruído elétrico

    while(digitalRead(BOTAO) == LOW) {
     // Fica preso aqui enquanto o dedo estiver no botão
    }
    //Se remover while e delay você cria uma roleta russa pois enquanto o dedo
    //estiver presionado vai ficar girando numeros 800 vezes por segundo aproximadamente
  }
}