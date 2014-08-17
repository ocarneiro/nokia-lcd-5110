//Olho de LCD - v1
//Controlador de Display LCD Nokia 5110 (84x48 pixels)
//em 31 de janeiro de 2014
//Mais informacoes: umcarneiro.blogspot.com
//Licenca: MIT (use como quiser!)

//Pinos utilizados no arduino
#define PIN_SCE   7  //pino 2 do display
#define PIN_RESET 6  //pino 1 do display
#define PIN_DC    5  //pino 3 do display
#define PIN_SDIN  4  //pino 4 do display
#define PIN_SCLK  3  //pino 5 do display

//Tamanho do LCD em pixels:
#define LCD_X     84
#define LCD_Y     48

byte linhaUm[84] = {
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //5
      0b00000000,
      0b00000001,
      0b00000010,
      0b00000100,
      0b00000100,  //10
      0b00001000,
      0b00001000,
      0b00010000,
      0b00100000,
      0b00100000,  //15
      0b00100000,
      0b01000000,
      0b01000000,
      0b01000000,
      0b01000000,  //20
      0b01000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //25
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //30
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //35
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //40
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //45
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //50
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //55
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,  //60
      0b10000000,
      0b10000000,
      0b10000000,
      0b10000000,
      0b01000000,  //65
      0b01000000,
      0b00100000,
      0b00100000,
      0b00010000,
      0b00010000,  //70
      0b00001000,
      0b00001000,
      0b00000100,
      0b00000010,
      0b00000010,  //75
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //80
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000
};

byte linhaDois[84] = {
      0b00000000,
      0b00000011,
      0b00001100,
      0b00110000,
      0b01000000,  //5
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //10
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //15
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //20
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //25
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //30
      0b00000000,
      0b00000000,
      0b00000001,
      0b00000011,
      0b00000111,  //35
      0b00000111,
      0b00001111,
      0b00001111,
      0b00001110,
      0b00011110,  //40
      0b00011111,
      0b00011111,
      0b00011111,
      0b00011111,
      0b00011111,  //45
      0b00011111,
      0b00011111,
      0b00011111,
      0b00011111,
      0b00011111,  //50
      0b00011111,
      0b00011111,
      0b00011111,
      0b00011111,
      0b00011111,  //55
      0b00011111,
      0b00011111,
      0b00011111,
      0b00001111,
      0b00001111,  //60
      0b00001111,
      0b00001111,
      0b00001111,
      0b00001111,
      0b00000111,  //65
      0b00000111,
      0b00000011,
      0b00000001,
      0b00000000,
      0b00000000,  //70
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //75
      0b00000000,
      0b10000000,
      0b01000000,
      0b00100000,
      0b00010000,  //80
      0b00001000,
      0b00000110,
      0b00000001,
      0b00000000
};

byte linhaTres[84] = {
      0b11111111,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //5
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //10
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //15
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //20
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //25
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00001111,  //30
      0b00111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //35
      0b10001111,
      0b00000111,
      0b00000111,
      0b00000011,
      0b00000011,  //40
      0b00000011,
      0b00000111,
      0b00001111,
      0b11111111,
      0b11111111,  //45
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //50
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //55
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //60
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //65
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b00111111,  //70
      0b00001111,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //75
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //80
      0b00000000,
      0b00000000,
      0b10000000,
      0b01111111
};

byte linhaQuatro[84] = {
      0b11111000,
      0b00000110,
      0b00000001,
      0b00000000,
      0b00000000,  //5
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //10
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //15
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //20
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //25
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b11100000,  //30
      0b11111000,
      0b11111100,
      0b11111111,
      0b11111111,
      0b11111111,  //35
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //40
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //45
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //50
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //55
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,  //60
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111001,
      0b11111001,  //65
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111111,
      0b11111110,  //70
      0111111000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //75
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //80
      0b00000000,
      0b00000000,
      0b00001111,
      0b11110000
};

