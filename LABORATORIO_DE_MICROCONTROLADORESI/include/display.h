
#define RS RE0
#define E RE1
#define DADO PORTC

void tempo(void) {
  E = 1;
  delay_ms(5);
  E = 0;
}
void inicializa(void) {
  E = 0;
  RS = 0;
  DADO = 0x38;
  tempo();
  DADO = 0x38;
  tempo();
  DADO = 0x06;
  tempo();
  DADO = 0x0C;
  tempo();
  DADO = 0x01;
  tempo();
  RS = 1;
}
void escreve(unsigned char posicao, char t[]) {
  unsigned char i = 0;
  RS = 0;
  DADO = posicao;
  tempo();
  RS = 1;
  while (t[i] != 0) {
    DADO = t[i];
    tempo();
    i++;
  }
}

void limpa() {
  RS = 0;
  DADO = 0x01;
  tempo();
  RS = 1;
}