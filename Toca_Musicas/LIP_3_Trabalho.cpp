// C++ code
//

#include <IRremote.hpp>
/*
4278238976 = ON_OFF
4261527296 = VOL_PLUS
4127833856 = VOL_MINUS
4244815616 = FUNC/STOP
4060987136 = EQ
4044275456 = ST/REPT
4211392256 = |<< : BACK
4194680576 = >|| : PLAY_STOP
4177968896 = >>| : AVANCE
4144545536 = \/  : DOWN
4111122176 = /\  : UP
4077698816 = 0
4010852096 = 1
3994140416 = 2
3977428736 = 3
3944005376 = 4
3927293696 = 5
3910582016 = 6
3877158656 = 7
3860446976 = 8
3843735296 = 9
*/

// Constante para o led de deteccao
const int R_LED = 3;

// constante para o piezo
const int BUZZER = 5;

// Constante para infravermelho
const int rcvPin=4;
IRrecv irrecv(rcvPin);
decode_results results;

// Notas musicais
const int NOTA_DO = 262;	// Dó
const int NOTA_RE = 294;	// Ré
const int NOTA_MI = 330;	// Mi
const int NOTA_FA = 349;	// Fá
const int NOTA_SOL = 392;	// Sol
const int NOTA_LA = 440;	// La
const int NOTA_SI = 495;	// Si

// Constantes Extras
const int FIRST_SONG_SIZE = 14;
const int SECOND_SONG_SIZE = 1;
const int THIRD_SONG_SIZE = 1;
const int DELAY_TIME = 400;

// Variaveis Extras
int song_number = 0;
int tick = 0;
int currentTick = 0;

// Musica 1:
const int SONG_ONE[14] = {392, 392, 349, 330, 392, 392, 349, 330, 392, 440, 392, 349, 330, 294};

// Musica 2:
const int SONG_TWO[] = {};
  
// Musica 3:
const int SONG_THIRD[] = {};



// Exemplo analogWrite(BUZZER, vol*2.55);


// Funcao reset

// Funcao passa musica

// Funcao Aumeta Volume

// Funcao Abaixa Volume

bool song_run = false;

void musicFalse()
{
  song_run = false;
}

void musicTrue ()
{
}

void playMusic()
{
  if (song_number = 0) {
    songOne();
  }
  else if (song_number = 1) {
    songTwo();
  }
  else if (song_number = 1) {
    songThree();
  }
}

void songOne ()
{
  int i;
  for (i = 0; i <= currentTick; i++) {
    tone(BUZZER, SONG_ONE[currentTick], DELAY_TIME/2);
  }
  if (i >= currentTick) {
    song_run = false;
    currentTick = 0;
    return;
  }
  else {
    return;
  }
}

void songTwo ()
{
}

void songThree ()
{
}

void setup()
{ 
  Serial.begin(9600);
   irrecv.enableIRIn(); // Inicia o receptor
    
  pinMode(R_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() 
{
  if (song_run == false) {
    
    if(IrReceiver.decode()) {
      auto value = IrReceiver.decodedIRData.decodedRawData; 	
      //switch(results.value)
       	switch(value)
        { 
          case 4278238976: // ON_OFF
          	playMusic();
          	break;

          case 4194680576: // PLAY_STOP
          	musicTrue();
          	break;
          
          case 4177968896: // AVANCE
          	songOne();
          	break;
          
          case 4211392256: // BACK
          	break;

          default: Serial.println(value);     
        }  
      IrReceiver.resume(); // Recebe proximo valor
    }
  }
}