byte linhaCinco[84] = {
      0b00000000,
      0b00000000,
      0b00000000,
      0b11000000,
      0b00110000,  //5
      0b00001100,
      0b00000010,
      0b00000001,
      0b00000000,
      0b00000000,  //10
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //15
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //20
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //25
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //30
      0b00000000,
      0b00000000,
      0b00000000,
      0b10000000,
      0b11000000,  //35
      0b11000000,
      0b11100000,
      0b11100000,
      0b11110000,
      0b11110000,  //40
      0b11110000,
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,  //45
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,  //50
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,  //55
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,
      0b11111000,  //60
      0b11110000,
      0b11110000,
      0b11110000,
      0b11110000,
      0b11100000,  //65
      0b11100000,
      0b11000000,
      0b11000000,
      0b10000000,
      0b00000000,  //70      
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //75
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000011,
      0b00000100,  //80
      0b00011000,
      0b01100000,
      0b10000000,
      0b00000000
};

byte linhaSeis[84] = {
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,  //5
      0b00000000,
      0b00000000,
      0b00000000,
      0b10000000,
      0b01000000,  //10
      0b00100000,
      0b00010000,
      0b00010000,
      0b00001000,
      0b00001000,  //15
      0b00001000,
      0b00000100,
      0b00000100,
      0b00000100,
      0b00000010,  //20
      0b00000010,
      0b00000010,
      0b00000010,
      0b00000010,
      0b00000001,  //25
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //30
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //35
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //40
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //45
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //50
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //55
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000001,  //60
      0b00000001,
      0b00000001,
      0b00000001,
      0b00000010,
      0b00000010,  //65
      0b00000010,
      0b00000010,
      0b00000010,
      0b00000010,
      0b00000100,  //70
      0b00000100,
      0b00000100,
      0b00001000,
      0b00010000,
      0b00100000,  //75
      0b00100000,
      0b01000000,
      0b10000000,
      0b00000000,
      0b00000000,  //80
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000
};

void setup(void)
{
  pinMode(PIN_SCE, OUTPUT);   // Inicializa os pinos...
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_DC, OUTPUT);
  pinMode(PIN_SDIN, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);
  digitalWrite(PIN_RESET, LOW); //RESET no controlador
  digitalWrite(PIN_RESET, HIGH);
  LcdWrite(LOW, 0x21 );  // Function set: PD=0 (On); V=0 (Horizontal); H=1 (Extended instruction set)
  LcdWrite(LOW, 0xBA );  // Define o LCD Vop (Contraste). //XXXXXXXXXXXXXXX
  LcdWrite(LOW, 0x04 );  // Define o coeficiente de temperatura (??)
  LcdWrite(LOW, 0x14 );  // LCD bias mode 1:48  (??)
  LcdWrite(LOW, 0x20 );  // Function set: PD=0 (On); V=0 (Horizontal); H=0 (Basic instruction set)
  LcdWrite(LOW, 0x0C );  // Display control = 10 (Normal)
  
  limpaTela();
  
  desenhaLinha(linhaSeis);
  desenhaLinha(linhaCinco);
  desenhaLinha(linhaQuatro);
  desenhaLinha(linhaTres);
  desenhaLinha(linhaDois);
  desenhaLinha(linhaUm);   
}
  
void limpaTela(void) {
  //Percorre todas as posicoes
  for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
  {
    LcdWrite(HIGH, 0);
  }
}

void desenhaLinha(byte linha[]) {
  //Percorre as colunas
  for (int coluna = 0; coluna < LCD_X; coluna++)
  {
    LcdWrite(HIGH, linha[coluna]);
  }
}


//Cuida da burocracia: envia o comando ou dado seguindo o protocolo do chip
void LcdWrite(byte dc, byte data)
{
  digitalWrite(PIN_DC, dc); //define se vai mandar dado ou comando
  digitalWrite(PIN_SCE, LOW); //ativa o chip para receber dados
  shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data); //envia um bit de cada vez, comecando pela esquerda
  digitalWrite(PIN_SCE, HIGH); //desativa o envio de dados
}

void loop(void)
{  
  //nada
}
