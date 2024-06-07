// C++ code
//

/*
    G = Green: Verde
    R = Red: Vermelho
    Y = Yellow: Amarelo
    B = Blue: Azul
*/
// definicao de constantes para butoes
const int G_BUTTON = 1;
const int R_BUTTON = 2;
const int Y_BUTTON = 3;
const int B_BUTTON = 4;

// definicao de constantes para os leds
const int G_LED = 6;
const int R_LED = 7;
const int Y_LED = 8;
const int B_LED = 9;

// definicao de constantes extras
const int START = 5;
const int BUZZER = 10;
const int SIZE_GAME = 10;
const int DELAY_TIME = 400;

// DO'b, RE, MI, FA, SOL, DO, MI#
const int FREQUENCES[6] = {262, 294, 330, 349, 132, 392};

int currentTurn = 0;
int maxGame[SIZE_GAME]; 

bool game_run = false;


void callSound(int position) {
  tone(BUZZER, FREQUENCES[position-1], DELAY_TIME);
  delay(DELAY_TIME);
  noTone(BUZZER);
}

void showLeds() {
  for (int i = 0; i <= currentTurn; i++){
    digitalWrite(maxGame[i]+5, HIGH);
    callSound(maxGame[i]);
    digitalWrite(maxGame[i]+5, LOW);
    delay(DELAY_TIME/2);
  }
}

bool verifySequence() {
  bool buttonClick = false;
  
  for (int i = 0; i <= currentTurn; i++) {
    buttonClick = false;
    
    while (!buttonClick) {
      for (int j = 1; j <= 4; j++) {
        while (digitalRead(j) == HIGH) {
          digitalWrite(j+5, HIGH);
          callSound(j);
          digitalWrite(j+5, LOW);
          if (j == maxGame[i]) {
            buttonClick = true;
          }
          else {
            return false;
          }
        }
      }
    }
  }
  
  return true;
}

void error() {
  delay(DELAY_TIME/4);
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(i+6, HIGH);
  }
  callSound(5);
  delay(DELAY_TIME/4);
  for (int j = 0; j < 4; j++)
  {
    digitalWrite(j+6, LOW);
  }
}

void setup()
{
  
  pinMode(G_BUTTON, INPUT);
  pinMode(R_BUTTON, INPUT);
  pinMode(Y_BUTTON, INPUT);
  pinMode(B_BUTTON, INPUT);
  
  pinMode(G_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  
  pinMode(START, INPUT);
  pinMode(BUZZER, OUTPUT);
  
}

void loop()
{ 
  // espera do botao de inicio
  if (digitalRead(START) == HIGH){
    game_run = true;
    currentTurn = 0;
    
    // definicao de sequencia aleatoria para jogo
    randomSeed(millis());
    for (int i = 0; i < SIZE_GAME; i++) {
      maxGame[i] = random(1,5);
    }
  }
  else if (!game_run) {
  	return;
  }
  
  // mostrar a sequencia de led's
  delay(DELAY_TIME*2);
  showLeds();
  delay(DELAY_TIME);
  
  // confirmar sequencia de led's
  bool acertou = verifySequence();
  if (acertou == false) {
    error();
    game_run = false;
    return;
  }
  
  // fim do jogo
  currentTurn++;
  if (currentTurn >= SIZE_GAME) {
    for (int j = 0; j < 3; j++) {
      callSound(6);
      delay(DELAY_TIME/4);
    }
    game_run = false;
    currentTurn = 0;
  }
}
